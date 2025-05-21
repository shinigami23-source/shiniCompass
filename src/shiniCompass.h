
#include <QMC5883LCompass.h>
#include <shiniConfig.h>

#ifndef shiniCompass_h
#define shiniCompass_h

class shiniCompass{
private:
    uint16_t azimuth;
    uint8_t bearing;
    uint8_t lastBearing;
    uint8_t moveToBearing;

    void onBearingChange();
    QMC5883LCompass compass;
public:
    void begin();
    void read();
    void setMoveToBearing(uint8_t);
    uint8_t getBearing();

};
#endif