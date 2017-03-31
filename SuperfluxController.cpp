// 
// 
// 

#include "SuperfluxController.h"

void SuperfluxControllerClass::init()
{


}

void SuperfluxControllerClass::setHSVColor(uint16_t h, uint16_t s, uint16_t v){
	
	uint8_t diff;
	
	byte red,green,blue;

	if(h>359) h=359;
	if(s>100) s=100;
	if(v>100) v=100;

	if(h < 61) {
		red = 255;
		green = (425 * h) / 100;
		blue = 0;
		}else if(h < 121){
		red = 255 - ((425 * (h-60))/100);
		green = 255;
		blue = 0;
		}else if(h < 181){
		red = 0;
		green = 255;
		blue = (425 * (h-120))/100;
		}else if(h < 241){
		red = 0;
		green = 255 - ((425 * (h-180))/100);
		blue = 255;
		}else if(h < 301){
		red = (425 * (h-240))/100;
		green = 0;
		blue = 255;
		}else {
		red = 255;
		green = 0;
		blue = 255 - ((425 * (h-300))/100);
	}

	s = 100 - s;
	diff = ((255 - red) * s)/100;
	red =	red + diff;
	diff = ((255 - green) * s)/100;
	green = green + diff;
	diff = ((255 - blue) * s)/100;
	blue = blue + diff;

	red = (red * v)/100;
	green = (green * v)/100;
	blue = (blue * v)/100;
	
	analogWrite(R,red);
	analogWrite(G,green);
	analogWrite(B,blue);

	
}

void SuperfluxControllerClass::setRGBColor(uint8_t r, uint8_t g, uint8_t b){
	
	analogWrite(R,r);
	analogWrite(G,g);
	analogWrite(B,b);
}




SuperfluxControllerClass SuperfluxController;

