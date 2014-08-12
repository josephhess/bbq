#include "temp_probe.h"
#include "application.h"

TempProbe::TempProbe(int p) {
  pin = p;
}

int TempProbe::read() {
    // return convert_to_f(digitalRead(pin));
}

int TempProbe::convert_to_f(int voltage) {
    double celsius, f;
    celsius = ((voltage * 0.0008) - 1.25) / 0.005;
    f = ((celsius * 9.0)/5.0 + 32.0);
    delay(200);
    return f;
}
