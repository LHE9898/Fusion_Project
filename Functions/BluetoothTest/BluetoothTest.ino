#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7

SoftwareSerial bluetooth(BT_RXD,BT_TXD); 

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {

  if(Serial.available()){
    bluetooth.write(Serial.read())  // 시리얼 모니터 내용을 블루투스측에 write
  }
  
  if(bluetooth.available()){
    Serial.write(bluetooth.read())  // 블루투스 내용을 시리얼측에 write
  }

}

 
