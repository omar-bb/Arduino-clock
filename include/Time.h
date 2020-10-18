#pragma once 

#include "RTClib.h"

class Time
{
public:
    void SetTime();
    void GetTime(char* sinput);
    void TimeToHex(char sinput[9], unsigned char* wordout, const unsigned char refTemp[11][16]);
private:
    RTC_DS3231 rtc;
};