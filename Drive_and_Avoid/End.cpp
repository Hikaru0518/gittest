#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;
static int StopTime;

//初期化
void End_Initialize(){
	mImageHandle = LoadGraph("images/Scene_End.png");
	StopTime = 0;
}

//終了処理
void End_Finalize() {
	DeleteGraph(mImageHandle);
}

//更新

//描画
void End_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//タイムの加算処理＆終了（3秒後）
	if (++StopTime > 180) {
		SceneMgr_ChangeScene(eScene_Stop);
	}
}