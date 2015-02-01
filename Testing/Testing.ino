//

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Uncomment the next line for Arduino 2009/Uno
//UTFT myGLCD(ITDB32S,19,18,17,16);   // Remember to change the model parameter to suit your display module!

// Uncomment the next line for Arduino Mega
//UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!

UTFT myGLCD(ITDB32S,38,39,40,41);
//UTouch  myTouch( 6, 5, 4, 3, 2);

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
}

void loop()
{
    myGLCD.print("Text rotation", 0, 0);
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("0 degrees", 0, 16, 0);
    myGLCD.print("90 degrees", 319, 0, 90);
    myGLCD.print("180 degrees", 319, 239, 180);
    myGLCD.print("270 degrees", 0, 239, 270);

    myGLCD.setFont(SevenSegNumFont);
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("45", 90, 100, 45);
    myGLCD.print("90", 200, 50, 90);
    myGLCD.print("180", 300, 200, 180);

  while (true) {};
}
