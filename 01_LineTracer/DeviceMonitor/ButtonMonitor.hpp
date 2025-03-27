#ifndef ___BUTTON_MONITOR__CLASS
#define ___BUTTON_MONITOR__CLASS

#include "DeviceMonitor.hpp"
#include "Button.h"

namespace linetracer {

class ButtonMonitor : public DeviceMonitor {
private:
    /* インスタンス */
    spikeapi::Button& mCenterButton;    // 中央ボタン

    /* 属性 */
    bool mState;    // 状態

public:
    /* コンストラクタ */
    ButtonMonitor(spikeapi::Button& centerbutton)
        : mCenterButton(centerbutton)
    {
        ;
    }

    /* データを書き込む */
    void writeData()
    {
        mState = mCenterButton.isCenterPressed();   // 中央ボタンの状態を確認する
    }

    /* 状態を読み取る */
    bool readState() const
    {
        return mState;
    }

};  // class ButtonMonitor

}   // namespace linetracer

#endif // ___BUTTON_MONITOR__CLASS
