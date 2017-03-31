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
	void setAnimation(tAnimation * animation, unsigned long currentMills);
	
	
private:
	
	void circleOfColor(tAnimation *animation, unsigned long currentMills);
	void switchingColors(tAnimation *animation, unsigned long currentMills);
	enum animations {circleOfColorEnum,switchingColorsEnum};
		
	typedef struct
	{
		uint8_t mode;
		unsigned long speed;
		uint8_t step;
		
	}tAnimation;
	
	

	
	
	
	
};

extern SuperfluxControllerClass SuperfluxController;

#endif

