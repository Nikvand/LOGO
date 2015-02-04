void Timescreen()
{
   myGLCD.clrScr();
 myGLCD.setBackColor(0,0,255);
  //void printNumI(long num, int x, int y, int length=0, char filler=' ');
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10, 160, 90, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 160, 90, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Back",17,185);

  }
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (115, 160, 195, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (115, 160, 195, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Set",123,185);

  }
  
  {
    myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (220, 160, 300, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (220, 160, 300, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Alarm",220,185);
  }
  //waitForIt(int x1, int y1, int x2, int y2)
}

