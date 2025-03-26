#ifndef ___DEVICE_MONITOR__CLASS
#define ___DEVICE_MONITOR__CLASS   // インクルードカード

namespace linetracer {

class DeviceMonitor {
public:
    /* 純粋仮想関数 */
    virtual void writeData() = 0;   // データを書き込む

};  // class DeviceMonitor

}   // namespace linetracer

#endif // ___DEVICE_MONITOR__CLASS
