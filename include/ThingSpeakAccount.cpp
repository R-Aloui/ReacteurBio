#include "ThingSpeakAccount.hpp"
#include "ThingSpeak.h"


ThingSpeakAccount::ThingSpeakAccount() {}
ThingSpeakAccount::ThingSpeakAccount(string pssid, string ppassword,
                                     unsigned long pmyChannelNumber, string pmyWriteAPIKey)
{
  ssid = pssid;
  password = ppassword;
  myChannelNumber = pmyChannelNumber;
  myWriteAPIKey = pmyWriteAPIKey;
}
void ThingSpeakAccount::init(wifi_mode_t mode)
{
  WiFi.mode(mode); // Connecter au réseau WIFI
  // Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect");
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid.c_str(), password.c_str());
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  ThingSpeak.begin(client); // Initialize ThingSpeak
}
void ThingSpeakAccount::setField(unsigned int field, float value)
{
  int res = ThingSpeak.setField(field, value);
  if (res != 200)
  {
    Serial.printf("Echec de la mise a jour de l attribut %d, le code est %d.\n",
                  field, res);
  }
  else
  {
    Serial.printf("Mise a jour de l attribut %d reussite, le code est %d.\n",
                  field, res);
  }
}
void ThingSpeakAccount::writeFields()
{
  int res = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey.c_str());
  if (res != 200)
  {
    Serial.printf("Echec de la mise a jour du ThingSpeak, le code est %d.\n", res);
  }
  else
  {
    Serial.printf("Mise a jour du ThingSpeak, le code est %d.\n", res);
  }
}