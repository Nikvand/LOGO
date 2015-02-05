void Time(){ 
  
 Timescreen();

  while(!flag_set && !flag_alarm && !flag_back)
  {
      myGLCD.setBackColor(0,0,0);
          myGLCD.setColor(255,255,255);

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

    myGLCD.setColor(0,255,0);
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
            SetTime();
            Timescreen();
            continue;
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
