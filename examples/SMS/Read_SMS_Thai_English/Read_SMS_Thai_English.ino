#include "esp32_TEE_UC20.h"
#include "esp32_call.h"
#include "esp32_sms.h"
CALL call;
SMS sms;

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
}

void loop() 
{
 
  if(gsm.event_input())
  {
    if(gsm.event_type == EVENT_RING)
    {
      Serial.println("Ring");
    }
    if(gsm.event_type == EVENT_SMS)
    {
      Serial.println("NEW SMS");
      Serial.print("index = ");
      int index = sms.IndexNewSMS();
      Serial.println(index);
      String str_sms =sms.ReadSMS(index);
      Serial.println(sms.ConvertStrUnicodeToTIS620(str_sms));
      sms.DeleteSMS(index);
    }
  }  
}
