#include "esp32_TEE_UC20.h"
#include "esp32_internet.h"
#include "esp32_tcp.h"

INTERNET net;
TCP tcp;

//SIM TRUE  internet
#define APN "internet"
#define USER ""
#define PASS ""

AltSoftSerial mySerial;

void debug(String data)
{
  Serial.println(data);
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
  
  Serial.println(F("Disconnect net"));
  net.DisConnect();
  Serial.println(F("Set APN and Password"));
  net.Configure(APN,USER,PASS);
  Serial.println(F("Connect net"));
  net.Connect();
  Serial.println(F("Show My IP"));
  Serial.println(net.GetIP());
  tcp.Ping(1,"www.google.co.th");  
}
void loop() 
{
   if (gsm.available())
  {
    Serial.write(gsm.read());
  } 
  if (Serial.available())
  {
    char c = Serial.read();
    gsm.write(c);
    
  }
}

