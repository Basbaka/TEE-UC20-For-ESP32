#include "esp32_TEE_UC20.h"
#include "esp32_call.h"
#include "esp32_sms.h"
#include "esp32_internet.h"
#include "esp32_File.h"
#include "esp32_http.h"

INTERNET net;
UC_FILE file;
HTTP http;

//SIM TRUE  internet
#define APN "internet"
#define USER "True"
#define PASS "true"

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
 
  Serial.println(F("Disconnect net"));
  net.DisConnect();
  Serial.println(F("Set APN and Password"));
  net.Configure(APN,USER,PASS);
  Serial.println(F("Connect net"));
  net.Connect();
  Serial.println(F("Show My IP"));
  Serial.println(net.GetIP());
  Serial.println(F("Start HTTP"));
  http.begin(1); 
  Serial.println(F("Send HTTP POST"));
  http.url("https://postman-echo.com/post");
  Serial.println(http.post("foo1=bar1&foo2=bar2")); // Body Raw Data
  Serial.println(F("Clear data in RAM"));
  file.Delete(RAM,"*");
  Serial.println(F("Save HTTP Response To RAM"));
  http.SaveResponseToMemory(RAM,"web.hml");
  Serial.println(F("Read data in RAM"));
  read_file(RAM,"web.hml");
  Serial.println(F("Disconnect net"));
  net.DisConnect();
  
}
void read_file(String pattern,String file_name)
{
  file.DataOutput =  data_out;
  file.ReadFile(pattern,file_name);
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
