#include "Time.h"

void Time::SetTime()
{
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void Time::GetTime(char* sinput) 
{
	DateTime now = rtc.now();
	
	String h = (String(now.hour(), DEC).length() == 1) ? "0" + String(now.hour(), DEC) : String(now.hour(), DEC);
	String m = (String(now.minute(), DEC).length() == 1) ? "0" + String(now.minute(), DEC) : String(now.minute(), DEC);
	String s = (String(now.second(), DEC).length() == 1) ? "0" + String(now.second(), DEC) : String(now.second(), DEC);

	String timeRTC = h + ":" + m + ":" + s;

	timeRTC.toCharArray(sinput, 9);
}

void Time::TimeToHex(char sinput[9], unsigned char* wordout, const unsigned char refTemp[11][16]) 
{    
    int counter = 0;
    int ipos = 0;

	for (int x = 0; x < 8; x++) 
	{
		ipos = (int)sinput[x] - 48;

		for (int k = 0; k < 16; k++) 
		{
			wordout[k + counter] = refTemp[ipos][k]; 
		}
		counter += 16;
	}
}