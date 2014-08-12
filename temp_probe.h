class TempProbe {
    int pin;

    public:
    int read();
    TempProbe(int p);
    
    private:
    int convert_to_f(int);
};