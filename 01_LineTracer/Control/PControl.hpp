#ifndef ___P_CONTROL__CLASS
#define ___P_CONTROL__CLASS

#include <cstdint>
#include "Control.hpp"
#include "DeviceMonitor.hpp"
#include "ColorSensorMonitor.hpp"

namespace linetracer {

class PControl : public Control {
private:
    /* インスタンス */
    const DeviceMonitor* mBrightnessMonitor;    // 反射光監視

    /* 属性 */
    const int32_t mTHREATHOLD;  // しきい値

public:
    /* コンストラクタ */
    PControl(const DeviceMonitor* brightnessmonitor, int32_t threathold, float p_gain)
        : mBrightnessMonitor(brightnessmonitor), mTHREATHOLD(threathold), Control(p_gain)
    {
        ;
    }

    /* 制御する */
    float control()
    {
        int32_t brightness;     // 反射光
        float   p_value;        // P制御値

        /* ダウンキャスト */
        brightness = dynamic_cast<ColorSensorMonitor*>(mBrightnessMonitor)->readBrightness();   // 反射光を読み取る

        mDiff = mTHREATHOLD - brightness;               // 偏差を求める
        p_value = static_cast<float>(mDiff) * mGAIN;    // P制御値を求める
        return p_value;
    }

};  // class PControl

}   // namespace linetracer

#endif // ___P_CONTROL__CLASS
