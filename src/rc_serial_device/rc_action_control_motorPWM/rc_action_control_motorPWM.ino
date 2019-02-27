#include <DueTimer.h>
#include "action.h"


String comdata = "";

void setup() {
  Serial1.begin(9600);
  pinMode(PwmPin1, OUTPUT);
  pinMode(PwmPin2, OUTPUT);
  pinMode(PwmPin3, OUTPUT);
  pinMode(Direction1, OUTPUT);
  pinMode(Direction2, OUTPUT);
  pinMode(Direction3, OUTPUT);

  Timer0.attachInterrupt(wheel_action_1);
  Timer0.setFrequency(1000);
  Timer1.attachInterrupt(wheel_action_2);
  Timer1.setFrequency(1000);
  Timer2.attachInterrupt(wheel_action_3);
  Timer2.setFrequency(1000);
}

void loop() {
  while (Serial1.available() > 0) {
    comdata += char(Serial1.read());
    delay(2);
  }
  if (comdata.length() > 0) {
    //Serial1.println(comdata);
    wheel_dierection_1 = comdata.substring(0, 1).toInt();
    wheel_speed_1 = comdata.substring(1, 5).toInt();

    wheel_dierection_2 = comdata.substring(5, 6).toInt();
    wheel_speed_2 = comdata.substring(6, 10).toInt();

    wheel_dierection_3 = comdata.substring(10, 11).toInt();
    wheel_speed_3 = comdata.substring(11, 15).toInt();

    Serial1.print("1轮速度:");
    Serial1.print(wheel_speed_1);
    Serial1.print(" 方向:");
    Serial1.println(wheel_dierection_1);

    Serial1.print("2轮速度:");
    Serial1.print(wheel_speed_2);
    Serial1.print(" 方向:");
    Serial1.println(wheel_dierection_2);

    Serial1.print("3轮速度:");
    Serial1.print(wheel_speed_3);
    Serial1.print(" 方向:");
    Serial1.println(wheel_dierection_3);
    Serial1.println("=============");

    digitalWrite(Direction1,(wheel_dierection_1!=0?HIGH:LOW));
    digitalWrite(Direction2,(wheel_dierection_2!=0?HIGH:LOW));
    digitalWrite(Direction3,(wheel_dierection_3!=0?HIGH:LOW));
    
    reset_timers();
    Timer0.setFrequency(wheel_speed_1).start();
    Timer1.setFrequency(wheel_speed_2).start();
    Timer2.setFrequency(wheel_speed_3).start();
    comdata = "";
  }
  //Serial1.println("Hello World");
  delay(200);
}
