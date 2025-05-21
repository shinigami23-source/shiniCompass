#define DEBUG 1  // Uncomment this line to enable debug
#include <shiniCompass.h>

shiniCompass compass;

void setup(){

#   ifdef DEBUG 
     Serial.begin(115200);  //begin
      delay(500);
    #endif

    compass.begin();
    delay(500);


    #ifdef DEBUG 
     Serial.print("compass started...");
    #endif


}

void loop(){
  compass.read();


}
