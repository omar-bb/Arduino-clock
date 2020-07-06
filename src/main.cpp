#include "clock.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arduino.h"

#define LEDARRAY_D 2
#define LEDARRAY_C 3
#define LEDARRAY_B 4
#define LEDARRAY_A 5
#define LEDARRAY_G 6
#define LEDARRAY_DI 7
#define LEDARRAY_CLK 8
#define LEDARRAY_LAT 9

/* const unsigned char zero[16] = {0xFF,0xFF,0xC3,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0xC3,0xFF,0xFF};
const unsigned char one[16] = {0xFF,0xFF,0xF7,0xE7,0xD7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xC1,0xFF,0xFF};
const unsigned char two[16] = {0xFF,0xFF,0xFF,0xC3,0xBD,0xBD,0xBD,0xFD,0xFB,0xF7,0xEF,0xDF,0xBD,0x81,0xFF,0xFF};
const unsigned char three[16] = {0xFF,0xFF,0xFF,0x81,0xFB,0xF7,0xEF,0xDF,0x83,0xFD,0xFD,0xFD,0xFD,0x83,0xFF,0xFF};
const unsigned char four[16] = {0xFF,0xFF,0xFF,0xBF,0xBD,0xBD,0xBD,0xBD,0x81,0xFD,0xFD,0xFD,0xFD,0xFD,0xFF,0xFF};
const unsigned char five[16] = {0xFF,0xFF,0xFF,0x81,0xBF,0xBF,0xBF,0x87,0xBB,0xFD,0xFD,0xBD,0xBB,0xC7,0xFF,0xFF};
const unsigned char six[16] = {0xFF,0xFF,0xE7,0xDB,0xBF,0xBF,0xA3,0x9D,0xBD,0xBD,0xBD,0xDD,0xE3,0xFF,0xFF,0xFF};
const unsigned char seven[16] = {0xFF,0xFF,0xFF,0x81,0xFB,0xF7,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xFF,0xFF};
const unsigned char eight[16] = {0xFF,0xFF,0xE7,0xDB,0xBD,0xBD,0xBD,0xC3,0xDB,0xBD,0xBD,0xBD,0xBD,0xC3,0xFF,0xFF};
const unsigned char nine[16] = {0xFF,0xFF,0xFF,0xC7,0xBB,0xBD,0xBD,0xBD,0xB9,0xC5,0xFD,0xFD,0xDB,0xE7,0xFF,0xFF};
const unsigned char twopoint[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF}; */

const unsigned char ref[11][16] = {
  {0xFF,0xFF,0xC3,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0xC3,0xFF,0xFF},
  {0xFF,0xFF,0xF7,0xE7,0xD7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xC1,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0xC3,0xBD,0xBD,0xBD,0xFD,0xFB,0xF7,0xEF,0xDF,0xBD,0x81,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0x81,0xFB,0xF7,0xEF,0xDF,0x83,0xFD,0xFD,0xFD,0xFD,0x83,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0xBF,0xBD,0xBD,0xBD,0xBD,0x81,0xFD,0xFD,0xFD,0xFD,0xFD,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0x81,0xBF,0xBF,0xBF,0x87,0xBB,0xFD,0xFD,0xBD,0xBB,0xC7,0xFF,0xFF},
  {0xFF,0xFF,0xE7,0xDB,0xBF,0xBF,0xA3,0x9D,0xBD,0xBD,0xBD,0xDD,0xE3,0xFF,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0x81,0xFB,0xF7,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xFF,0xFF},
  {0xFF,0xFF,0xE7,0xDB,0xBD,0xBD,0xBD,0xC3,0xDB,0xBD,0xBD,0xBD,0xBD,0xC3,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0xC7,0xBB,0xBD,0xBD,0xBD,0xB9,0xC5,0xFD,0xFD,0xDB,0xE7,0xFF,0xFF},
  {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF}
};


char time[8] = {'2', '4', ':', '2', '7', ':', '5', '0'};

int counter = 0;

unsigned char Word[128];

unsigned char Display_Buffer[8];
unsigned char Display_Swap_Buffer[1][32]={0};

void setup()
{
  createArrayOfTime(time, (unsigned char*)&Word);
  
  Serial.begin(9600);
  pinMode(LEDARRAY_D, OUTPUT); 
  pinMode(LEDARRAY_C, OUTPUT);
  pinMode(LEDARRAY_B, OUTPUT);
  pinMode(LEDARRAY_A, OUTPUT);
  pinMode(LEDARRAY_G, OUTPUT);
  pinMode(LEDARRAY_DI, OUTPUT);
  pinMode(LEDARRAY_CLK, OUTPUT);
  pinMode(LEDARRAY_LAT, OUTPUT);

  Clear_Display();
}

void loop() {
  
  Display(Word);
}

/* void updateTime() {

  while 
} */

void createArrayOfTime(unsigned char sinput[8], unsigned char* wordout) {
  
  for (int x = 0; x < 8; x++) {
    
    int ipos = (int)sinput[x] - 48;
    
    Serial.println(sinput[x]);
    Serial.println(ipos);
    
    for (int k = 0; k < 16; k++) {
      wordout[k + counter] = ref[ipos][k]; 
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
    
    if( dat&0x01 ) {
      
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