#include "funcs.h"
using namespace std;

Timer::Timer(){

}

Timer::~Timer(){

}

string Timer::getLocalTime(){
    time_t timep;
    time(&timep);
    char tmp[256];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    string localTime = tmp;
    return localTime;
}
