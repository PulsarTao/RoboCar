int PwmPin1 = 7;
int PwmPin2 = 6;
int PwmPin3 = 5;
int Direction1=2;
int Direction2=3;
int Direction3=4;

int time_wait = 1000;
int wheel_speed_1 = 0;
int wheel_speed_2 = 0;
int wheel_speed_3 = 0;
int wheel_dierection_1 = 0;
int wheel_dierection_2 = 0;
int wheel_dierection_3 = 0;

void reset_timers() {
  Timer0.stop();
  Timer1.stop();
  Timer2.stop();
}
void encode_data(long long data, int *de_data, int data_size) {

}
void decode_data(long long data, int *de_data, int data_size) {

}
void wheel_action_1() {
  if (wheel_speed_1 != 0) {
    digitalWrite(PwmPin1, HIGH);
    digitalWrite(PwmPin1, LOW);
  }

}
void wheel_action_2() {
  if (wheel_speed_2 != 0) {
    digitalWrite(PwmPin2, HIGH);
    digitalWrite(PwmPin2, LOW);
  }
}
void wheel_action_3() {
  if (wheel_speed_3 != 0) {
    digitalWrite(PwmPin3, HIGH);
    digitalWrite(PwmPin3, LOW);
  }
}
