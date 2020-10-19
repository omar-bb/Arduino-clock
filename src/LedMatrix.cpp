#include "LedMatrix.h"

void LedMatrix::ClearDisplay() 
{
	unsigned char i;
	for(i = 0 ; i < 32 ;i++) 
	{	
		_displaySwapBuffer[0][i] = 0xff;   
	}
}

void LedMatrix::Display(const unsigned char dat[4 * 32]) 
{    
	unsigned char i;

	for(i = 0; i < 16; i++) 
	{
		digitalWrite(LEDARRAY_G, HIGH);
		
		_displayBuffer[0] = dat[0*32+i];    
		_displayBuffer[1] = dat[0*32+(i+16)];

		_displayBuffer[2] = dat[1*32+i];    
		_displayBuffer[3] = dat[1*32+(i+16)];

		_displayBuffer[4] = dat[2*32+i];    
		_displayBuffer[5] = dat[2*32+(i+16)];

		_displayBuffer[6] = dat[3*32+i];    
		_displayBuffer[7] = dat[3*32+(i+16)];

		Send(_displayBuffer[7]);
		Send(_displayBuffer[6]);
		Send(_displayBuffer[5]);
		Send(_displayBuffer[4]);
		Send(_displayBuffer[3]);
		Send(_displayBuffer[2]);
		Send(_displayBuffer[1]);
		Send(_displayBuffer[0]);
		
		digitalWrite(LEDARRAY_LAT, HIGH);
		delayMicroseconds(1);

		digitalWrite(LEDARRAY_LAT, LOW);
		delayMicroseconds(1);

		ScanLine(i);

		digitalWrite(LEDARRAY_G, LOW);
		
		delayMicroseconds(300);     
    } 
}

void LedMatrix::ScanLine(unsigned char m)
{   
	switch(m) 
	{
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

void LedMatrix::Send(unsigned char dat) 
{  
	unsigned char i;
	digitalWrite(LEDARRAY_CLK, LOW);
	delayMicroseconds(1); 
	digitalWrite(LEDARRAY_LAT, LOW);
	delayMicroseconds(1);

	for(i = 0 ; i < 8 ; i++)
	{
		if (dat&0x01)
			digitalWrite(LEDARRAY_DI, HIGH);

		else
			digitalWrite(LEDARRAY_DI, LOW);

		digitalWrite(LEDARRAY_CLK, HIGH);
		delayMicroseconds(1);

		digitalWrite(LEDARRAY_CLK, LOW);
		delayMicroseconds(1);
		
		dat >>= 1;
	}
}
