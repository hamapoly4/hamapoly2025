
#include "app.h"
#include <stdio.h>

/* ここに使用するクラスのヘッダファイルをインクルード */



/* ここに静的インスタンスを生成する */




/* 動的インスタンス確保のためのポインタを定義 */



/* 動的にインスタンスを確保 */
static void create_system()
{
    
}

/* 動的インスタンスを解放 */
static void destroy_system()
{
    
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
    

    ext_tsk();  // タスク終了
}
