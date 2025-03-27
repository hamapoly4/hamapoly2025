#ifndef ___ULTRASONIC_SENSOR_MONITOR__CLASS
#define ___ULTRASONIC_SENSOR_MONITOR__CLASS

#include <cstdint>
#include "DeviceMonitor.hpp"
#include "UltrasonicSensor.h"

namespace linetracer {

class UltrasonicSensorMonitor : public DeviceMonitor {
private:
    /* インスタンス */
    const spikeapi::UltrasonicSensor& mDistanceSensor;  // 測距センサ

    /* 属性 */
    int32_t mDistance;  // 距離

public:
    /* コンストラクタ */
    UltrasonicSensorMonitor(const spikeapi::UltrasonicSensor& distancesensor)
        : mDistanceSensor(distancesensor)
    {
        ;
    }

    /* データを書き込む */
    void writeData()
    {
        mDistance = mDistanceSensor.getDistance();  // 距離を測定する
    }

    int32_t readDistance() const
    {
        return mDistance;
    }

};  // class UltrasonicSensorMonitor

}   // namespace linetracer

#endif // ___ULTRASONIC_SENSOR_MONITOR__CLASS
