#ifndef ___RUN_SIGNAL__CLASS
#define ___RUN_SIGNAL__CLASS

#include "DeviceMonitor.hpp"

namespace linetracer {

class RunSignal {
protected:
    /* インスタンス */
    const DeviceMonitor* mDataMonitor;  // データ監視

    /* 属性 */
    bool mSignal;   // 合図

    /* コンストラクタ */
    RunSignal(const DeviceMonitor* datamonitor)
        : mDataMonitor(datamonitor), mSignal(false)
    {
        ;
    }

public:
    /* 純粋仮想関数 */
    virtual bool checkSignal() = 0;     // 合図を確認する

};  // class RunSignal

}   // namespace linetracer

#endif // ___RUN_SIGNAL__CLASS
