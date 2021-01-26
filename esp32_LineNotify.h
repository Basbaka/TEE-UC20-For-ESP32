#ifndef LINE_NOTIFY_h
#define LINE_NOTIFY_h

#include "esp32_TEE_UC20.h"
#include "esp32_ssl.h"

#define CONTEX 1
#define CLI_ID 4

class LINE_NOTIFY
{
public:
	LINE_NOTIFY();
	bool begin(String auth);
	int  connect();
	bool close();
	bool sendMessage(String message);
	void send_http(String http_type,String data);
	
	
private:
	String Authen;
	
	
	
};




#endif
