#include "esp32_TEE_UC20.h"
#include "esp32_internet.h"
#include "esp32_File.h"
#include "esp32_ftp.h"

//SIM TRUE  internet
#define APN "internet"
#define USER "True"
#define PASS "true"

#define USERNAME  "Your username"
#define PASSWORD  "Your passwore"
#define HOST      "Your host name"
#define PORT      21
#define PATH      "/"


INTERNET net;
UC_FILE file;
FTP ftp;

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
  
  ftp.begin(1);
  Serial.println(F("Set FTP Username and Password"));
  ftp.SetUsernamePassword(USERNAME,PASSWORD);
  Serial.println(F("Set File Type = Binary"));
  ftp.SetFileType(BINARY);
  Serial.println(F("Set FTP = Passive Mode"));
  ftp.SetTransMode(PASSIVE);
  Serial.println(F("Set Timeout"));
  ftp.SetTimeout(90);  
// Serial.println(F("Enable SSL"));
// Serial.println(ftp.SSLEnable());
  Serial.print(F("Login Server"));
  Serial.println(ftp.LoginServer(HOST,PORT));
  Serial.println(F("Set Path"));
  Serial.println(ftp.SetPath(PATH));
  Serial.println(F("List File in Server"));
  ftp.ListOutput = debug;
  ftp.List(".");
  Serial.println(F("Logout"));
  Serial.println(ftp.Logout());
  Serial.println(F("Disconnect net"));
  net.DisConnect();
 
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
