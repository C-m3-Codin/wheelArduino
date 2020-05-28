#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>

#ifndef STASSID
#define STASSID "dancing on broken glass"
#define STAPSK  "PayCyril21"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const int led = 13;


void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  server.on("/", getInst);

  server.begin();
  Serial.println("HTTP server started");
}


void getInst(){

  Serial.print("received post");

  String data= server.arg("plain");
  StaticJsonBuffer<200> jbuffer;
    JsonObject& obj=jbuffer.parseObject(data);
  
   String dir = obj["dir"];
//   up = obj["down"];
//       up = obj["left"];
//      up = obj["right"];
//3String     asd[4]={"up","down","right","left"};
    Serial.println("\n\n\n\n");
    Serial.println(dir);
//    Serial.println(asd[up.toInt()]);
    
  }





  
void loop(void) {
  server.handleClient();
 // MDNS.update();
}
