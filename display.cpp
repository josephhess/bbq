#include "display.h"

Display::Display {
    int greeting_chooser = rand() % 6;
    String greetings[5] = {"Get your BBQ on!", "Slow and Low ", "Is it wrong to love your BBQ this much?", "Every day is a ribs day", "Smoke + Heat + Meat = Heaven"};
}
    
void Display::initialize(){
    Serial1.begin(9600);
    delay(100);
    Serial1.write("                "); // clear display
    Serial1.write("                ");
    Serial.print(greetings[greeting_chooser]);
    delay(200);
    Serial1.write("                "); // clear display
    Serial1.write("                ");
    
}
void Bbq::clear_screen (){
    Serial1.write(254); // move cursor to beginning of first line
    Serial1.write(128);

    Serial1.write("                "); // clear display
    Serial1.write("                ");

    Serial1.write(254); // move cursor to beginning of first line
    Serial1.write(128);
}