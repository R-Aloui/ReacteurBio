#include <Arduino.h>
#include "ThingSpeakAccount.cpp"

ThingSpeakAccount tha("Allure M1", "isetbeja", 1669058, "F18ZYOXVIMEDN2LL");
// ThingSpeakAccount::Data d;
// La fonction d'initialisation, exécutée une seule fois
void setup(){
  Serial.begin(115200);         // Initialiser la fréquence de communication avec la carte
  
  tha.init();
}

// La fonction du programme principal, exécutée en boucle
void loop(){
  tha.setField(ThingSpeakAccount::P_SEN_1, 1);
  tha.setField(ThingSpeakAccount::P_SEN_2, 2);
  tha.setField(ThingSpeakAccount::P_SEN_3, 3);
  tha.setField(ThingSpeakAccount::P_SEN_4, 4);
  tha.writeFields();
  delay(15000);
}