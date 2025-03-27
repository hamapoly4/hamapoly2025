#ifndef ___LINE_TRACE__CLASS
#define ___LINE_TRACE__CLASS

#include <cstdint>
#include "Run.hpp"
#include "Control.hpp"
#include "Motor.h"

namespace linetracer {

class LineTrace : public Run {
public:
    /* 列挙体クラス */
    enum class EEdge { LEFT, RIGHT };   // エッジ方向

private:
    /* インスタンス */
    Control* mPController;  // P制御装置
    Control* mIController;  // I制御装置
    Control* mDController;  // D制御装置

    /* 属性 */
    const EEdge mEDGE;  // エッジ

public:
    /* コンストラクタ */
    LineTrace(Control* pcontroller, Control* icontroller, Control* dcontroller, EEdge edge,
                const spikeapi::Motor& leftmotor, const spikeapi::Motor& rightmotor, int8_t power)
        : mPController(pcontroller), mIController(icontroller),
            mDController(dcontroller), mEDGE(edge), Run(leftmotor, rightmotor, power)
    {
        ;
    }

    /* 走行する */
    void run()
    {
        float p_value;  // P制御値
        float i_value;  // I制御値
        float d_value;  // D制御値
        int8_t turn;    // 操作量

        p_value = mPController->control();  // P制御をする
        i_value = mIController->control();  // I制御をする
        d_value = mDController->control();  // D制御をする
        turn = static_cast<int8_t>(p_value + i_value + d_value);    // 操作量を求める

        switch (mEDGE)
        {
            case EEdge::LEFT:   // 左エッジのとき
                mLeftMotor.setPower(mPOWER - turn);
                mRightMotor.setPower(mPOWER + turn);
                break;
            case EEdge::RIGHT:  // 右エッジのとき
                mLeftMotor.setPower(mPOWER + turn);
                mRightMotor.setPower(mPOWER - turn);
                break;
            default:
                break;
        }
    }

};  // class LineTrace

}   // namespace linetracer

#endif // ___LINE_TRACE__CLASS
