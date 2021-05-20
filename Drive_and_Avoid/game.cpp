#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
/*************************
** 変数 **
*************************/
static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //画像のロード
	Player_Initialize(); //プレイヤー（自車）の初期化
	Enemy_Initialize(); //敵車の初期化
}
//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
	Player_Finalize(); // プレイヤー（自車）の開放
	Enemy_Finalize(); //敵車の開放
}
//更新
void Game_Update() {
	//BボタンまたはESCボタンでメニューに戻る
	if (iKeyFlg == PAD_INPUT_B || (CheckHitKey(KEY_INPUT_ESCAPE) != 0)) {
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	Player_Update();
	Enemy_Update();
}
//描画
void Game_Draw() {
	//背景(コース)の描画処理
	BackScrool();
	//敵車、プレイヤーの描画処理
	Player_Draw();
	Enemy_Draw();
}
/**********************************
* 背景画像スクロール処理
* 引 数：なし
* 戻り値：なし
 **********************************/
void BackScrool(void)
{
	//スクロールのスピードを設定
	mPlayer.mileage += mPlayer.speed;
	//スクロール画像表示
	DrawGraph(0, mPlayer.mileage % 480 - 480, mImageHandle, FALSE);
	DrawGraph(0, mPlayer.mileage % 480, mImageHandle, FALSE);
}