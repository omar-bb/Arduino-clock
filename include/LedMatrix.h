#pragma once

#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <Arduino.h>

#define LEDARRAY_D 2
#define LEDARRAY_C 3
#define LEDARRAY_B 4
#define LEDARRAY_A 5
#define LEDARRAY_G 6
#define LEDARRAY_DI 7
#define LEDARRAY_CLK 8
#define LEDARRAY_LAT 9

class LedMatrix
{
public:
    void ClearDisplay();
    void Display(const unsigned char dat[4 * 32]);
    void ScanLine(unsigned char m);
    void Send(unsigned char dat);
private:
    // Display_Buffer / Display_Swap_Buffer
    unsigned char _displayBuffer[8];
    unsigned char _displaySwapBuffer[1][32] = { { 0 } };
};

#endif