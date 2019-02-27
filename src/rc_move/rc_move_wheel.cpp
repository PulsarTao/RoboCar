//
// Created by PulsarV on 19-2-26.
//
#include <rc_move/rcmove.h>
#ifdef __linux__

void RC::RobotCarMove::wheel_1_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_1_BACKWARD);
}

void RC::RobotCarMove::wheel_1_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_1_FORWARD);

}

void RC::RobotCarMove::wheel_2_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_2_BACKWARD);

}

void RC::RobotCarMove::wheel_2_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_2_FORWARD);
}

void RC::RobotCarMove::wheel_3_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_3_BACKWARD);

}

void RC::RobotCarMove::wheel_3_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_3_FORWARD);

}

void RC::RobotCarMove::wheel_AC() {
    this->serial_device->send(RC_WHEEL_AC);
}

void RC::RobotCarMove::wheel_CW() {
    this->serial_device->send(RC_WHEEL_CW);

}

void RC::RobotCarMove::wheel_go_forward() {
    this->serial_device->send((char *) RC_WHEEL_GO_BACKWARD);

}

void RC::RobotCarMove::wheel_go_backward() {
    this->serial_device->send((char *) RC_WHEEL_GO_FORWARD);

}
void RC::RobotCarMove::wheel_stop() {
    this->serial_device->send((char *) RC_WHEEL_STOP);

}

#else
void RC::RobotCarMove::wheel_1_backward(double trangle) {
}

void RC::RobotCarMove::wheel_1_forward(double trangle) {

}

void RC::RobotCarMove::wheel_2_backward(double trangle) {

}

void RC::RobotCarMove::wheel_2_forward(double trangle) {

}

void RC::RobotCarMove::wheel_3_backward(double trangle) {

}

void RC::RobotCarMove::wheel_3_forward(double trangle) {

}

void RC::RobotCarMove::wheel_AC() {
}

void RC::RobotCarMove::wheel_CW() {

}

void RC::RobotCarMove::wheel_go_forward() {

}

void RC::RobotCarMove::wheel_go_backward() {
}
#endif // __linux__
