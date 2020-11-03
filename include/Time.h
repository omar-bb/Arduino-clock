#pragma once

#ifndef TIME_H
#define TIME_H

#include "RTClib.h"

class Time
{
public:
    Time(RTC_DS3231* rtc)
        : m_rtc(rtc) {}

    void InitializeRTC();
    // parameter : char* sinput
    void GetTime(char* sinput);
    void TimeToHex(char sinput[9], unsigned char* wordout, const unsigned char refTemp[11][16]);

private:
    RTC_DS3231* m_rtc;
};

#endif
