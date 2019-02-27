int time_wait = 1000;
int PwmPin1 = 7;
int PwmPin2 = 6;
int PwmPin3 = 5;
String comdata = "";
int state=0;
void setup() {
  Serial1.begin(9600);
  pinMode(PwmPin1, OUTPUT);
  pinMode(PwmPin2, OUTPUT);
  pinMode(PwmPin3, OUTPUT);

}

void loop() {
  while (Serial1.available() > 0) {
    comdata += char(Serial1.read()); 
    delay(2);
  }
  if (comdata.length() > 0) {
    Serial1.println(comdata); 
    time_wait = comdata.toInt();
    comdata = "";
  }
  //Serial1.println(time_wait);
  if (time_wait > 0) {
 
    if(state==0){
      time_wait+=1;
      }else{
        time_wait-=1;
        }
    if(time_wait>=3000)
      state=1;
    if(time_wait<=300)
      state=0;
     
    delayMicroseconds(time_wait);
    digitalWrite(PwmPin1, HIGH);
    digitalWrite(PwmPin2, HIGH);
    digitalWrite(PwmPin3, HIGH);
    delayMicroseconds(time_wait);
    digitalWrite(PwmPin1, LOW);
    digitalWrite(PwmPin2, LOW);
    digitalWrite(PwmPin3, LOW);
  }
}
