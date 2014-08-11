

class Auger{
    int pin;
    public:
};

class Fan{
    int pin;
    public:

};
class Igniter{
    public:
    void on();
    void off();
};

class Bbq{
    int a,f;
    public:

    void ignite();
    void cook():
    void keep_warm();
};


class Recipe{
    // in manual mode, create recipe with 24 hours worth of time, otherwise use recipe indicated
    // [[time,temp],[time,temp]]
    
};
class Timer{
    // initialize amount of time
    // run amount of time(based on input of recipe)
    public:
    void start_cycle();
    
};



// class Errors_if_i_can_read_from_device{
//     void low_pellet(){}
//     void no_ignition(){}
//     void element_error(){}
//     void auger_error(){}
//     void fan_error(){}
// };
// start up heater, check for ingnition, if ignition start cooking , if not, restart ingnition sequence or some rescue sequence or alert of failure
// heat sequence: activate fan and auger until temp block chosen has been reached. maintian temp by fan and auger cycle
// check if reignition is needed, initiate if needed
// run for time allotted or internal temp or related to recipe
// watch for runaway temp
// watch for internal temp