#ifndef ___I_CONTROL__CLASS
#define ___I_CONTROL__CLASS

#include <cstdint>
#include "Control.hpp"

namespace linetracer {

class IControl : public Control {
private:
    /* 属性 */
    int32_t mDiffRingBuffer[10];

    /* バッファを更新する */
    void updateBuffer()
    {
        uint8_t i;      // 添字

        for (i = 9; i > 0; i--)
        {
            mDiffRingBuffer[i] = mDiffRingBuffer[i - 1];    // シフト
        }
        mDiffRingBuffer[0] = mDiff; // バッファの先頭に新しい偏差を書き込む
    }

public:
    /* コンストラクタ */
    IControl(float i_gain)
        : mDiffRingBuffer{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, Control(i_gain)
    {
        ;
    }

    /* 制御する */
    float control()
    {
        int32_t sum = 0;    // 偏差の合計
        uint8_t i;          // 添字
        float   i_value;    // I制御値

        updateBuffer();     // バッファを更新する

        /* バッファの合計を求める */
        for (i = 0; i < 10; i++)
        {
            sum += mDiffRingBuffer[i];
        }

        i_value = static_cast<float>(sum) * mGAIN;  // I制御値を求める

        return i_value;
    }

};  // class IControl

}   // namespace linetracer

#endif // ___I_CONTROL__CLASS
