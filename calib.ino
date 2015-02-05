
void Calib(){  myGLCD.clrScr();
        //File myFile;
   pinMode(53, OUTPUT);
   //pinMode(52, OUTPUT);
   //pinMode(10, OUTPUT);

        Serial.println("SD calib");

while(!myTouch.dataAvailable()){
      //myGLCD.drawBitmap(10,10,250,350,fer,1);
    
      if (sd.begin(53,SPI_FULL_SPEED)) {
        Serial.println("SD INIT");
        if (inFile.open(bkgRaw,O_READ)) {
      Serial.println("SD CARD READING");
      dispRaw(&myGLCD,&inFile);
      inFile.close();
    }    }
  //if (!SD.begin(53)) {
    //Serial.println("initialization failed!");
    //return;
  //}
  //Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  //myFile = SD.open("test.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  //if (myFile) {
    //Serial.print("Writing to test.txt...");
    //myFile.println("testing 1, 2, 3.");
    // close the file:
    //myFile.close();
    //Serial.println("done.");
  //} else {
    // if the file didn't open, print an error:
    //Serial.println("error opening test.txt");
 // }
  
  // re-open the file for reading:
  //myFile = SD.open("test.txt");
  //if (myFile) {
    //Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    //while (myFile.available()) {
        //Serial.write(myFile.read());
    //}
    // close the file:
    //myFile.close();
  //} else {
    // if the file didn't open, print an error:
    //Serial.println("error opening test.txt");
  //}

}
}


