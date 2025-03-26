#ifndef ___CONTROL_CLASS
#define ___CONTROL_CLASS

#include <cstdint>

class Control {
protected:
    int32_t mDiff;
    const float mGain;

    Control(float gain)
        : mGain(gain)
    {
        ;
    }

public:
    virtual float control() = 0;

};

#endif 