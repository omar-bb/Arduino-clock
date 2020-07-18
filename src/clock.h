#pragma once

#include "RTClib.h"

#define LEDARRAY_D 2
#define LEDARRAY_C 3
#define LEDARRAY_B 4
#define LEDARRAY_A 5
#define LEDARRAY_G 6
#define LEDARRAY_DI 7
#define LEDARRAY_CLK 8
#define LEDARRAY_LAT 9

void GetTime(char* sinput, RTC_DS3231 rtcSens);
void TimeToHex(char sinput[9], unsigned char* wordout, const unsigned char refTemp[11][16]);
void Clear_Display();
void Display(const unsigned char dat[4 * 32]);
void Scan_Line(unsigned char m);
void Send(unsigned char dat);