#include "app.h"
#include "LineTracer.hpp"

using namespace linetracer;

/* 走行する */
void LineTracer::run()
{
    switch (mState)
    {
        case EState::START:     // 走行開始中
            exeStart();
            break;
        case EState::RUN:       // 走行実行中
            exeRun();
            break;
        case EState::STOP:      // 走行停止中
            exeStop();
            break;
        default:
            break;
    }
}

/* 走行を開始する */
void LineTracer::exeStart()
{
    mDistanceMonitor->writeData();  // データ（距離）を書き込む
    if (mEachSignal[0].checkSignal())
    {
        switchState(EState::RUN);   // ”走行実行中”に遷移する
    }
}

/* 走行を実行する */
void LineTracer::exeRun()
{
    mBrightnessMonitor->writeData();    // データ（反射光）を書き込む
    mStateMonitor->writeData();         // データを（状態）書き込む

    mLineTrace->run();  // 走行する

    if (mEachSignal[1].checkSignal())
    {
        switchState(EState::STOP);  // ”走行停止中”に遷移する
    }
}

/* 走行を停止する */
void LineTracer::exeStop()
{
    mLineTrace->stop();         // 停止する
    switchState(EState::FIN);   // ”終了状態”に遷移する
    wup_tsk(MAIN_TASK);         // メインタスクを起こす
}
