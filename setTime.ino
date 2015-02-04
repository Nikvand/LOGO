void SetTime()
{
  int hour_count =0;
  int minute_count=0;
  int second_count=0;
  myGLCD.clrScr();
     {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 255, 0);
    myGLCD.setBackColor(0, 255, 0);

    myGLCD.fillRoundRect (40, 20, 60, 40);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (40, 20, 60, 40);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("+",42,24);

  }
  
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 255, 0);
        myGLCD.setBackColor(0, 255, 0);

    myGLCD.fillRoundRect (140, 20, 160, 40);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (140, 20, 160, 40);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("+",142,24);

  }
  
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 255, 0);
        myGLCD.setBackColor(0, 255, 0);

    myGLCD.fillRoundRect (240, 20, 260, 40);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (240, 20, 260, 40);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("+",242,24);

  }
          myGLCD.setBackColor(0, 0, 0);

    myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.printNumI(hour_count, 20,50,2,'0');
    myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" : ", 83,70);
    myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    //myGLCD.print("",120,80);
    myGLCD.printNumI(minute_count,120,50,2,'0');
    myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.print(" : ", 183,70);
    myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
    //myGLCD.print(":",160,80);
    myGLCD.printNumI(second_count,220,50,2,'0');
    
    
     {
                 myGLCD.setBackColor(0, 0, 255);

     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10, 160, 90, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 160, 90, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Back",20,185);

  }
  
  {
              myGLCD.setBackColor(0, 0, 255);

    myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (220, 160, 300, 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (220, 160, 300, 220);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("Set",240,185);
  }
  
  
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(255, 0, 0);
    myGLCD.setBackColor(255, 0, 0);

    myGLCD.fillRoundRect (40, 110, 60, 130);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (40, 110, 60,130);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("-",42,112);

  }
  
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(255, 0, 0);
        myGLCD.setBackColor(255, 0, 0);

    myGLCD.fillRoundRect (140, 110, 160,130);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (140, 110, 160, 130);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("-",142,112);

  }
  
   {
     myGLCD.setFont(BigFont); //SmallFont SevenSegNumFont BigFont
    myGLCD.setColor(255, 0, 0);
        myGLCD.setBackColor(255, 0, 0);

    myGLCD.fillRoundRect (240, 110, 260, 130);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (240, 110, 260, 130);
    //myGLCD.printNumI(1, 55, 130);
    myGLCD.print("-",242,112);

  }
  
  
  
  while(flag_set)
  {
        if(myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if(y>20 && y<40)
      {
        if(x>40 && x<60)
        {
           waitForIt(40, 20, 60, 40);
           if(hour_count<24)
             hour_count++;
           else
             hour_count=0;
           myGLCD.setBackColor(0, 0, 0);

           myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
           myGLCD.printNumI(hour_count, 20,50,2,'0');
        }
        if(x>140 && x<160)
        {
           waitForIt(140, 20, 160, 40);
           if(minute_count<60)
             minute_count++;
           else
             minute_count=0;
           myGLCD.setBackColor(0, 0, 0);

         myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
          //myGLCD.print("",120,80);
          myGLCD.printNumI(minute_count,120,50,2,'0');
        }
              if(x>240 && x<260)
        {
                               waitForIt(240, 20, 260, 40);
           if(second_count<59)
             second_count++;
           else
             second_count=0;
           myGLCD.setBackColor(0, 0, 0);

                   myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
                    //myGLCD.print(":",160,80);
                    myGLCD.printNumI(second_count,220,50,2,'0');
        }
        
       
      

  }
  
  
  
   if(y>110 && y<130)
      {
        if(x>40 && x<60)
        {
           waitForIt(40, 110, 60, 130);
           if(hour_count>0)
             hour_count--;
           else
             hour_count=0;
           myGLCD.setBackColor(0, 0, 0);

           myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
           myGLCD.printNumI(hour_count, 20,50,2,'0');
        }
        if(x>140 && x<160)
        {
           waitForIt(140, 110, 160, 130);
           if(minute_count>0)
             minute_count--;
           else
             minute_count=0;
           myGLCD.setBackColor(0, 0, 0);

          myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
          //myGLCD.print("",120,80);
          myGLCD.printNumI(minute_count,120,50,2,'0');
        }
              if(x>240 && x<260)
        {
            waitForIt(240, 110, 260, 130);
           if(second_count>0)
             second_count--;
           else
             second_count=0;
           myGLCD.setBackColor(0, 0, 0);

                   myGLCD.setFont(SevenSegNumFont); //SmallFont SevenSegNumFont BigFont
                    //myGLCD.print(":",160,80);
                    myGLCD.printNumI(second_count,220,50,2,'0');
        }
      

  }
  
  if(y>160 && y<220)
  {
    if(x>10 && x<90)
    {
        waitForIt(10, 160, 90, 220);
        flag_set = false;
        break;
    }
    if(x>220 && x<300)
    {
        waitForIt(220, 160, 300, 220);
       setTime(hour_count,minute_count,second_count,day(),month(),year());
       flag_set  = false;
       break;
    }
  }
 
  
    }  //end of touch if
  
}
}
