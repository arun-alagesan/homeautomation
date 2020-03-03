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
int switches[5] = { D1,D2,D3,D4,D8 };
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
  //server.on("/switches",handleSwitches);
  server.on("/testswitches", handleTestSwitches);
  server.on("/turnallon", turnOnAll);
  server.on("/turnalloff", turnOffAll);
  server.on("/1x1on", turn1by1on);
  server.on("/1x1off",turn1by1off);
  
  
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


int* readAllSwitchStatus()
{
  int switchValues[5] = {0,0,0,0,0};

  for (int i = 0; i< 5; i++)
    switchValues [i] = digitalRead (switches[i]);

  return switchValues;
  
}

void turn1by1on()
{
  for (int i = 0; i<5 ;i++){
    delay(1);
    pinMode(switches[i],OUTPUT);
    digitalWrite(switches[i], HIGH);
    delay(1000);
  }
 
  server.send( 200, "text/html", responseHTML("Writing  : All pins put to High Success, you should see the relay On"));
}
void turn1by1off()
{
  for (int i = 0; i<5 ;i++){
    delay(1);
    pinMode(switches[i],OUTPUT);
    digitalWrite(switches[i], LOW);
    delay(1000);
  }
 
  server.send( 200, "text/html", responseHTML("Writing  : All pins put to High Success, you should see the relay Off"));
}
void turnOnAll()
{
  delay(1);
  pinMode(D1,OUTPUT);
  digitalWrite(D1, HIGH);

  delay(1);
  pinMode(D2,OUTPUT);
  digitalWrite(D2, HIGH);

  delay(1);
  pinMode(D3,OUTPUT);
  digitalWrite(D3, HIGH);

  delay(1);
  pinMode(D4,OUTPUT);
  digitalWrite(D4,HIGH);
  
  delay(1);
  pinMode(D8,OUTPUT);
  digitalWrite(D8, HIGH);
  server.send( 200, "text/html", responseHTML("Writing  : All pins put to High Success, you should see the relay On"));
}
void turnOffAll()
{
  delay(1);
  pinMode(D1,OUTPUT);
  digitalWrite(D1,LOW);

  delay(1);
  pinMode(D2,OUTPUT);
  digitalWrite(D2, LOW);

  delay(1);
  pinMode(D3,OUTPUT);
  digitalWrite(D3, LOW);

  delay(1);
  pinMode(D4,OUTPUT);
  digitalWrite(D4, LOW);
  
  delay(1);
  pinMode(D8,OUTPUT);
  digitalWrite(D8, LOW);

  server.send( 200, "text/html", responseHTML("Writing  : All pins put to Low Success, you should see the relay Off"));
}



void handleTestSwitches()
{

  
  server.send( 200, "text/html", responseHTML("Test on all pins done : Success, you should see the relay ON"));
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
