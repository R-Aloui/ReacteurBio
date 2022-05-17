#pragma once
#include <WiFi.h>
#include <string>

using std::string;

class ThingSpeakAccount{
public:
  enum Data {
    P_SEN_1 = 1, P_SEN_2, P_SEN_3, P_SEN_4, 
    DATA5, DATA6, DATA7, DATA8
  };
  ThingSpeakAccount();
  ThingSpeakAccount(string pssid, string ppassword, 
    unsigned long pmyChannelNumber, string pmyWriteAPIKey);
  void init(wifi_mode_t mode = WIFI_STA);
  void setField(unsigned int field, float value);
  void writeFields();
private:
  string ssid = "Allure M1";       // network SSID
  string password = "isetbeja";    // network password
  unsigned long myChannelNumber = 1669058;
  string myWriteAPIKey = "F18ZYOXVIMEDN2LL";
  WiFiClient  client;
};