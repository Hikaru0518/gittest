#pragma once

#define PI 3.1415926535897932384626433832795f
/*************************
** 定数 **
*************************/
// 画面領域の大きさ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH = 63;
const int PLAYER_HEIGHT = 120;
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_SPEED = 5;
const int PLAYER_HP = 100;
const double PLAYER_FUEL = 400.0;
/*************************
** 構造体 **
*************************/
// プレイヤー
struct PLAYER
{
	bool flg; // 自車の状態フラグ
		int x, y; // 座標x,y
	int w, h; // 幅w高さh
		double angle; // 機体の向き
		int count; // 自車表示用カウンター
	int speed; // 移動速度
	int hp; // 体力
	double fuel; // 燃料
	int mileage; // 走行距離
};
extern struct PLAYER mPlayer;
extern void Player_Initialize();//初期化
extern void Player_Finalize();//終了処理
extern void Player_Update();//更新
extern void Player_Draw();//描画