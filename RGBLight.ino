#include "SuperfluxController.h"

#define R 5
#define G 3
#define B 6




String receiveString = "";
bool checkIfStringReceive = false;

SuperfluxControllerClass controller;
unsigned long currentMills;

void setup()
{

  /* add setup code here */
  Serial.begin(9600);
  controller.init(R,G,B);
  receiveString.reserve(256);
  

}

void loop()
{

  /* add main program code here */
  
  currentMills = millis();
  
  
  if (checkIfStringReceive){
	  
	  controller.ATCommandsService(receiveString,&controller.animation);
	  receiveString = "";
	  checkIfStringReceive = false;
	  
	  
	  
  }
  
  controller.setAnimation(&controller.animation,currentMills);
  
  
  

}


void serialEvent(){
	
	while (Serial.available()){
		
		char c = (char)(Serial.read());
		
		receiveString += c;
		
		if (c == '\n'){
			
				checkIfStringReceive = true;
				
				
			
			
		}
		
		
		
	}
	
}
