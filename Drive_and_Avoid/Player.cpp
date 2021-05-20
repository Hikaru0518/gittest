#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Player.h"
/*************************
** 変数 **
*************************/
// 自機
struct PLAYER mPlayer;
static int mImagePlayer; //画像ハンドル格納用変数
//初期化
void Player_Initialize() {
	mImagePlayer = LoadGraph("images/pleyer.png"); //画像のロード
		//// プレイヤーの初期設定
		mPlayer.flg = true;
	mPlayer.x = PLAYER_POS_X;
	mPlayer.y = PLAYER_POS_Y;
	mPlayer.w = PLAYER_WIDTH;
	mPlayer.h = PLAYER_HEIGHT;
	mPlayer.angle = 0.0;
	mPlayer.count = 0;
	mPlayer.speed = PLAYER_SPEED;
	mPlayer.hp = PLAYER_HP;
	mPlayer.fuel = PLAYER_FUEL;
	mPlayer.mileage = 0;
}
//終了処理
void Player_Finalize() {
	DeleteGraph(mImagePlayer); //画像の解放
}
//更新
void Player_Update() {
	//プレイヤー（自車）の加速・減速
		// Aキーで加速
		if (iKeyFlg & PAD_INPUT_A && mPlayer.speed < 11) mPlayer.speed++;
	// Xキーで減速
		if (iKeyFlg & PAD_INPUT_C && mPlayer.speed > 1) mPlayer.speed--;
	//プレイヤー（自車）の左右移動
		if (iNowKey & PAD_INPUT_LEFT
			) mPlayer.x -= PLAYER_SPEED;
	if (iNowKey & PAD_INPUT_RIGHT
		) mPlayer.x += PLAYER_SPEED;
	// 画面をはみ出さないようにする
		if (mPlayer.x < 40) mPlayer.x = 40;
	if (mPlayer.x > SCREEN_WIDTH - 180) mPlayer.x = SCREEN_WIDTH - 180;
}
//描画
void Player_Draw() {
	// プレイヤーの表示
	if (mPlayer.flg) { //通常の表示
		if (iNowKey & PAD_INPUT_LEFT) {
			DrawRotaGraph(mPlayer.x, mPlayer.y, 1.0f, -PI / 18, mImagePlayer, TRUE,
				FALSE);
		}
		else if (iNowKey & PAD_INPUT_RIGHT) {
			DrawRotaGraph(mPlayer.x, mPlayer.y, 1.0f, PI / 18, mImagePlayer, TRUE, FALSE);
		}
		else {
			DrawRotaGraph(mPlayer.x, mPlayer.y, 1.0f, 0, mImagePlayer, TRUE, FALSE);
		}
	}
	else { //ぶつかったときの表示
		if (++mPlayer.count >= 80) mPlayer.flg = true;
		if (mPlayer.count / 5 % 2 == 0) {
			DrawRotaGraph(mPlayer.x, mPlayer.y, 1.0f, 0, mImagePlayer, TRUE, FALSE);
		}
	}
}