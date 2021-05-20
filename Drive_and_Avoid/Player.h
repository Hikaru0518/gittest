#pragma once

#define PI 3.1415926535897932384626433832795f
/*************************
** �萔 **
*************************/
// ��ʗ̈�̑傫��
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
** �\���� **
*************************/
// �v���C���[
struct PLAYER
{
	bool flg; // ���Ԃ̏�ԃt���O
		int x, y; // ���Wx,y
	int w, h; // ��w����h
		double angle; // �@�̂̌���
		int count; // ���ԕ\���p�J�E���^�[
	int speed; // �ړ����x
	int hp; // �̗�
	double fuel; // �R��
	int mileage; // ���s����
};
extern struct PLAYER mPlayer;
extern void Player_Initialize();//������
extern void Player_Finalize();//�I������
extern void Player_Update();//�X�V
extern void Player_Draw();//�`��