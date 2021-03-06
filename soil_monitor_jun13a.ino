#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/5735a352-ed1f-4aa1-99e0-989f66ae220f 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float read_Pot;
  bool pump_status;
  bool push_button;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

#define POTENTIOMETER_PIN A1


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  int potValue = analogRead(POTENTIOMETER_PIN);
  read_Pot = map(potValue, 0, 1023, 0, 1023);  
  
}


/*
  Since PushButton is READ_WRITE variable, onPushButtonChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPushButtonChange()  {
  if(push_button==true)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)  
  onPumpStatusChange();
  ArduinoCloud.update();
  delay(4000);                       // wait for 4 seconds
  digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW  
  
  }
  onPumpStatusChange();
}

/*
  Since PumpStatus is READ_WRITE variable, onPumpStatusChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPumpStatusChange()  {
  // Add your code here to act upon PumpStatus change
  if(push_button==true)
  {pump_status=true;
  }
  else
  {pump_status=false;}

}





