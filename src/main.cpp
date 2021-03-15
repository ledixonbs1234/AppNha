#include <Arduino.h>
#include <wifi_connect.h>
#include <update_firmware_github.h>
#include <ESP8266httpUpdate.h>
#include <WiFiClientSecure.h>
#include <CertStoreBearSSL.h>
#include <time.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

const String FirmwareVer = {"1.0"};
// #define URL_fw_Version "/programmer131/otaFiles/master/version.txt"
#define URL_fw_Version "/ledixonbs1234/otaesp8266/main/version.txt"
#define URL_fw_Bin "https://raw.githubusercontent.com/ledixonbs1234/otaesp8266/main/firmware.bin"
char *ssid = "Huong -2.4G";
char *password = "0348759205";

char auth[] = "bqE84StNq9oGMl961KtH_lgWSb8iNeeT";

BLYNK_WRITE(V1)
{
  Serial.println("Dang update");

  setClock();

  FirmwareUpdate(URL_fw_Bin, URL_fw_Version, FirmwareVer);
}


void setup()
{
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Start");

  Blynk.begin(auth, ssid, password);
  //connect_wifi(ssid,password);
  Serial.println("Dang chay version");
  Serial.println(FirmwareVer);

  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  Blynk.run();
}
