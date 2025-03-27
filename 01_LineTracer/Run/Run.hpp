#ifndef ___RUN__CLASS
#define ___RUN__CLASS

#include <cstdint>
#include "Motor.h"

namespace linetracer {

class Run {
protected:
    /* インスタンス */
    const spikeapi::Motor& mLeftMotor;  // 左モータ
    const spikeapi::Motor& mRightMotor; // 右モータ

    /* 属性 */
    const int8_t mPOWER;    // パワー値

    /* コンストラクタ */
    Run(const spikeapi::Motor& leftmotor, const spikeapi::Motor& rightmotor, int8_t power)
        : mLeftMotor(leftmotor), mRightMotor(rightmotor), mPOWER(power)
    {
        ;
    }

public:
    /* 純粋仮想関数 */
    virtual void run() = 0;     // 走行する

    /* 停止する */
    void stop()
    {
        mLeftMotor.stop();      // 左モータを停止する
        mRightMotor.stop();     // 右モータを停止する
    }

};  // class Run

}   // namespace linetracer

#endif // ___RUN__CLASS
