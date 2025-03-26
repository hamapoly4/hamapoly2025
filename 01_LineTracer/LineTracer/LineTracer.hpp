#ifndef ___LINE_TRACER__CLASS
#define ___LINE_TRACER__CLASS

#include "RunSignal.hpp"
#include "Run.hpp"
#include "DeviceMonitor.hpp"

namespace linetracer {

class LineTracer {
public:
    /* 列挙体クラス */
    enum class EState { START, RUN, STOP, FIN, };   // 状態

private:
    /* インスタンス */
    RunSignal*      mEachSignal;        // 各走行合図
    Run*            mLineTrace;         // ライントレース
    DeviceMonitor*  mDistanceMonitor;   // 距離監視
    DeviceMonitor*  mBrightnessMonitor; // 反射光監視
    DeviceMonitor*  mStateMonitor;      // 状態監視

    /* 属性 */
    EState mState;  // 状態

    void exeStart();    // 走行を開始する
    void exeRun();      // 走行を実行する
    void exeStop();     // 走行を停止する

    /* 状態を切り替える */
    void switchState(EState state)
    {
        mState = state;
    }

public:
    /* コンストラクタ */
    LineTracer(RunSignal* eachsignal, Run* linetrace,
                DeviceMonitor* distancemonitor, DeviceMonitor* brightnessmonitor, DeviceMonitor* statemonitor)
        : mEachSignal(eachsignal), mLineTrace(linetrace),
            mDistanceMonitor(distancemonitor), mBrightnessMonitor(brightnessmonitor),
                mStateMonitor(statemonitor), mState(EState::START)
    {
        ;
    }

    void run();     // 走行する

};  // class LineTracer

}   // namespace linetracer

#endif // ___LINE_TRACER__CLASS
