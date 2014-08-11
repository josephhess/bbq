#include "bbq.h"

Auger::Auger (int p) { pin = p; }

void Auger::turn(int rate = 0){
    analogWrite(pin,rate);
}
    

Fan::Fan (int p) { pin = p; }
    
void Fan::spin(int speed = 0){
  analogWrite(pin,speed);
} 


Bbq::Bbq (int a){auger_pin = a;}
Bbq::Bbq (int f){fan_pin = f;}
Bbq::Bbq(){
    Auger auger(auger_pin);
    Fan   fan(fan_pin);  
}

    
void Bbq::ignite(){
    auger.turn(100);
    fan.spin(100); 
}


void Bbq::cook(){
    // feed pellets at rate specified by  
    // spin fan at rate specified by
    // keep reading temp
    // keep reading temp2
    // turn on ignition if needed
}
    
void Bbq::keep_warm();
};