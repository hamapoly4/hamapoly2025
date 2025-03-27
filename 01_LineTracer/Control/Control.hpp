#ifndef ___CONTROL__CLASS
#define ___CONTROL__CLASS

#include <cstdint>

namespace linetracer {

class Control {
protected:
    /* 属性 */
    static  int32_t mDiff;  // 偏差
    const   float   mGAIN;  // ゲイン

    /* コンストラクタ */
    Control(float gain)
        : mGAIN(gain)
    {
        ;
    }

public:
    /* 純粋仮想関数 */
    virtual float control() = 0;    // 制御する

};  // class Control

int32_t Control::mDiff = 0;     // 静的属性の定義

}   // namespace linetracer

#endif // ___CONTROL__CLASS
