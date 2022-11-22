#define SSLeft 16
#define SSBack 15
#define SSRight 14
#define BZLeft 13
#define BZBack 12
#define BZRight 11

#define trig_pin_L  6   // 좌측 초음파센서
#define echo_pin_L  7   // 좌측 초음파센서
#define trig_pin_R  5   // 후방 초음파 센서
#define echo_pin_R  4   // 후방 초음파 센서
#define trig_pin_B  2  // 우측 초음파 센서
#define echo_pin_B  3  // 우측 초음파 센서
#define Limit_dis 50 // 지정된 거리 이하일때 반응, 단위 [cm] 
//HC-SR04 초음파 센서의 경우 최대 400cm의 거리 측정 가능

int Set_Sensors(){
  // setting SuperSonic Sensor 
  pinMode(trig_pin_L, OUTPUT);
  pinMode(echo_pin_L, INPUT);
  pinMode(trig_pin_R, OUTPUT);
  pinMode(echo_pin_R, INPUT);
  pinMode(trig_pin_B, OUTPUT);
  pinMode(echo_pin_B, INPUT);

  return 0;
}


double getSS_R(){
  double distance_R;
  long timeout = 400 * 10000L / 340 * 2;
  //초음파의 속도는 340m/s
  //최대 측정거리를 감안한 초음파 측정 함수를 만들어 
  //불필요한 대기시간을 제거하여 아두이노 구동지연현상 방지
  digitalWrite(trig_pin_R, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_R, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_R, LOW);

  double time_R = pulseIn(echo_pin_R, HIGH, timeout);
  distance_R = time_R * 340 / 10000 / 2;

  // distance_R = pulseIn(echo_pin_R, HIGH)/58.0;
  // if (distance_R > 500.0){
  //   distance_R = 500.0;
  // }

  return distance_R;
}

double getSS_L(){
  double distance_L;
  long timeout = 400 * 10000L / 340 * 2;
  digitalWrite(trig_pin_L, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_L, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_L, LOW);

  double time_L = pulseIn(echo_pin_L, HIGH, timeout);
  distance_L = time_L * 340 / 10000 / 2;
  // distance_L = pulseIn(echo_pin_L, HIGH)/58.0;
  // if (distance_L > 500){
  //   distance_L = 500;
  // }

  return distance_L;
}


double getSS_B(){
  double distance_B;
  long timeout = 400 * 10000L / 340 * 2;
  digitalWrite(trig_pin_B, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_B, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_B, LOW);

  double time_B = pulseIn(echo_pin_B, HIGH, timeout);
  distance_B = time_B * 340 / 10000 / 2;


  // distance_B = pulseIn(echo_pin_B, HIGH)/58.0;
  //   if (distance_B > 500){
  //   distance_B = 0;
  // }
  return distance_B;
}

int output_Buzzer(int index){// 왼 뒤 오
    switch (index){
        case BZLeft: 
          // tone(13, 1000, 1);      //13번핀으로 1,000Hz음을 10ms 동안 발생
          tone(13, 2000, 10);      //13번핀으로 1,000Hz음을 10ms 동안 발생
           delay(10);
          break;

        case BZBack:
          // tone(12, 1000, 1);      //12번핀으로 1,000Hz음을 10ms 동안 발생
          tone(12, 2000, 10);      //13번핀으로 1,000Hz음을 10ms 동안 발생
           delay(10);
          break;

        case BZRight:
          // tone(11, 1000, 1);      //11번핀으로 1,000Hz음을 10ms 동안 발생
          tone(11, 2000, 10);      //11번핀으로 1,000Hz음을 10ms 동안 발생
          delay(10);
          break;
    }

    return 0;
}

int Buzzer(int index){// 왼 뒤 오
    switch (index){
        case BZLeft: 
          // // tone(13, 1000, 1);      //13번핀으로 1,000Hz음을 10ms 동안 발생
          // tone(13, 2000, 10);      //13번핀으로 1,000Hz음을 10ms 동안 발생
          digitalWrite(13, HIGH);
          delay(10);
          digitalWrite(13, LOW);
          break;

        case BZBack:
          // tone(12, 1000, 1);      //12번핀으로 1,000Hz음을 10ms 동안 발생
          // tone(12, 2000, 10);      //13번핀으로 1,000Hz음을 10ms 동안 발생
          //  delay(10);
          digitalWrite(12, HIGH);
          delay(10);
          digitalWrite(12, LOW);
          break;

        case BZRight:
          // tone(11, 1000, 1);      //11번핀으로 1,000Hz음을 10ms 동안 발생
          // tone(11, 2000, 10);      //11번핀으로 1,000Hz음을 10ms 동안 발생
          // delay(10);
          digitalWrite(11, HIGH);
          delay(10);
          digitalWrite(11, LOW);
          break;
    }

    return 0;
}
////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  Set_Sensors();
  

}
void loop() {
  double S1 = getSS_L();
  double S2 = getSS_R();
  double S3 = getSS_B();

  static int iter1 = 0;
  static int iter2 = 0;
  static int iter3 = 0;

  Serial.print("S1: ");Serial.print(S1);
  Serial.print("\tS2: "); Serial.print(S2);
  Serial.print("\tS3: "); Serial.println(S3);

  if (0.01< S1 && S1 < Limit_dis){
    // Serial.print("S1: ");Serial.println(S1);
    // output_Buzzer(BZLeft);
    iter1 ++;
    if (iter1 >30){
      Buzzer(BZLeft);
      iter1 = 0;
    }

  
  }
  if (0.01< S2 && S2 < Limit_dis){
    // Serial.print("S2: "); Serial.println(S2);
    // output_Buzzer(BZBack);
    
    iter2 ++;
    if (iter2 >30){
      Buzzer(BZBack);
      iter3 = 0;
    }
  }
  if (0.01< S3  && S3 < Limit_dis){
    // Serial.print("S3: "); Serial.println(S3);
    // output_Buzzer(BZRight);
    
    
    iter3 ++;
    if (iter3 >30){
    Buzzer(BZRight);
      iter3 = 0;
    }
  }
}