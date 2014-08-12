class Bbq {

  Auger auger;
  Fan fan;  
  
  public:
  Bbq(int augerPin, int fanPin);
  
  void ignite();
  void cook();
  void keep_warm();

};


