//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>



#ifndef STASSID
#define STASSID  "Sweet Home"
#define STAPWD  "arun5767"
#endif

const char *ssid = STASSID;
const char *password = STAPWD;

ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  delay(1000);  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("____ Warm up______");
  Serial.print("Relay Status : ");
  pinMode (D8,INPUT);
  bool relayStatus = digitalRead(D8);
  relayStatus ?  Serial.println( " On ") : Serial.println( " Off " );

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("Warming up WiFi Station Mode .");

  while( WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(" trying to connect.");
  }

  Serial.println("");
  Serial.print("Connected to Access point : ");
  Serial.println( ssid );
  Serial.print("Device IP Address : ");
  Serial.println(WiFi.localIP());
  if(MDNS.begin("srs")){
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/", handleRoot);
  server.on("/status", handleDeviceStatus);
  server.on("/relayStatus", handleRelayStatus);
  server.on("/relayToggle", handleRelayToggle);
  server.on("/relayOn", handleRelayOn);
  server.on("/relayOff", handleRelayOff);
  server.begin();
  Serial.println(" Shining the LED to mark Warm up Complete "); 
  digitalWrite(LED_BUILTIN, HIGH);
  
}

String responseHTML(String msg ){
  
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  String hTML = "<html><head><title>Single Relay Server Demo</title><style>body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style></head><body>";
  hTML += "<h1> " + msg + " </h1>";
  hTML += "<p>Uptime: " ;
  hTML += hr ;
  hTML += ":" ; 
  hTML += min % 60; 
  hTML += ":" ;
  hTML += sec % 60; 
  hTML += "</p></body></html>";
  return hTML;
}

void handleRelayToggle(){

  pinMode (D8,OUTPUT);

  
  server.send(200, "text/html", responseHTML("To handle Relay Toggle"));
  
}

void handleRelayOn(){
  pinMode (D8,OUTPUT);
  Serial.println("Writing HIGH on pin D8");
  digitalWrite(D8, HIGH);
  server.send( 200, "text/html", responseHTML("Writing HIGH on pin D8 : Success, you should see the relay ON"));
}

void handleRelayOff(){
  pinMode (D8,OUTPUT);
  Serial.println("Writing LOW on pin D8");
  digitalWrite(D8, LOW);
  server.send( 200, "text/html", responseHTML("Writing LOW on pin D8 : Success, you should see the relay OFF"));
}

void handleRelayStatus()
{
  
  //pinMode (D8,INPUT);
  bool relayStatus = digitalRead(D8);
  Serial.print( "relayStatus : ");
  Serial.println( relayStatus);
  String msg = "Relay control is on D8 and is " ;
  if (relayStatus == 1){
    msg += " On ";
  }
  else
  {
    msg += " Off ";
  }
  server.send(200, "text/html", responseHTML(msg));
  
}

void handleDeviceStatus(){
  
  String msg = "Wifi Connected as Station mode on : "; 
  msg += ssid;
  msg += " and its IP address is : "; 
  msg += WiFi.localIP().toString(); 
  msg += ". Relay control is on D8";
  server.send(200, "text/html", responseHTML(msg));
  
}
  
void handleRoot(){
  
  server.send(200, "text/html", responseHTML("Hello from SRS - Single Relay Server"));
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  server.handleClient();
}
