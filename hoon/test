#define TRIG 2
#define ECHO 3

void setup() {
  
  pinMode (TRIG, OUTPUT);
  pinMode (ECHO, INPUT);
  Serial.begin(9600); //9600bps로 시리얼 통신 설정

}
void loop() {

  digitalWrite (TRIG, LOW); //TRIG를 끈다. 
  delayMicroseconds(2); //끄는데 약간의 시간이 필요
  digitalWrite (TRIG, HIGH); // TRIG를 켠다. 
  delayMicroseconds(10); //TRIG핀에 10us의 펄스를 준다. 
  digitalWrite (TRIG, LOW); //TRIG를 끈다. 

  long distance=pulseIn(ECHO, HIGH)/58.0; //ECHO핀이 1이 되는 시간을 측정해서 cm로 환산. 초음파는 29us 동안 1cm 이동 (왕복 58us)
  Serial.println(distance);
 
  tone (8, 1000, 20); //8번핀으로 1,000Hz음을 20ms 동안 발생
  delay(distance*5); //거리가 짧을수록 자주 울림.
}
