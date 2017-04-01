#include <OneWire.h>
#include <DallasTemperature.h>


#include "SuperfluxController.h"


#define R 5
#define G 3
#define B 6




String receiveString = "";
bool checkIfStringReceive = false;

SuperfluxControllerClass controller;
unsigned long currentMills;
OneWire oneWire(9);
DallasTemperature sensors(&oneWire);


void setup()
{

  /* add setup code here */
  Serial.begin(9600);
  controller.init(R,G,B);
  receiveString.reserve(256);
  sensors.begin();
  

}

void loop()
{

  /* add main program code here */
  
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  
  currentMills = millis();
  
  
  if (checkIfStringReceive){
	  
	  controller.ATCommandsService(receiveString,&controller.animation,temperature);
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
