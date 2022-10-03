#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7
int FSRSensor = A0;

SoftwareSerial bluetooth(BT_RXD,BT_TXD); 

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {

  int SensorReading = analogRead(FSRSensor); 
  int mfsr = map(SensorReading, 0, 1024, 0, 255);

  if (mfsr > 40){
    bluetooth.println(mfsr); // FSR 센서 내용을 블루투스측에 write
    bluetooth.println("헬멧을 착용 했습니다"); 
    Serial.println(mfsr);
    Serial.println("헬멧을 착용 했습니다");
    while(1);

  }
}
 
