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


