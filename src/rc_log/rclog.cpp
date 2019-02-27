//
// Created by PulsarV on 18-5-10.
//

#include <rc_log/rclog.h>
#include <iostream>
int RC::LOG::printlog(char *logType,char *str) {
    std::cout<<logType<<str<<std::endl;
    return 1;
}
int RC::LOG::printlog(char *logType,std::string str) {
    std::cout<<logType<<str<<std::endl;
    return 1;
}
int RC::LOG::logSuccess(char *str) {
    std::string _s=str;
    _s="\033[1;32;32m"+_s+"\033[0m";
    RC::LOG::printlog((char*)"\033[1;32;32m[SUCCESS] \033[0m",str);
    return 1;
}
int RC::LOG::logError(char *str) {
//    std::cout<<"\033[33mHello \033[34mworld!\033[0m"<<std::endl;
    std::string _s=str;
    _s="\033[1;32;31m"+_s+"\033[0m";
    RC::LOG::printlog((char*)"\033[1;32;31m[ERROR] \033[0m",_s.c_str());
    return 0;
}

int RC::LOG::logInfo(char *str) {
    RC::LOG::printlog((char*)"\033[1;32;34m[INFO] \033[0m",str);
    return 1;
}
int RC::LOG::logDebug(char *str) {
    RC::LOG::printlog((char*)"[DEBUG] ",str);
    return 1;
}