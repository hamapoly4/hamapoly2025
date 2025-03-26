#ifndef ___START__CLASS
#define ___START__CLASS

#include "RunSignal.hpp"
#include "DeviceMonitor.hpp"

namespace linetracer {

class Start : public RunSignal {
public:
    /* 列挙体クラス */
    enum class EState { NO_OBSTACLE, A_OBSTACLE, FIN, };    // 状態

private:
    /* 属性 */
    EState mState;  // 状態

    void exeNoObstacle();   // 障害物なし状態を実行する
    void exeAObstacle();    // 障害物あり状態を実行する

    /* 状態を切り替える */
    void switchState(EState state)
    {
        mState = state;
    }

public:
    /* コンストラクタ */
    Start(const DeviceMonitor* distancemonitor)
        : mState(EState::NO_OBSTACLE), RunSignal(distancemonitor)
    {
        ;
    }

    bool checkSignal(); // 合図を確認する

};  // class Start

}   // namespace linetracer

#endif // ___START__CLASS
