#ifndef ___D_CONTROL__CLASS
#define ___D_CONTROL__CLASS

#include <cstdint>
#include "Control.hpp"

namespace linetracer {

class DContorl : public Control {
private:
    /* 属性 */
    int32_t mOldDiff;   // 過去の偏差

public:
    /* コンストラクタ */
    DContorl(float d_gain)
        : Control(d_gain)
    {
        ;
    }

    /* 制御する */
    float control()
    {
        float d_value;  // D制御値

        d_value = static_cast<float>(mDiff - mOldDiff) * mGAIN; // D制御値を求める
        mOldDiff = mDiff;   // 偏差を保持する

        return d_value;
    }

};  // class DControl

}   // namespace linetracer

#endif // ___D_CONTROL__CLASS
