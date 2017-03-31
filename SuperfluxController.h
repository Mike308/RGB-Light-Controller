// SuperfluxController.h

#ifndef _SUPERFLUXCONTROLLER_h
#define _SUPERFLUXCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	
#else
	#include "WProgram.h"
#endif

#define R 1
#define G 2
#define B 3 

class SuperfluxControllerClass
{
 protected:


 public:
	void init();
	void setHSVColor(uint16_t h, uint16_t s, uint16_t v);
	void setRGBColor(uint8_t r, uint8_t g, uint8_t b);
	
	
	
};

extern SuperfluxControllerClass SuperfluxController;

#endif

