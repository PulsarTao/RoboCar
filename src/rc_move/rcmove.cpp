//
// Created by PulsarV on 18-5-9.
//

#include <rc_move/rcmove.h>


int RC::RobotCarMove::init(int camera_id, char *device, char *mapping) {
    if (mapping != NULL)
        this->mapping = mapping;
    this->camera_id = camera_id;
    this->type = RC_PLAY_BY_CAMERA;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init(char *video, char *device, char *mapping) {
    if (mapping != NULL)
        this->mapping = mapping;
    this->video = video;
    this->type = RC_PLAY_BY_VIDEO;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init_serial_device(char *device) {
    this->serial_device = new Serial();
#ifdef __linux__
    this->serial_device->openSerial(device);
#endif // __linux__
    return 1;
}

int RC::RobotCarMove::start() {
    std::fstream mapped;
    std::ifstream map;

    cv::VideoCapture cap;
    switch (this->type) {
        case RC_PLAY_BY_CAMERA:
            if (this->camera_id != -1) {
                LOG::logInfo("Open Camera Device From Device");
                int id = this->camera_id;
                cap.open(id);
            } else
                return LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
        case RC_PLAY_BY_VIDEO:
            if (this->video != NULL) {
                LOG::logInfo("Open Camera Device From Files");
                cap.open(this->camera_id);
            } else
                return LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
    }

    if (this->mapping != NULL) {
        map.open(this->mapping);
    } else {
        mapped.open("map.bin", std::ios::app);
    }

    if (cap.isOpened()) {
        LOG::logSuccess("Open Camera Device Successed");
        RC::CV::BodyDetceter decter;
        decter.init_body_cascade(RC_BODY_CASCADES_FILE_PATH);
        while (true) {
            cv::Mat frame, output;
            cap >> frame;

            if (not frame.empty()) {
                //巡线
                if (this->AutoMove) {
                    cv::Mat re_frame;
                    cv::resize(frame, re_frame, cv::Size(128, 128), 0, 0, cv::INTER_LINEAR);

//                    int ans[2] = {0, 0};
//                    cv::Mat thresh_image;
//                    cv::Mat gray_image;
//                    RC::CV::detcetByRightAndLeft(re_frame, ans);

//                    LOG::logInfo("Model AutoMove");

//                    if(this->serial_device->isOpend()){
//                        if (ans[0] > (128 / 2) + 10) {
//                            this->wheel_AC();
//                        }
//                        if (ans[0] < (128 / 2) - 10) {
//                            this->wheel_CW();
//                        }
//                        this->wheel_go_backward();
//                        char buffer[64] = {'\0'};
//                        this->serial_device->recive(buffer, 64);
//                        std::string data = buffer;
//                    }
                }
                //自动跟随
                if (this->AutoFollow) {
                    cv::Point center,img_center;
                    img_center.x=frame.cols/2;
                    img_center.y=frame.rows/2;
                    LOG::logInfo("Model AutoFllow");
                    std::vector<cv::Rect> body=decter.detcetBody(frame);
                    if (not body.empty()){
                        center.x = body[0].x + cvRound(body[0].width/2.0);
                        center.y = body[0].y + cvRound(body[0].height/2.0);
                        cv::circle(frame, center, 3,cv::Scalar(0,0,255),-1);
                    }
                    cv::circle(frame, img_center, 10,cv::Scalar(255,0,0),-1);
//                    if(this->serial_device->isOpend()){
//                        if(center.x>img_center.x){
//                            //车轮左修正
//                            this->wheel_2_forward(20);
//                            this->wheel_1_forward(20);
//                            this->wheel_3_forward(20);
//                        } else{
//                            //车轮右修正
//                            this->wheel_2_backward(20);
//                            this->wheel_1_backward(20);
//                            this->wheel_3_backward(20);
//                        }
//                        if(center.y>img_center.y){
//                            //前进
//                        } else{
//                            //后退
//
//                        }
                    }
                }

                cv::imshow("", frame);
                char key = cv::waitKey(20);
                switch (key){
                    case 'c':
                        this->AutoMove = this->AutoMove == true ? false : true;
                        this->AutoFollow= false;
                        break;
                    case 'f':
                        this->AutoFollow=this->AutoFollow == true ? false : true;
                        this->AutoMove= false;
                        break;
                    default:
                        break;
                }
                if (map.is_open()) {
                    if (!map.eof()) {
                        char com = map.get();
                        this->command(com);
                        continue;
                    }
                }
                if (key == 'x')break;

                if (mapping == NULL)
                    if ((int) key > 65 and (int) key < 122)
                        mapped << &key;
                if (this->serial_device->isOpend()) {
                    this->command(key);
                }
//            }
        }
    } else
        return LOG::logError(RC_OPEN_CAMERA_ERROR);
    cv::destroyAllWindows();
    mapped.close();
    return 1;
}

void RC::RobotCarMove::command(char com) {
    switch (com) {
        case 'w':
            this->wheel_go_backward();
            this->wheel_go_backward();
            break;
        case 'a':
            this->wheel_2_forward(20);
            this->wheel_2_forward(20);
            break;
        case 's':
            this->wheel_go_forward();
            this->wheel_go_forward();
            break;
        case 'd':
            this->wheel_1_backward(20);
            this->wheel_1_backward(20);
            break;
        case 'q':
            this->wheel_AC();
            this->wheel_AC();

            break;
        case 'e':
            this->wheel_CW();
            this->wheel_CW();
            break;
        case 'r':
            this->wheel_stop();
            this->wheel_stop();
            break;
    }
}

