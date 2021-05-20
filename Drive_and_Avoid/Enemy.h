#pragma once

#define PI 3.1415926535897932384626433832795f
/*************************
** �萔 **
*************************/
// �G�@�̍ő吔
const int ENEMY_MAX = 6;
const int ENEMY_IMAGE_MAX = 4;
const int ENEMY_CREATE_TIME = 200;
/*************************
** �\���� **
*************************/
// �G�@�̍\����
struct ENEMY
{
	bool flg; // �g�p�t���O
	int type; // �^�C�v
	int img; // �摜
	int x, y, w, h; // ���Wx,y��w����h
		int speed; // �ړ����x
	int point; // �X�R�A���Z
	int mx;
	int cnt;
};
extern struct ENEMY mEnemy[ENEMY_MAX]; //�G�ԃp�����[�^
extern int mImageEnemy[ENEMY_IMAGE_MAX]; //�G�ԉ摜
extern int EnemyCount[ENEMY_IMAGE_MAX]; //
extern void Enemy_Initialize();//������
extern void Enemy_Finalize();//�I������
extern void Enemy_Update();//�X�V
extern void Enemy_Draw();//�`��
extern int CreateEnemy(); //�G�Ԃ̐���
//extern int HitBoxPlayer(PLAYER*, ENEMY*); //�����蔻��i�l�p�j