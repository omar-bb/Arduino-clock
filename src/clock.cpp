#include "Arduino.h"
#include "clock.h"

unsigned char Display_Buffer[8];
unsigned char Display_Swap_Buffer[1][32]={0};

void GetTime(char* sinput, RTC_DS3231 rtcSens) {
	DateTime now = rtcSens.now();
	
	String h = (String(now.hour(), DEC).length() == 1) ? "0" + String(now.hour(), DEC) : String(now.hour(), DEC);
	String m = (String(now.minute(), DEC).length() == 1) ? "0" + String(now.minute(), DEC) : String(now.minute(), DEC);
	String s = (String(now.second(), DEC).length() == 1) ? "0" + String(now.second(), DEC) : String(now.second(), DEC);

	String timeRTC = h + ":" + m + ":" + s;

	timeRTC.toCharArray(sinput, 9);
}

void TimeToHex(char sinput[9], unsigned char* wordout, const unsigned char refTemp[11][16]) {
    
    int counter = 0;
    int ipos = 0;

	for (int x = 0; x < 8; x++) {

		ipos = (int)sinput[x] - 48;

		for (int k = 0; k < 16; k++) {
			wordout[k + counter] = refTemp[ipos][k]; 
		}
		counter += 16;
	}
}

void Clear_Display() {
  
	unsigned char i,j;
	for(i = 0 ; i < 32 ;i++) {
		
		Display_Swap_Buffer[j][i] = 0xff;   
	}
}

void Display(const unsigned char dat[4 * 32]) {
    
	unsigned char i;

	for(i = 0; i < 16; i++) {
    
		digitalWrite(LEDARRAY_G, HIGH);
		
		Display_Buffer[0] = dat[0*32+i];    
		Display_Buffer[1] = dat[0*32+(i+16)];

		Display_Buffer[2] = dat[1*32+i];    
		Display_Buffer[3] = dat[1*32+(i+16)];

		Display_Buffer[4] = dat[2*32+i];    
		Display_Buffer[5] = dat[2*32+(i+16)];

		Display_Buffer[6] = dat[3*32+i];    
		Display_Buffer[7] = dat[3*32+(i+16)];

		Send(Display_Buffer[7]);
		Send(Display_Buffer[6]);
		Send(Display_Buffer[5]);
		Send(Display_Buffer[4]);
		Send(Display_Buffer[3]);
		Send(Display_Buffer[2]);
		Send(Display_Buffer[1]);
		Send(Display_Buffer[0]);
		
		digitalWrite(LEDARRAY_LAT, HIGH);
		delayMicroseconds(1);

		digitalWrite(LEDARRAY_LAT, LOW);
		delayMicroseconds(1);

		Scan_Line(i);

		digitalWrite(LEDARRAY_G, LOW);
		
		delayMicroseconds(300);     
    } 
}

void Scan_Line(unsigned char m) { 
  
	switch(m) {
    
		case 0:     
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW);          
			break;
		case 1:         
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH);     
			break;
		case 2:         
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW);     
			break;
		case 3:         
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH);    
			break;
		case 4:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW);     
			break;
		case 5:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH);    
			break;
		case 6:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW);    
			break;
		case 7:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH);     
			break;
		case 8:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW);     
			break;
		case 9:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH);    
			break;  
		case 10:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW);    
			break;
		case 11:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH);     
			break;
		case 12:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW);    
			break;
		case 13:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH);     
			break;
		case 14:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW);     
			break;
		case 15:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH);    
			break;
		default : break;  
	}
}

void Send(unsigned char dat) {
  
	unsigned char i;
	digitalWrite(LEDARRAY_CLK, LOW);
	delayMicroseconds(1); 
	digitalWrite(LEDARRAY_LAT, LOW);
	delayMicroseconds(1);

	for( i = 0 ; i < 8 ; i++ ) {

	if (dat&0x01) {
		
		digitalWrite(LEDARRAY_DI, HIGH);  
	}
	else {
		
		digitalWrite(LEDARRAY_DI, LOW);
    }

	digitalWrite(LEDARRAY_CLK, HIGH);
	delayMicroseconds(1);
	digitalWrite(LEDARRAY_CLK, LOW);
	delayMicroseconds(1);  
	dat >>= 1;
      
	}    
}