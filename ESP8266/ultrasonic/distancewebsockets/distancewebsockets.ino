#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>

// DEFAULT variables *********************************************************
const char* ssid="Sweet Home";             // yourSSID
const char* password="arun5767";     // yourPASSWORD
#define TRIGGER 2 //D4
#define ECHO    0 //D3
long duration;
int distance;
int websockMillis=1000;                    // SocketVariables are sent to client every 50 milliseconds
String webSite, javaScript,JSONtxt;
String distanceValue;
// END ***********************************************************************

ESP8266WebServer server(80);
WebSocketsServer webSocket=WebSocketsServer(88);

unsigned long websockCount=0UL,wait000=0UL,wait001=0UL;



void buildWebsite(){
  buildJavascript();
  webSite="<!DOCTYPE HTML><HTML>\n";
  webSite+="<META name='viewport' content='width=device-width, initial-scale=1'>\n";
  webSite+=javaScript;
  webSite+="<BODY>\n";
  webSite+="<BR><B>This is the ESP website ...</B><BR><BR>\n";
  webSite+="Runtime = <A ID='runtime'></A><BR>\n";
  webSite+="websockCount = <A ID='websockCount'></A><BR><BR>\n";
  webSite+="<TABLE BORDER=1 WIDTH=200px BGCOLOR='cornsilk' STYLE='border-collapse:collapse;text-align:center'>\n"; 
  webSite+="<TR><TD> Websocket response for Distance measurement from the sensor </TD></TR>";
  webSite+="<TR><TD> <textarea id=distance  cols=40 rows=20></textarea></TD></TR>";
  webSite+="</TABLE>\n"; 
  webSite+="</BODY>\n";
  webSite+="</HTML>\n";
}

void buildJavascript(){
  javaScript="<SCRIPT>\n";
  javaScript+="InitWebSocket();\n";
  javaScript+="function InitWebSocket(){\n";
  javaScript+="  websock=new WebSocket('ws://'+window.location.hostname+':88/');\n";
  javaScript+="  websock.onmessage=function(evt){\n";
  javaScript+="    JSONobj=JSON.parse(evt.data);\n";
  javaScript+="    document.getElementById('distance').innerHTML+=JSONobj.distance + String.fromCharCode(13, 10) ;\n"; 
  javaScript+="  }\n";
  javaScript+="}\n";
  javaScript+="</SCRIPT>\n";
}

String millis2time(){
  String Time="";
  unsigned long ss;
  byte mm,hh;
  ss=millis()/1000;
  hh=ss/3600;
  mm=(ss-hh*3600)/60;
  ss=(ss-hh*3600)-mm*60;
  if(hh<10)Time+="0";
  Time+=(String)hh+":";
  if(mm<10)Time+="0";
  Time+=(String)mm+":";
  if(ss<10)Time+="0";
  Time+=(String)ss;
  return Time;
}

void handleWebsite(){
  buildWebsite();

  server.send(200,"text/html",webSite);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t wslength){
  
}

void setup() {
  delay(1);
  pinMode(TRIGGER, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)delay(500);
  WiFi.mode(WIFI_STA);
  Serial.println("\n\nBOOTING ESP8266 ...");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("Station IP address = ");
  Serial.println(WiFi.localIP());
  server.on("/",handleWebsite);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
  server.handleClient();
if(millis()>wait001){
  digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
Serial.println(distance);
distanceValue = (String) distance;
  
    websockCount++;
    JSONtxt="{\"runtime\":\""+millis2time()+"\","+              // JSON requires double quotes
             "\"distance\":\""+distanceValue+"\"}";
    webSocket.broadcastTXT(JSONtxt);
    wait001=millis()+websockMillis;
  }
}
