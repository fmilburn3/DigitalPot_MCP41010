/*
  DigiPot.cpp - Library for MCP41010 digital potentiometer.
  Created by Frank Milburn, 17 June 2015
  Released into the public domain.
*/

#include <Energia.h>
#include "DigiPot.h"

DigiPot::DigiPot(int digiPotPin)
{
  _digiPotPin = digiPotPin;
  pinMode(_digiPotPin, OUTPUT);
}
void DigiPot::setValue(byte potValue) 
{
  _potCommand = B00010001;         // command to write to pot
  _potValue = potValue;            // pot value to be written
  writeValue(_potCommand, _potValue);
}
void DigiPot::shutdown() 
{ 
  _potCommand = B00100001;         // command to shutdown pot
  _potValue = B00000000;           // pot value doesn't matter
  writeValue(_potCommand, _potValue);
}
void DigiPot::writeValue(byte _potCommand, byte _potValue)
{
  digitalWrite(_digiPotPin, LOW);   // SS pin low - select chip
  SPI.transfer(_potCommand);        // transfer command
  SPI.transfer(_potValue);          // transfer value
  digitalWrite(_digiPotPin, HIGH);  // SS pin high - de-select chip
}
