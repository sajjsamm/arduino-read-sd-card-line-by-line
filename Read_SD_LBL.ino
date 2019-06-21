#include <SPI.h>
#include <SD.h>
String line;
File myFile;
unsigned long counter = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file for reading:
  myFile = SD.open("myfile.txt");
  if (myFile) {
        while (line = myFile.readStringUntil('\n')){ //or vany other line ending char
        Serial.println(line);
        counter++;
        a = "";
      }
    }
    // close the file:
    myFile.close();
    Serial.println();
    Serial.print("line counter: ");
    Serial.println(counter);
  } 

void loop() {
  // nothing happens after setup
}


