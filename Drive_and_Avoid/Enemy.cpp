#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Enemy.h"
#include "Player.h"
extern int HitBoxPlayer(PLAYER*, ENEMY*); //当たり判定（四角）
/*************************
** 変数 **
*************************/
// エネミー
struct ENEMY mEnemy[ENEMY_MAX];
struct ENEMY enemyCar = { true , 0 , 0 , 0 , -50 , 63 , 120 , 0 , 1 ,0,0 };
struct ENEMY enemyBike = { true , 3 , 0 , 0 , -50 , 32 , 72 , 0 , 1 ,1,0 };
int mImageEnemy[ENEMY_IMAGE_MAX];
int EnemyCount[ENEMY_IMAGE_MAX];
//初期化
void Enemy_Initialize() {
	LoadDivGraph("images/car.png", 3, 3, 1, 63, 120, mImageEnemy); //エネミー画像
	mImageEnemy[3] = LoadGraph("images/bike.png"); //エネミー(バイク)
	// エネミーの初期設定
	for (int i = 0; i < ENEMY_MAX; i++) {
		mEnemy[i].flg = false;
	}
}
//終了処理
void Enemy_Finalize() {
	DeleteGraph(mImageEnemy[0]); //画像の解放
	DeleteGraph(mImageEnemy[1]); //画像の解放
	DeleteGraph(mImageEnemy[2]); //画像の解放
	DeleteGraph(mImageEnemy[3]); //画像の解放
}
//更新
void Enemy_Update() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (mEnemy[i].flg == true) {
			// 真っすぐ下に移動
			mEnemy[i].y += mEnemy[i].speed + mPlayer.speed - PLAYER_SPEED;
			//オートバイのジグザク走行
			if (mEnemy[i].type == 3 && ++mEnemy[i].cnt < 30) {
				mEnemy[i].x += mEnemy[i].mx;
			}
			else {
				mEnemy[i].x += mEnemy[i].mx * -1;
				if (mEnemy[i].cnt > 60) mEnemy[i].cnt = 0;
			}
			// 画面をはみ出したら消去
			if (mEnemy[i].y > SCREEN_HEIGHT + mEnemy[i].h) mEnemy[i].flg = FALSE;
			//敵車とのヒットチェック
			if (HitBoxPlayer(&mPlayer, &mEnemy[i]) == TRUE) {
				mPlayer.flg = false;
				mPlayer.speed = PLAYER_SPEED;
				mPlayer.count = 0;
				mPlayer.hp -= 20;
				mEnemy[i].flg = false;
			}
		}
	}
	// エネミーの生成
	if (mPlayer.mileage % ENEMY_CREATE_TIME == 0) {
		CreateEnemy();
	}
}
//描画
void Enemy_Draw() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (mEnemy[i].flg == true) {
			DrawRotaGraph(mEnemy[i].x, mEnemy[i].y, 1.0f, 0, mEnemy[i].img, TRUE, FALSE);
		}
	}
}
/**********************************
* エネミーの生成
* 引 数：なし
* 戻り値：TRUE:成功 FALSE:失敗 <---- 戻り値はあえて使わない。
 **********************************/
int CreateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (mEnemy[i].flg == FALSE) {
			mEnemy[i] = enemyCar;
			mEnemy[i].type = GetRand(3);
			if (mEnemy[i].type == 3) mEnemy[i] = enemyBike;
			mEnemy[i].img = mImageEnemy[mEnemy[i].type];
			mEnemy[i].x = GetRand(4) * 105 + 30 + GetRand(20);
			mEnemy[i].speed = 3 + mEnemy[i].type * 1;
			// 成功
			return TRUE;
		}
	}
	// 失敗
	return FALSE;
}
/**********************************
* 当たり判定（四角）
* 引 数：PLAYERポインタ, ENEMYポインタ
* 戻り値：TRUE:当たり, FALSE:なし
 **********************************/
int HitBoxPlayer(PLAYER* p, ENEMY* e)
{
	// x, y は中心座標とする
	int sx1 =p->x - (int)(p->w * 0.45f);
	int sy1 =p->y - (int)(p->h * 0.45f);
	int sx2 =p->x + (int)(p->w * 0.45f);
	int sy2 =p->y + (int)(p->h * 0.45f);
	int dx1 =e->x - (int)(e->w * 0.4f);
	int dy1 =		e->y - (int)(e->h * 0.4f);
	int dx2 =e->x + (int)(e->w * 0.4f);
	int dy2 =e->y + (int)(e->h * 0.4f);
	// 矩形が重なっていれば当たり
		if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
			return TRUE;
		}
	return FALSE;
}