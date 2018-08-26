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
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//Sensor inputs
#define BME_SCK 5
#define BME_MISO 4
#define BME_MOSI 2
#define BME_CS 0

// Screen inputs
#define cs   10
#define dc   9
#define rst  8


// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);
BME280 sensor;

void setup() {
  Serial.begin(9600);

  //Setup input for Humidity
  int humidityInput = A1;
  pinMode(humidityInput, INPUT);

  //Setup Sensor
  sensor.settings.commInterface = I2C_MODE;
  sensor.settings.I2CAddress = 0x77;
  sensor.settings.runMode = 3;
  sensor.settings.tStandby = 0;
  sensor.settings.filter = 0;
  sensor.settings.tempOverSample = 1;
  sensor.settings.pressOverSample = 1;

  //Setup Screen
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.stroke(255, 255, 255);

  //Play Init. Anim.
  TFTscreen.text("Paranormal Superstore",6,57);
  TFTscreen.text("www.paranormalsuperstore.com",6,80);
  delay(2000);
  TFTscreen.background(0,0,0);
  delay(1000);
}

void loop() {

  //Output Barometer

  //Output Temp

  //Output Humidity


}

void writeToScreen(char* input, int x, int y){
  //Output to serial for testing
  Serial.println(input);

  //Clear screen for new display
  TFTscreen.background(0,0,0);
  TFTscreen.text(input,x,y);

}
