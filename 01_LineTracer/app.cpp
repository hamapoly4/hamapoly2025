
#include "app.h"
#include <stdio.h>
#include <cstdint>

/* ここに使用するクラスのヘッダファイルをインクルード */
#include "LineTracer.hpp"
#include "RunSignal.hpp"
#include "Start.hpp"
#include "Stop.hpp"
#include "Run.hpp"
#include "LineTrace.hpp"
#include "Control.hpp"
#include "PControl.hpp"
#include "IControl.hpp"
#include "DControl.hpp"
#include "DeviceMonitor.hpp"
#include "UltrasonicSensorMonitor.hpp"
#include "ColorSensorMonitor.hpp"
#include "ButtonMonitor.hpp"
#include "Port.h"
#include "UltrasonicSensor.h"
#include "ColorSensor.h"
#include "Button.h"
#include "Motor.h"

/* パラメータ */
static const float      gPGAIN = 0.6;       // Pゲイン
static const float      gIGAIN = 0.01;      // Iゲイン
static const float      gDGAIN = 0.7;       // Dゲイン
static const int32_t    gTHREATHOLD = 50;   // しきい値
static const int8_t     gPOWER = 50;        // パワー値
static const
    linetracer::
        LineTrace::EEdge gEDGE = linetracer::LineTrace::EEdge::LEFT;    // 左エッジ

/* ここに静的インスタンスを生成する */
static const spikeapi::UltrasonicSensor gDistanceSensor(EPort::PORT_F);     // 測距センサ
static const spikeapi::ColorSensor      gBrightnessSensor(EPort::PORT_C);   // 反射光センサ
static       spikeapi::Button           gCenterButton;                      // 中央ボタン
static const spikeapi::Motor            gLeftMotor(EPort::PORT_E, EDirection::COUNTERCLOCKWISE);    // 左モータ
static const spikeapi::Motor            gRightMotor(EPort::PORT_B, EDirection::CLOCKWISE);          // 右モータ

/* 動的インスタンス確保のためのポインタを定義 */
linetracer::UltrasonicSensorMonitor*    gDistanceMonitor;       // 距離監視
linetracer::ColorSensorMonitor*         gBrightnessMonitor;     // 反射光監視
linetracer::ButtonMonitor*              gStateMonitor;          // 状態監視
linetracer::Control*                    gPController;           // P制御装置
linetracer::Control*                    gIController;           // I制御装置
linetracer::Control*                    gDController;           // D制御装置
linetracer::Run*                        gLeftLineTrace;         // 左ライントレース
linetracer::RunSignal*                  gEachSignal[2];         // 各走行合図
linetracer::LineTracer*                 gLeftEdgeTracer;        // 左エッジトレーサ

/* 動的にインスタンスを確保 */
static void create_system()
{
    gDistanceMonitor    = new linetracer::UltrasonicSensorMonitor(gDistanceSensor);
    gBrightnessMonitor  = new linetracer::ColorSensorMonitor(gBrightnessSensor);
    gStateMonitor       = new linetracer::ButtonMonitor(gCenterButton);
    gPController        = new linetracer::PControl(gBrightnessMonitor, gTHREATHOLD, gPGAIN);
    gIController        = new linetracer::IControl(gIGAIN);
    gDController        = new linetracer::DContorl(gDGAIN);
    gLeftLineTrace      = new linetracer::LineTrace(gPController, gIController, gDController,
                                                    gEDGE, gLeftMotor, gRightMotor, gPOWER);
    gEachSignal[0]      = new linetracer::Start(gDistanceMonitor);
    gEachSignal[1]      = new linetracer::Stop(gStateMonitor);
    gLeftEdgeTracer     = new linetracer::LineTracer(gEachSignal, gLeftLineTrace,
                                                    gDistanceMonitor, gBrightnessMonitor,
                                                    gStateMonitor);
}

/* 動的インスタンスを解放 */
static void destroy_system()
{
    delete gDistanceMonitor;
    delete gBrightnessMonitor;
    delete gStateMonitor;
    delete gPController;
    delete gIController;
    delete gDController;
    delete gLeftLineTrace;
    delete gEachSignal[0];
    delete gEachSignal[1];
    delete gLeftEdgeTracer;
}

/* メインタスク(起動時にのみ関数コールされる) */
void main_task(intptr_t unused)
{
    create_system();

    sta_cyc(SUB_TASK_CYC);  // サブタスクの起動
  
    slp_tsk();  // メインタスクの就寝
  
    stp_cyc(SUB_TASK_CYC);  // サブタスクの停止
  
    destroy_system();

	printf("------------攻略終了------------\n");

    ext_tsk();  // タスク終了
}

/* サブタスク(10ms周期で関数コールされる) */
void sub_task(intptr_t unused)
{
    gLeftEdgeTracer->run();     // 走行する

    ext_tsk();  // タスク終了
}
