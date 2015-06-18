# DigitalPot_MCP41010
  This example sketch controls a Microchip MCP41010 I/P digital potentiometer with a MSP-EXP430F5529LP over SPI.
  
  The MCP41xxx has 1 potentiometer channel with 256 taps.  There is a 2 channel version, the MCP42xxx.  The xxx refers to the potentiometer maximum resistance - in the case of the 010 it is 10k ohms.
   
  The MCP41010 is SPI-compatible,and to command it, send two bytes, one with the command selection bits (xxC1xxC2) and one with the data value (0-255).  Note there is only one channel on the MCP41010, so P1 in the command summary table below is ignored.
  
  C1  C0  Command  Command Summary
  --  --  -------  --------------------------------------------------------
   0   0  None     No command executed
   0   1  Write    Write the date contained in Data Byte to the pot
   1   0  Shutdown Enter shutdown mode.  Data Byte does not matter
   1   1  None     No command executed
   
  P1  P0  Potentiometer Selections
  --  --  ------------------------------------------------------------------
   0   0  Dummy Code - pot not affected
   0   1  Command executed on Pot 0
   1   0  Command executed on Pot 1
   1   1  Command executed on both Pots
  So, the byte 00010001 will write to Pot 0.  The byte 00100001 shuts things down.
  
  The chip doesn't write anything back so MISO is not hooked up
