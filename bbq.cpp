#include "auger.h"
#include "fan.h"
#include "bbq.h"

Bbq::Bbq(int augerPin, int fanPin) : auger(augerPin), fan(fanPin){}


void Bbq::ignite() {
    auger.turn(100);
    fan.spin(100);
}

void Bbq::cook() {
    // feed pellets at rate specified by
    // spin fan at rate specified by
    // keep reading temp
    // keep reading temp2
    // turn on ignition if needed
}

void Bbq::keep_warm() {

}