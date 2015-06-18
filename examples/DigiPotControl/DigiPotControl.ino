/*
  DigitalPotControl
  
  The library controls a Microchip MCP41010 digital potentiometer and
  was tested with a MSP-EXP430F5529LP over SPI.  In the example the 
  potentiometer slowly brightens an LED, abruptly turns the LED off,
  and goes into low power mode for a short period before starting over again.
   
  Energia example modified and turned into a library for the MCP41010
  Frank Milburn  17 June 2015
  Released into the public domain

  Pin Connections / Wiring
  MCP41010  Connection
  --------  ----------------------------------------------------------
  1 (CS)    Pin 8 of MSP-EXP430F5529LP  (CS)
  2 (SCK)   Pin 7 of MSP-EXP430F5529LP  (SCK)
  3 (SI)    Pin 15 of MSP-EXP430F5529LP (MOSI)
  4 (GND)   GND 
  5 (PAO)   3.3V 
  6 (PWO)   220 ohm resistor to LED and GND
  7 (PBO)   GND 
  8 (Vdd)   3.3V
*/

#include <SPI.h>
#include "DigiPot.h" 

DigiPot pot(8); // Instantiate the digital pot with pin 8 for chip selection

void setup() 
{
  SPI.begin();
}

void loop()
{
  // This potentiometer has 256 taps (0 to 255) and since it is a 10k linear
  // potentiometer this loop will change the level from 10k down to zero in
  // steps of about 39 ohms
  for (int tap = 0; tap < 255; tap++)
  {
    pot.setValue(tap);         // Set the pot value
    delay(20);                 // and reduce resistance slowly
  }
  delay(200);                  // wait a bit at the brightest level of LED
  pot.setValue(0);             // then turn the LED off
  
  pot.shutdown();              // shut everything down for a while...
  sleepSeconds(1);
}
