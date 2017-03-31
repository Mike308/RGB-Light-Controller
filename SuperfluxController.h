// SuperfluxController.h

#ifndef _SUPERFLUXCONTROLLER_h
#define _SUPERFLUXCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	
#else
	#include "WProgram.h"
#endif



class SuperfluxControllerClass
{
	
	
	
 protected:


 public:
 
		typedef struct
		{
			uint8_t mode;
			unsigned long speed;
			uint8_t step;
			
		}tAnimation;
		
	tAnimation animation;
	
	
	void init(uint8_t r, uint8_t g, uint8_t b);
	void setHSVColor(uint16_t h, uint16_t s, uint16_t v);
	void setRGBColor(uint8_t r, uint8_t g, uint8_t b);
	void setAnimation(tAnimation * animation, unsigned long currentMills);
	void ATCommandsService(String str, tAnimation * animation);
	
	
	
	
private:
	
	void circleOfColor(tAnimation * animation, unsigned long currentMills);
	void switchingColors(tAnimation * animation, unsigned long currentMills);
	enum animations {circleOfColorEnum,switchingColorsEnum,animationOff};
	uint8_t rPin;
	uint8_t gPin;
	uint8_t bPin;
		

	
	

	
	
	
	
};

extern SuperfluxControllerClass SuperfluxController;

#endif

