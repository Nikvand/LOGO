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
extern unsigned int her[63600];
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

void drawButtons()
{
// Draw the upper row of buttons
// Draw the center row of buttons
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10, 90, 80, 150);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 90, 80, 150);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Monitor",20,115);

  }
  
    {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10, 160, 80, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 160, 80, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Calib.",20,185);

  }
  
   x = 30;
    {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (200+x, 90, 280+x, 150);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (200+x, 90, 280+x, 150);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Graph",220+x,115);

  }
  
 {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (200+x, 160, 280+x, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (200+x, 160, 280+x, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Time",220+x,185);

  }
}


// Draw a red frame while a button is touched
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
  myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

/*************************
**  Required functions  **
*************************/

//extern unsigned int tux[0x400];
int r;

   bool flag_back =false;
   bool flag_set = false;
   bool flag_alarm = false;
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



void Monitor(){   
  myGLCD.clrScr();
  for (int i=0; i<100; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=32+random(256);
    y=45+random(146);
    r=random(30);
    myGLCD.drawCircle(x, y, r);
  }
}


void Time(){ 
  
  myGLCD.clrScr();
 myGLCD.setBackColor(0,0,0);
  //void printNumI(long num, int x, int y, int length=0, char filler=' ');
   {
     myGLCD.setFont(SmallFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10, 160, 90, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 160, 90, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Back",35,185);

  }
   {
     myGLCD.setFont(SmallFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (115, 160, 195, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (115, 160, 195, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("SET TIME",125,185);

  }
  
  {
    myGLCD.setFont(SmallFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (220, 160, 300, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (220, 160, 300, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("SET ALARM",225,185);
  }
  //waitForIt(int x1, int y1, int x2, int y2)
  while(!flag_set && !flag_alarm && !flag_back)
  {
      //myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    //myGLCD.print("Time : Date ", CENTER,20);
    myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.printNumI(day(), 20,20,2,'0');
        myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" / ", 83,55);
        myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont

    myGLCD.printNumI(month(), 120,20,2,'0');
    myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" / ", 183,55);
    myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.printNumI((year()-2000), 220,20,2,'0');

    myGLCD.printNumI(hour(), 20,80,2,'0');
           myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" : ", 83,100);
        myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    //myGLCD.print("",120,80);
    myGLCD.printNumI(minute(),120,80,2,'0');
           myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" : ", 183,100);
        myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    //myGLCD.print(":",160,80);
    myGLCD.printNumI(second(),220,80,2,'0');
    delay(800);
    
    if(myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if(y>160 && y<220)
      {
        if(x>10 && x<90)
        {
          flag_back = true;
          waitForIt(10, 160, 90, 220);
          break;
        }
        if(x>115 && x<195)
        {
          flag_set = true;
            waitForIt(115, 160, 195, 220);
            break;
        }
         if(x>220 && x<300)
        {
          flag_alarm = true;
          waitForIt(220, 160, 300, 220);
          break;
        }
      }
    }

  }

}
void Graph(){
  myGLCD.clrScr();
}
void Calib(){  myGLCD.clrScr();
while(!myTouch.dataAvailable()){
      myGLCD.drawBitmap(10,10,250,350,fer,1);}

}

void loop()
{
   

      myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
      myGLCD.fillScr(255, 255, 255);
      myGLCD.setColor(255, 255, 255);
      myGLCD.setContrast(255);
      myGLCD.setBrightness(255);
      myGLCD.drawBitmap(0,0,80,60,bck,4);
      myGLCD.setBackColor(VGA_MAROON);
      myGLCD.print(" SARTREX Inc. ", CENTER,28);
      myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
      myGLCD.setBackColor(VGA_OLIVE);
      myGLCD.print("Detection System ", CENTER,45);
      myGLCD.drawBitmap(95,95,120,120,SAR);
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
