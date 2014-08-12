#include "fan.h"
#include "application.h"

Fan::Fan(int p) { pin = p;}

void Fan::spin(int speed = 0){
  analogWrite(pin, speed);
}
