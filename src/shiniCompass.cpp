
#include "shiniCompass.h"
void shiniCompass::begin(){

    compass.init();
    #ifdef DEBUG
    Serial.println("compass started...");
    #endif

}

uint8_t shiniCompass::getBearing(){
    return bearing;
}
void shiniCompass::setMoveToBearing(uint8_t _bearing){
    #ifdef DEBUG
    Serial.print("Setting MoveToBearing: ");
    Serial.println(bearing);
    #endif
    moveToBearing = _bearing;


}

void shiniCompass::onBearingChange(){

    #ifdef DEBUG
    Serial.print("Bearing Changed from: ");
    Serial.print(lastBearing);
    Serial.print(" to: ");
    Serial.println(bearing);
    #endif

    //if moveTo is set
    if(moveToBearing == bearing){
        COMMS_SERIAL.println("");  //send trigger
        //reset trigger
        moveToBearing == NULL;
    }

    lastBearing = bearing;
}

void shiniCompass::read(){
    compass.read();
    azimuth = compass.getAzimuth();
    bearing = compass.getBearing(azimuth);

#ifdef DEBUG
    Serial.print("a:");
    Serial.print(azimuth);
    Serial.print(", b:");
    Serial.println(bearing);
    
#endif
    //check if same and return .. if changed ...
    //execute passed method only if changed
    //bearing or azumuth
    //check to see if bearing has changed then trigger
    if( bearing += lastBearing){
        return;
    }
    else{
    onBearingChange();
    }

}
