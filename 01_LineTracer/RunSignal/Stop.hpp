#ifndef ___STOP__CLASS
#define ___STOP__CLASS

#include "RunSignal.hpp"
#include "DeviceMonitor.hpp"
#include "ButtonMonitor.hpp"

namespace linetracer {

class Stop : public RunSignal {
public:
    /* コンストラクタ */
    Stop(const DeviceMonitor* statemonitor)
        : RunSignal(statemonitor)
    {
        ;
    }

    /* 合図を確認する */
    bool checkSignal()
    {
        /* ダウンキャスト */
        mSignal = dynamic_cast<ButtonMonitor*>(mDataMonitor)->readState();  // 状態を読み取る
        return mSignal;
    }

};  // class Stop

}   // namespace linetracer

#endif // ___STOP__CLASS
