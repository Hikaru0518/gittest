#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Enemy.h"
#include "Player.h"
extern int HitBoxPlayer(PLAYER*, ENEMY*); //�����蔻��i�l�p�j
/*************************
** �ϐ� **
*************************/
// �G�l�~�[
struct ENEMY mEnemy[ENEMY_MAX];
struct ENEMY enemyCar = { true , 0 , 0 , 0 , -50 , 63 , 120 , 0 , 1 ,0,0 };
struct ENEMY enemyBike = { true , 3 , 0 , 0 , -50 , 32 , 72 , 0 , 1 ,1,0 };
int mImageEnemy[ENEMY_IMAGE_MAX];
int EnemyCount[ENEMY_IMAGE_MAX];
//������
void Enemy_Initialize() {
	LoadDivGraph("images/car.png", 3, 3, 1, 63, 120, mImageEnemy); //�G�l�~�[�摜
	mImageEnemy[3] = LoadGraph("images/bike.png"); //�G�l�~�[(�o�C�N)
	// �G�l�~�[�̏����ݒ�
	for (int i = 0; i < ENEMY_MAX; i++) {
		mEnemy[i].flg = false;
	}
}
//�I������
void Enemy_Finalize() {
	DeleteGraph(mImageEnemy[0]); //�摜�̉��
	DeleteGraph(mImageEnemy[1]); //�摜�̉��
	DeleteGraph(mImageEnemy[2]); //�摜�̉��
	DeleteGraph(mImageEnemy[3]); //�摜�̉��
}
//�X�V
void Enemy_Update() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (mEnemy[i].flg == true) {
			// �^���������Ɉړ�
			mEnemy[i].y += mEnemy[i].speed + mPlayer.speed - PLAYER_SPEED;
			//�I�[�g�o�C�̃W�O�U�N���s
			if (mEnemy[i].type == 3 && ++mEnemy[i].cnt < 30) {
				mEnemy[i].x += mEnemy[i].mx;
			}
			else {
				mEnemy[i].x += mEnemy[i].mx * -1;
				if (mEnemy[i].cnt > 60) mEnemy[i].cnt = 0;
			}
			// ��ʂ��͂ݏo���������
			if (mEnemy[i].y > SCREEN_HEIGHT + mEnemy[i].h) mEnemy[i].flg = FALSE;
			//�G�ԂƂ̃q�b�g�`�F�b�N
			if (HitBoxPlayer(&mPlayer, &mEnemy[i]) == TRUE) {
				mPlayer.flg = false;
				mPlayer.speed = PLAYER_SPEED;
				mPlayer.count = 0;
				mPlayer.hp -= 20;
				mEnemy[i].flg = false;
			}
		}
	}
	// �G�l�~�[�̐���
	if (mPlayer.mileage % ENEMY_CREATE_TIME == 0) {
		CreateEnemy();
	}
}
//�`��
void Enemy_Draw() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (mEnemy[i].flg == true) {
			DrawRotaGraph(mEnemy[i].x, mEnemy[i].y, 1.0f, 0, mEnemy[i].img, TRUE, FALSE);
		}
	}
}
/**********************************
* �G�l�~�[�̐���
* �� ���F�Ȃ�
* �߂�l�FTRUE:���� FALSE:���s <---- �߂�l�͂����Ďg��Ȃ��B
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
			// ����
			return TRUE;
		}
	}
	// ���s
	return FALSE;
}
/**********************************
* �����蔻��i�l�p�j
* �� ���FPLAYER�|�C���^, ENEMY�|�C���^
* �߂�l�FTRUE:������, FALSE:�Ȃ�
 **********************************/
int HitBoxPlayer(PLAYER* p, ENEMY* e)
{
	// x, y �͒��S���W�Ƃ���
	int sx1 =p->x - (int)(p->w * 0.45f);
	int sy1 =p->y - (int)(p->h * 0.45f);
	int sx2 =p->x + (int)(p->w * 0.45f);
	int sy2 =p->y + (int)(p->h * 0.45f);
	int dx1 =e->x - (int)(e->w * 0.4f);
	int dy1 =		e->y - (int)(e->h * 0.4f);
	int dx2 =e->x + (int)(e->w * 0.4f);
	int dy2 =e->y + (int)(e->h * 0.4f);
	// ��`���d�Ȃ��Ă���Γ�����
		if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
			return TRUE;
		}
	return FALSE;
}