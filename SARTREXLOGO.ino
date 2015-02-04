// UTFT_Bitmap (C)2014 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the drawBitmap()-function.
//
// This demo was made to work on the 320x240 modules.
// Any other size displays may cause strange behaviour.
//
// This program requires the UTFT library.
//
//This is done on LINUX to check

//I am adding this to check git functionality
//change added to check Nima2

#include <UTFT.h>
#include <UTouch.h>
#include <avr/pgmspace.h>
#include <Time.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t BigFont[];

//extern unsigned int info[0x400];
extern unsigned int SAR[14400];
extern unsigned int bck[4800];
extern unsigned int fer[7000];
//extern unsigned int her[63600];
enum states {N,M,G,T,C,MM};

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
UTFT myGLCD(ITDB32S,38,39,40,41);
UTouch  myTouch( 6, 5, 4, 3, 2);
int x, y;
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";




/*************************
**  Required functions  **
*************************/

//extern unsigned int tux[0x400];
int r;

   bool flag_back =false;
   bool flag_set = false;
   bool flag_alarm = false;
   bool flag_set_back = false;
   bool flag_set_done = false;

   states stat = MM; 

void setup()
{
  myGLCD.InitLCD();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  setTime(14,59,0,31,1,15);
}





void loop()
{
   

      myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
      myGLCD.fillScr(255, 255, 255);
      myGLCD.setColor(255, 255, 255);
      myGLCD.setContrast(64);
      myGLCD.setBrightness(16);
      myGLCD.setColor(VGA_AQUA);
      //myGLCD.drawBitmap(0,0,80,60,bck,4);
      myGLCD.setBackColor(255,255,255);   //VGA_MAROON
      myGLCD.print(" SARTREX Inc. ", CENTER,28);
      myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
      //myGLCD.setBackColor(VGA_OLIVE);
      myGLCD.print("Detection System ", CENTER,45);
      myGLCD.setColor(255, 255, 255);

      myGLCD.drawBitmap(95,95,120,120,SAR);
      myGLCD.setBackColor(0,0,255);
      myGLCD.setFont(SmallFont); //SmallFont SevenSegNumFont BigFont
      drawButtons(); 
      stat = MM;
     while(stat == MM)
   { 
   if(myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if(x>10 && x<80)
      {
        if(y>90 && y<150)
        {
          Serial.println("Monitor");
          waitForIt(10, 90, 80, 150);
          stat = M;
        }
        if(y>160 && y<220)
        {
          Serial.println("Calib.");
          waitForIt(10, 160, 80, 220);
          stat = C;

        }
      }
      if(x>230 && x<310)
      {
        if(y>90 && y<150)
        {
           Serial.println("Graph");
           waitForIt(230, 90, 310, 150);
           stat = G;

        }
        if(y>160 && y< 220)
        {
          Serial.println("Time");
          waitForIt(230, 160, 310,220);
          stat = T;

        }
      }    
    }
   switch(stat)
   {
     case M:
       Serial.println(M);
       Monitor();
     case T:
       Serial.println("T");
         flag_back =false;
         flag_set = false;
         flag_alarm = false;
         Time();
         break;
    case C:
       Serial.println("C");
       Calib();
     case G:
       Serial.println("G");
       Graph();
   
   }
   Serial.print(stat);
   }
}
