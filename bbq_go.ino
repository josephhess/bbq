#include "application.h"
#include "auger.h"
#include "fan.h"
#include "bbq.h"
#include "temp_probe.h"
#include "display.h"


int encoderPinA   = D0;
int encoderPinB   = D1;
int encoderButton = D2;

int tempPinA      = A0;
int tempPinB      = A1;

int fan_pin     = A5;
int auger_pin   = A6;
int igniter_pin = A2;

volatile bool adjust_counter_bool = false;
volatile bool show_main_menu = true;
volatile int counter;
int desired_temp;
int grill_area_temp = 0.0;
int heat = D5;

Display display;
TempProbe grill_area_probe (tempPinA);
Bbq bbq (fan_pin, auger_pin);


void setup()
{
    pinMode(fan_pin, OUTPUT);
    pinMode(auger_pin, OUTPUT);
    pinMode(igniter_pin,OUTPUT);
    pinMode(tempPinA,      INPUT_PULLUP);
    pinMode(encoderPinA,   INPUT_PULLUP);
    pinMode(encoderPinB,   INPUT_PULLUP);
    pinMode(encoderButton, INPUT_PULLUP);
    pinMode(heat,          OUTPUT);

    attachInterrupt(encoderPinA, call_adjust_counter, FALLING);

    display.initialize();
}

void loop()
{
    bbq.ignite();

    if (grill_area_probe.read() >= desired_temp)
        digitalWrite(heat,LOW);
    else
        digitalWrite(heat,HIGH);
    main_menu();
    adjust_counter();
}

void call_adjust_counter() {
    show_main_menu = false;
    adjust_counter_bool = true;
    attachInterrupt(encoderButton, set_desired_temp, CHANGE);
    detachInterrupt(encoderPinA);
    attachInterrupt(encoderPinA, choose_temp, FALLING);
}

void main_menu() {
    if (show_main_menu) {
        display.clear_screen();
        Serial1.print("current_temp  ");
        Serial1.print( grill_area_probe.read());
        Serial1.print("desired_temp ");
        Serial1.print(desired_temp);
    }
}

void adjust_counter() {
    if (adjust_counter_bool) {
        display.clear_screen();
        Serial1.print("Setting temp to ");
        Serial1.print(counter);
        // delay(200);
        // display.clear_screen();
    }
}

void lower_speed(int component, int amount) {
    for (int motorValue = 255 ; motorValue >= 0; motorValue -= 5) {
        analogWrite(component, motorValue);
        delay(60);
    }
}

void increase_speed(int component, int amount) {
    for(int motorValue = 0 ; motorValue <= 255; motorValue +=5) {
        analogWrite(component, motorValue);
        delay(60);
    }
}

void choose_temp() {
    if (digitalRead(encoderPinB))
        counter -= 10;
    else
        counter += 10;
}

void set_desired_temp() {
    desired_temp = counter;
    adjust_counter_bool = false,
    show_main_menu = true;
    detachInterrupt(encoderButton);
    attachInterrupt(encoderPinA, call_adjust_counter, CHANGE);
}
