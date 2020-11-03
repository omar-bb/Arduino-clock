#include "Time.h"

void Time::InitializeRTC()
{
	m_rtc->begin();
	m_rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void Time::GetTime(char *sinput)
{
	DateTime now = m_rtc->now();

	String h = (String(now.hour(), DEC).length() == 1) ? "0" + String(now.hour(), DEC)
	                                                   : String(now.hour(), DEC);
	String m = (String(now.minute(), DEC).length() == 1) ? "0" + String(now.minute(), DEC)
	                                                     : String(now.minute(), DEC);
	String s = (String(now.second(), DEC).length() == 1) ? "0" + String(now.second(), DEC)
	                                                     : String(now.second(), DEC);

	String timeRTC = h + ":" + m + ":" + s;

	timeRTC.toCharArray(sinput, 9);
}

void Time::TimeToHex(char sinput[9], unsigned char *wordout, const unsigned char refTemp[11][16])
{
	for (int x = 0, j = 0; x < 8; x++, j += 16)
	{
		int ipos = (int)sinput[x] - 48;

		for (int k = 0; k < 16; k++)
			wordout[k + j] = refTemp[ipos][k];
	}
}
