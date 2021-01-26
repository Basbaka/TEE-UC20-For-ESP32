#include "esp32_TEE_UC20.h"
#include "esp32_gnss.h"

GNSS gps;

void debug(String data)
{
  Serial.println(data);
}
void data_out(char data)
{
  Serial.write(data);
}
void setup() 
{
  Serial.begin(115200);
  gsm.begin(&Serial2,115200);
  gsm.Event_debug = debug;
  Serial.println(F("UC20"));
  gsm.PowerOn(); 
  while(gsm.WaitReady()){}
  Serial.print(F("GetOperator --> "));
  Serial.println(gsm.GetOperator());
  Serial.print(F("SignalQuality --> "));
  Serial.println(gsm.SignalQuality());
  Serial.println(F("Start GPS"));
  gps.Start();
  Serial.println(F("Enable NMEA"));
  gps.EnableNMEA();
}
void loop() 
{
  Serial.println(gps.GetNMEA("GGA"));
  delay(500);  
}
