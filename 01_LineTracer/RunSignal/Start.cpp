#include <cstdint>
#include "Start.hpp"
#include "UltrasonicSensorMonitor.hpp"

using namespace linetracer;

/* 合図を確認する */
bool Start::checkSignal()
{
    switch (mState)
    {
        case EState::NO_OBSTACLE:   // 障害物なし状態
            exeNoObstacle();
            break;
        case EState::A_OBSTACLE:    // 障害物あり状態
            exeAObstacle();
            break;
        default:
            break;
    }

    return mSignal;
}

/* 障害物なし状態を実行する */
void Start::exeNoObstacle()
{
    int32_t distance;   // 距離(mm)

    /* ダウンキャスト */
    distance = dynamic_cast<UltrasonicSensorMonitor*>(mDataMonitor)->readDistance();    // 距離を読み取る

    /* 5cm以内に障害物があれば判定 */
    if (-1 < distance && distance < 50)
    {
        switchState(EState::A_OBSTACLE);    // ”障害物あり状態”に遷移する
    }
}

/* 障害物あり状態を実行する */
void Start::exeAObstacle()
{
    int32_t distance;   // 距離(mm)

    /* ダウンキャスト */
    distance = dynamic_cast<UltrasonicSensorMonitor*>(mDataMonitor)->readDistance();    // 距離を読み取る

    /* 5cm以内に障害物がなければ判定 */
    if (distance <= -1 || 50 <= distance)
    {
        switchState(EState::FIN);   // ”終了状態”に遷移する
        mSignal = true;             // 走行開始合図を出す
    }
}
