#ifndef ___CONTROL_CLASS
#define ___CONTROL_CLASS

#include <cstdint>
#include "Control.hpp"
#include "ColorSensorMonitor.hpp"

class PControl : public Control {
private:
    const int32_t mThreathold;
    ColorSensorMonitor* mBrightnessMonitor;

public:
    PControl(int32_t threathold ColorSensorMonitor* brightnessmonitor)
        : mThreathold(threathold), mBrightnessMonitor(brightnessmonitor)
    float control()
    {
        int32_t brightness;
        float p_varue;
        brightness = mBrightnessMonitor->readBrightness();
        mDiff = mThreathold - brightness;
        p_varue = static_cast<float>(mDiff) * mGain;
    }



};

#endif