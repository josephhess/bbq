#include "auger.h"
#include "application.h"

Auger::Auger(int p) { pin = p; }

void Auger::turn(int rate = 0){
    analogWrite(pin, rate);
}
