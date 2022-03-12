#include <Arduino.h>

// La fonction d'initialisation, exécutée une seule fois
void setup(){
  Serial.begin(9600);         // Initialiser la fréquence de communication avec la carte
  Serial.println("Bonjour");  // Afficher bonjour
}

// La fonction du programme principal, exécutée en boucle
void loop(){

}