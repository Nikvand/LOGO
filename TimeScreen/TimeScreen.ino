void Timescreen()
{
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
}

