#ifndef FUNCS_H
#define FUNCS_H

#include <ctime>
#include <cstdio>
#include <string>

class Timer{
public:
    Timer();
    ~Timer();
    std::string getLocalTime();
};

#endif // FUNCS_H
