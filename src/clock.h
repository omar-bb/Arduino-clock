#ifndef __CLOCK__
#define __CLOCK__

void createArrayOfTime(unsigned char sinput[8], unsigned char* wordout);
void Clear_Display();
void Display(const unsigned char dat[4 * 32]);
void Scan_Line(unsigned char m);
void Send(unsigned char dat);

#endif