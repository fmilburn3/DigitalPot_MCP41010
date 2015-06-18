/*
  DigiPot.h - Library for MCP41010 SPI digital potentiometer.
  Created by Frank Milburn, 17 June 2015
  Released into the public domain.
*/
#ifndef DigiPot_h
#define DigiPot_h

#include <Energia.h>
#include <SPI.h>

class DigiPot
{
  public:
    DigiPot(int digiPotPin);
    void setValue(byte potValue);
    void shutdown();
  private:
    void writeValue(byte _potCommand, byte _potValue);
    int _digiPotPin;
    byte _potValue;
    byte _potCommand;
};
#endif
