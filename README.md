3G HAT Expansion for Raspberry Pi (UC20-G) with ESPino32 
Libraly and Example code Quectel UC20 3G  for ESP32 Board.

Doucument
- 3G_Shield_User_Manual(TH) (https://github.com/ThaiEasyElec/TEE_UC20_Shield/blob/master/3G%20Shield%20manual/ETEE059_3G_Shield_User_Manual_TH_20160321.pdf)
- Development_Guide_for_3G_Shield(TH) (https://github.com/ThaiEasyElec/TEE_UC20_Shield/blob/master/3G%20Shield%20manual/Development_Guide_for_3G_Shield_and_3G_Module_using_Arduino_TH_20160726.pdf)


ESPino32 With 3G HAT connection via HardwareSerial(Serial2 defaulf 115200bps) 


![image](https://user-images.githubusercontent.com/33049022/105818151-1fc5af80-5fe9-11eb-9f62-19f5381bced5.png)



- ให้ทำการกดเปิดโมดูลโดยการกดปุ่ม PWRKEY ค้างไว้ประมาณ 1-2 วินาที เมื่อโมดูลเปิดจะมี LED สีเหลืองติดขึ้นมา 


1. ให้ติดตั้ง Library https://github.com/Basbaka/TEE-UC20-For-ESP32


2. รันโปรแกรม ATCommand_serial เพื่อใช้งานโหมด AT command โดยไปที่เมนู File >> Examples >> TEE-UC20-For-ESP32 >> ATCommand_serial 


3. เปิด Serial monitor โดยไปที่แถบเมนู Tools >> Serial monitor โดยตั้ง baudrate บน Serial monitor เป็น 115200 bps และเลือกเป็น Both NL & CR  จากนั้นพิมพ์คำสั่ง AT กด Enter จากนั้นตัวโมดูลจะตอบกลับมาว่า OK ซึ่งหมายถึงบอร์ด ESPino32 สามารถติดต่อกับตัวโมดูลได้


![image](https://user-images.githubusercontent.com/8803501/105676107-a2346d80-5f1c-11eb-9255-8db14a6242cb.png)



5. ทำการตั้งค่า URC Port ให้ออกทาง UART โดยใชคำสั่ง AT+QURCCFG="urcport","uart1" จากนั้นตัวโมดูลจะตอบกลับมาว่า OK ซึ่งหมายถึงได้ทำการเปลี่ยนให้ URC Port ออกทาง UART แล้ว

![image](https://user-images.githubusercontent.com/8803501/105678007-356ea280-5f1f-11eb-81a1-211707cd2b70.png)


6. ทำการทดสอบโดยรันโปรแกรม NTP ไปที่ เมนู File >> Examples >> TEE-UC20-For-ESP32 >> TCP >> NTP จากนั้นทำการอัพโหลด และติดตามผลการเชื่อมต่อ NTP server เป็นอันเรียบร้อย 

![image](https://user-images.githubusercontent.com/8803501/105677213-29ceac00-5f1e-11eb-93da-9d94ae7a927d.png)
