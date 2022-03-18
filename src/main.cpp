#include <Arduino.h>
#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Allure M1";   // your network SSID (name) 
const char* password = "isetbeja";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 1669058;
const char * myWriteAPIKey = "F18ZYOXVIMEDN2LL";

unsigned long timerDelay = 15000;

// La fonction d'initialisation, exécutée une seule fois
void setup(){
  Serial.begin(9600);         // Initialiser la fréquence de communication avec la carte
  
  WiFi.mode(WIFI_STA);        // Connecter au réseau WIFI
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);
    } 
    Serial.println("\nConnected.");
  }

  ThingSpeak.begin(client);   // Initialize ThingSpeak
}

// La fonction du programme principal, exécutée en boucle
void loop(){
  ThingSpeak.setField(1, 2);
  ThingSpeak.setField(2, 2);
  ThingSpeak.setField(3, 3);
  ThingSpeak.setField(4, 4);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(timerDelay);
}