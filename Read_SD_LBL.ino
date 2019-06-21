#include <SPI.h>
#include <SD.h>
String a;
File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

  // re-open the file for reading:
  myFile = SD.open("b.txt");
  if (myFile) {
    Serial.println("b.txt:");

    while (a = myFile.readStringUntil('\n')){
        Serial.println(a);
        a = "";
      }
    }
    // close the file:
    myFile.close();
  } 

void loop() {
  // nothing happens after setup
}


