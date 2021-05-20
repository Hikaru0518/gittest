#pragma once

#define PI 3.1415926535897932384626433832795f
/*************************
** 定数 **
*************************/
// 敵機の最大数
const int ENEMY_MAX = 6;
const int ENEMY_IMAGE_MAX = 4;
const int ENEMY_CREATE_TIME = 200;
/*************************
** 構造体 **
*************************/
// 敵機の構造体
struct ENEMY
{
	bool flg; // 使用フラグ
	int type; // タイプ
	int img; // 画像
	int x, y, w, h; // 座標x,y幅w高さh
		int speed; // 移動速度
	int point; // スコア加算
	int mx;
	int cnt;
};
extern struct ENEMY mEnemy[ENEMY_MAX]; //敵車パラメータ
extern int mImageEnemy[ENEMY_IMAGE_MAX]; //敵車画像
extern int EnemyCount[ENEMY_IMAGE_MAX]; //
extern void Enemy_Initialize();//初期化
extern void Enemy_Finalize();//終了処理
extern void Enemy_Update();//更新
extern void Enemy_Draw();//描画
extern int CreateEnemy(); //敵車の生成
//extern int HitBoxPlayer(PLAYER*, ENEMY*); //当たり判定（四角）