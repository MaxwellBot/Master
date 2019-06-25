#include "LedControl.h"
#include "stdio.h"

LedControl lc1 = LedControl(34, 2, 32, 8); // Pins: DIN(digital),CLK(pwm),CS(digital), # of Display connected
LedControl lc2 = LedControl(28, 3, 30, 4);


//================================================================================================================================================================================= SETUP ==========================================================================
void setup()
{
  lc1.shutdown(0, false); // Wake up displays
  lc1.shutdown(1, false);
  lc1.shutdown(2, false);
  lc1.shutdown(3, false);
  lc1.setIntensity(0, 3); // Set intensity levels
  lc1.setIntensity(1, 3);
  lc1.setIntensity(2, 3);
  lc1.setIntensity(3, 3);
  lc1.clearDisplay(0);    // Clear Displays
  lc1.clearDisplay(1);
  lc1.clearDisplay(2);
  lc1.clearDisplay(3);

  lc1.shutdown(4, false); // Wake up displays
  lc1.shutdown(5, false);
  lc1.shutdown(6, false);
  lc1.shutdown(7, false);
  lc1.setIntensity(4, 3); // Set intensity levels
  lc1.setIntensity(5, 3);
  lc1.setIntensity(6, 3);
  lc1.setIntensity(7, 3);
  lc1.clearDisplay(4);    // Clear Displays
  lc1.clearDisplay(5);
  lc1.clearDisplay(6);
  lc1.clearDisplay(7);

  lc2.shutdown(0, false); // Wake up displays
  lc2.shutdown(1, false);
  lc2.shutdown(2, false);
  lc2.shutdown(3, false);
  lc2.setIntensity(0, 3); // Set intensity levels
  lc2.setIntensity(1, 3);
  lc2.setIntensity(2, 3);
  lc2.setIntensity(3, 3);
  lc2.clearDisplay(0);    // Clear Displays
  lc2.clearDisplay(1);
  lc2.clearDisplay(2);
  lc2.clearDisplay(3);
}

//================================================================================================================================================================================= PROTOTYPES =====================================================================

void eyeshow(byte pic[])
{
  int arr=0;
  int row=0;
  int col=0;
  for (col = 0; col < 8; col++)
  {
    for(row=7; row>-1; row--)
    {
      lc2.setLed(2, row, col, pic[arr]);
      arr++;
    }  
    for(row=0; row<8; row++)
    {  
      lc1.setLed(5, row, 7-col, pic[arr]);
      arr++;
    }  
    for(row=7; row>-1; row--)
    {   
      lc1.setLed(2, row, col, pic[arr]);
      arr++;
    }  
  }  
}

void browshow(byte pic[])
{
  int arr=0;
  int row=0;
  int col=0;
  for (col = 0; col < 8; col++)
  {
    for(row=7; row>-1; row--)
    {
      lc2.setLed(3, row, col, pic[arr]);
      arr++;
    }  
    for(row=0; row<8; row++)
    {  
      lc1.setLed(4, row, 7-col, pic[arr]);
      arr++;
    }  
    for(row=7; row>-1; row--)
    {   
      lc1.setLed(3, row, col, pic[arr]);
      arr++;
    }  
  } 
}

void mouthshow(byte pic[])
{
  int arr=0;
  int row=0;
  int col=0;
  for (col = 0; col < 8; col++)
  {
    for(row=7;row>-1;row--)
    {
      lc2.setLed(0, row, col, pic[arr]);
      arr++;
    }  
    for(row=0; row<8; row++)
    {  
      lc1.setLed(7, row, 7-col, pic[arr]);
      arr++;
    }  
    for(row=7; row>-1; row--)
    {   
      lc1.setLed(0, row, col, pic[arr]);
      arr++;
    }  
  } 
}

void cheekshow(byte pic[])
{
  int arr=0;
  int row=0;
  int col=0;
  for (col = 0; col < 8; col++)
  {
    for(row=7;row>-1;row--)
    {
      lc2.setLed(1, row, col, pic[arr]);
      arr++;
    }  
    for(row=0; row<8; row++)
    {  
      lc1.setLed(6, row, 7-col, pic[arr]);
      arr++;
    }  
    for(row=7; row>-1; row--)
    {   
      lc1.setLed(1, row, col, pic[arr]);
      arr++;
    }  
  } 
}

void startface(byte pic1[],byte pic2[],byte pic3[],byte pic4[])
{
  browshow(pic1);
  eyeshow(pic2); 
  cheekshow(pic3); 
  mouthshow(pic4);
}

//================================================================================================================================================================================= BYTES ==========================================================================
void loop()
{
//BASIC--------------------------------------------------------------------------------------------
byte  fullest[]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

byte blank[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

//EYEBROWS------------------------------------------------------------------------------------------
byte restbrow[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,};

//EYEIMAGES----------------------------------------------------------------------------------------
byte forward[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,};

byte left[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,};

byte leftup[]={
0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

byte leftdown[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,
0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,};

byte right[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,};

byte rightup[]={
0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

byte rightdown[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,};

byte up[]={
0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

byte down[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,
0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,};

//CHEEKS--------------------------------------------------------------------------------------------
byte cheeky[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
};

//MOUTH--------------------------------------------------------------------------------------------
byte restmouth[]={
0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

byte smiley[]={
0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

byte smirk[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

//================================================================================================================================================================================= LOOP ===========================================================================  
  startface(restbrow,forward,blank,smirk);
  int delta=100;
  while(true)
  {
    eyeshow(left);
    delay(delta);
    eyeshow(leftup);
    delay(delta);
    eyeshow(up);
    delay(delta);
    eyeshow(rightup);
    delay(delta);
    eyeshow(right);
    delay(delta);
    eyeshow(rightdown);
    delay(delta);
    eyeshow(down);
    delay(delta);
    eyeshow(leftdown);
    delay(delta);
  }
}