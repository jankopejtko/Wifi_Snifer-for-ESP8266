#include "ESP8266WiFi.h"
int counter = 0;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}
void printEncryption(int i)
{
    switch(WiFi.encryptionType(i))
    {
      case 2:
        Serial.print("WPA");
        break;
      case 5:
        Serial.print("WEP");
        break;
      case 4:
        Serial.print("CCMP (WPA)");
        break;
      case 7:
        Serial.print("WIFI UNLOCKED");
        break;
      case 8:
        Serial.print("AUTO");
        break;
    }
}
void loop()
{
  Serial.print("Record num: ");
  Serial.println(counter);
  Serial.println("--------------------------");
  Serial.print("Scaning...  ");
  int wifi_found = WiFi.scanNetworks();
  Serial.print(wifi_found);
  Serial.println(" network(s) found:"); 
  
  for (int i = 0; i < wifi_found; i++)
  {
    Serial.println();
    Serial.print(i); Serial.print(".) ");
    Serial.print("Name: "); Serial.print(WiFi.SSID(i));
    Serial.println();
    Serial.print("    RSSI: "); Serial.print(WiFi.RSSI(i));  Serial.print(" dB");
    Serial.println();
    Serial.print("    Channel: "); Serial.print(WiFi.channel(i));
    Serial.println();
    Serial.print("    Encryption: "); printEncryption(i);
    Serial.println();
  }
  Serial.println();
  counter = counter + 1;
  Serial.println();
  Serial.println();
  delay(5000);
}
