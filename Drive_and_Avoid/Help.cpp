#include "Help.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle;

//初期化
void Help_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Menu.png");

}

//終了処理
void Help_Finalize() {
	DeleteGraph(mImageHandle);

}

//更新
void Help_Update() {
	if (iKeyFlg == PAD_INPUT_2) {
		SceneMgr_ChangeScene(eScene_Menu);
	}
}

//描画
void Help_Draw(){
	DrawGraph(0,0,mImageHandle,FALSE);

	SetFontSize(16);
	DrawString(20, 120, "ヘルプ画面", 0xffffff, 0);

	DrawString(20,160, "これは障害物を避けながら", 0xffffff, 0);
	DrawString(20, 180, "走り続けるゲームです", 0xffffff, 0);
	DrawString(20, 200, "燃料が尽きるか、障害物に", 0xffffff, 0);
	DrawString(20, 220, "数回当たるとゲームオーバーです", 0xffffff, 0);

	DrawString(20, 450, "----　スペースキーを押してタイトルへ戻る　----", 0xffffff, 0);
}