////////////////////////////////////////////////////
// 추후 *.c / *.h 을 만들어 관리
#define SSLeft 1
#define SSBack 2
#define SSRight 3
#define BZLeft 1
#define BZBack 2
#define BZRight 3

#define trig_pin_L  2   // 좌측 초음파센서
#define echo_pin_L  3   // 좌측 초음파센서
#define trig_pin_R  10  // 우측 초음파 센서
#define echo_pin_R  11  // 우측 초음파 센서
#define Limit_dis 100 // 지정된 거리 이하일때 반응, 단위 [cm]

int Set_Sensors(){
  // setting SuperSonic Sensor 
  pinMode(trig_pin_L, OUTPUT);
  pinMode(echo_pin_L, INPUT);
  pinMode(trig_pin_R, OUTPUT);
  pinMode(echo_pin_R, INPUT);

  return 0;
}

double get_SSSensor(int index){// 왼 뒤 오
    double distance;

    switch (index){
        case SSLeft: 
          digitalWrite(trig_pin_L, LOW);
          delayMicroseconds(2);
          digitalWrite(trig_pin_L, HIGH);
          delayMicroseconds(10);
          digitalWrite(trig_pin_L, LOW);

          double time_L = pulseIn(echo_pin_L, HIGH);
          distance = time_L * 340 / 10000 / 2;
          break;

        case SSBack:
          printf("NOP");
          break;

        case SSRight:
          digitalWrite(trig_pin_R, LOW);
          delayMicroseconds(2);
          digitalWrite(trig_pin_R, HIGH);
          delayMicroseconds(10);
          digitalWrite(trig_pin_R, LOW);

          double time_R = pulseIn(echo_pin_R, HIGH);
          distance = time_R * 340 / 10000 / 2;
          break;
        default:
          printf("did not anything");
          break;
    }

    return distance;
}

int output_Buzzer(int index){// 왼 뒤 오
    switch (index){
        case BZLeft: 
          tone(1, 1000, 10);      //1번핀으로 1,000Hz음을 10ms 동안 발생
          break;

        case BZBack:
          tone(2, 1000, 10);      //2번핀으로 1,000Hz음을 10ms 동안 발생
          break;

        case BZRight:
          tone(3, 1000, 10);      //2번핀으로 1,000Hz음을 10ms 동안 발생
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
  double getSS_L = get_SSSensor(SSLeft);
  double getSS_R = get_SSSensor(SSRight);
  
  if (getSS_L < Limit_dis){
    output_Buzzer(BZLeft);
  }
  if (getSS_R < Limit_dis){
    output_Buzzer(BZRight);
  }
}
