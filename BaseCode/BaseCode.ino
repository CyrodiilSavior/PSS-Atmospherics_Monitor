

/*
*
* PARANORMAL SUPERSTORE - ATMOSPHERICS MONITOR
* DESIGNED BY m10 Technology
*
 */

#include <TFT.h>
#include <SPI.h>


#include <Wire.h>
#include <SPI.h>
#include "SparkFunBME280.h"

//Create Sensor
BME280 mySensorB;

// Screen inputs
#define cs   10
#define dc   9
#define rst  8


// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);


void setup() {
  Serial.begin(9600);

  //Setup input for Humidity
  int humidityInput = A1;
  pinMode(humidityInput, INPUT);

  //Setup Screen
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.stroke(255, 255, 255);

  //Play Init. Anim.

  TFTscreen.text("Paranormal",10,37);
  TFTscreen.text("  Superstore",10,67);
  delay(2000);
  TFTscreen.background(0,0,0);
  delay(1000);

  //Setup BMP Sensor
  Wire.begin();
  mySensorB.setI2CAddress(0x76); //Connect to a second sensor
  if(mySensorB.beginI2C() == false) Serial.println("Sensor B connect failed");
  TFTscreen.setTextSize(1);

  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text("Temp: ",6,25);
  TFTscreen.text("F",139,25);

  TFTscreen.text("Pres: ",6,56);
  TFTscreen.text("hpa",139,56);

  TFTscreen.text("Humid: ",6,87);
  TFTscreen.text("%",139,87);


}

void loop() {

  writeToScreen(mySensorB.readTempF(),mySensorB.readFloatPressure(),mySensorB.readFloatHumidity());

}

void writeToScreen(float tempInput, float pressureInput, int HumidityInput){
 //Preliminary Garbage
 char temp[6];
 char pressure[6];
 char humid[6];
 dtostrf(tempInput, 6, 2, temp);
 dtostrf(pressureInput, 6, 2, pressure);
 dtostrf(HumidityInput, 6, 2, humid);


  //Clear screen for new display
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text(temp,65,25);
  TFTscreen.text(pressure,65,56);
  TFTscreen.text(humid,65,87);
  delay(800);
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(temp,65,25);
  TFTscreen.text(pressure,65,56);
  TFTscreen.text(humid,65,87);

}

void writeToScreen(char* input, int x, int y){

  //Output to serial for testing
  Serial.println(input);

  //Clear screen for new display
  TFTscreen.text(input,x,y);

}
