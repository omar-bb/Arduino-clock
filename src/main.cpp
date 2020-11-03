#include "LedMatrix.h"
#include "Time.h"

#include <Arduino.h>

const unsigned char ref[11][16] = {
    {0xFF, 0xFF, 0xC3, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xC3, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xF7, 0xE7, 0xD7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xC1, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBD, 0x81, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0x81, 0xFB, 0xF7, 0xEF, 0xDF, 0x83, 0xFD, 0xFD, 0xFD, 0xFD, 0x83, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xBF, 0xBD, 0xBD, 0xBD, 0xBD, 0x81, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0x81, 0xBF, 0xBF, 0xBF, 0x87, 0xBB, 0xFD, 0xFD, 0xBD, 0xBB, 0xC7, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xE7, 0xDB, 0xBF, 0xBF, 0xA3, 0x9D, 0xBD, 0xBD, 0xBD, 0xDD, 0xE3, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0x81, 0xFB, 0xF7, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xE7, 0xDB, 0xBD, 0xBD, 0xBD, 0xC3, 0xDB, 0xBD, 0xBD, 0xBD, 0xBD, 0xC3, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xC7, 0xBB, 0xBD, 0xBD, 0xBD, 0xB9, 0xC5, 0xFD, 0xFD, 0xDB, 0xE7, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xFF, 0xFF}};

RTC_DS3231 rtc;

Time time(&rtc);
LedMatrix display;

void setup()
{
	Serial.begin(9600);
	delay(3000);

	// initializing the rtc module
	time.InitializeRTC();

	pinMode(LEDARRAY_D, OUTPUT);
	pinMode(LEDARRAY_C, OUTPUT);
	pinMode(LEDARRAY_B, OUTPUT);
	pinMode(LEDARRAY_A, OUTPUT);
	pinMode(LEDARRAY_G, OUTPUT);
	pinMode(LEDARRAY_DI, OUTPUT);
	pinMode(LEDARRAY_CLK, OUTPUT);
	pinMode(LEDARRAY_LAT, OUTPUT);

	// clearing the led matrix display
	display.ClearDisplay();
}

void loop()
{
	char timeArr[9];
	unsigned char word[128];

	time.GetTime((char*)&timeArr);
	time.TimeToHex(timeArr, (unsigned char*)&word, ref);
	display.Display(word);
}
