#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Player.h"
/*************************
** �ϐ� **
*************************/
// ���@
struct PLAYER mPlayer;
static int mImagePlayer; //�摜�n���h���i�[�p�ϐ�
//������
void Player_Initialize() {
	mImagePlayer = LoadGraph("images/pleyer.png"); //�摜�̃��[�h
		//// �v���C���[�̏����ݒ�
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
//�I������
void Player_Finalize() {
	DeleteGraph(mImagePlayer); //�摜�̉��
}
//�X�V
void Player_Update() {
	//�v���C���[�i���ԁj�̉����E����
		// A�L�[�ŉ���
		if (iKeyFlg & PAD_INPUT_A && mPlayer.speed < 11) mPlayer.speed++;
	// X�L�[�Ō���
		if (iKeyFlg & PAD_INPUT_C && mPlayer.speed > 1) mPlayer.speed--;
	//�v���C���[�i���ԁj�̍��E�ړ�
		if (iNowKey & PAD_INPUT_LEFT
			) mPlayer.x -= PLAYER_SPEED;
	if (iNowKey & PAD_INPUT_RIGHT
		) mPlayer.x += PLAYER_SPEED;
	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
		if (mPlayer.x < 40) mPlayer.x = 40;
	if (mPlayer.x > SCREEN_WIDTH - 180) mPlayer.x = SCREEN_WIDTH - 180;
}
//�`��
void Player_Draw() {
	// �v���C���[�̕\��
	if (mPlayer.flg) { //�ʏ�̕\��
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
	else { //�Ԃ������Ƃ��̕\��
		if (++mPlayer.count >= 80) mPlayer.flg = true;
		if (mPlayer.count / 5 % 2 == 0) {
			DrawRotaGraph(mPlayer.x, mPlayer.y, 1.0f, 0, mImagePlayer, TRUE, FALSE);
		}
	}
}