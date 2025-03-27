#ifndef ___COLOR_SENSOR_MONITOR__CLASS
#define ___COLOR_SENSOR_MONITOR__CLASS

#include <cstdint>
#include "DeviceMonitor.hpp"
#include "ColorSensor.h"

namespace linetracer {

class ColorSensorMonitor : public DeviceMonitor {
private:
    /* インスタンス */
    const spikeapi::ColorSensor& mBrightnessSensor; // 反射光センサ

    /* 属性 */
    int32_t mBrightness;    // 反射光

public:
    /* コンストラクタ */
    ColorSensorMonitor(const spikeapi::ColorSensor& brightnesssensor)
        : mBrightnessSensor(brightnesssensor)
    {
        ;
    }

    /* データを書き込む */
    void writeData()
    {
        mBrightness = mBrightnessSensor.getReflection();    // 反射光の値を取得する
    }

    /* 反射光を読み取る */
    int32_t readBrightness() const
    {
        return mBrightness;
    }

};  // class ColorSensorMonitor

}   // namespace linetracer

#endif // ___COLOR_SENSOR_MONITOR__CLASS
