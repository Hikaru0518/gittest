#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
/*************************
** �ϐ� **
*************************/
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //�摜�̃��[�h
	Player_Initialize(); //�v���C���[�i���ԁj�̏�����
	Enemy_Initialize(); //�G�Ԃ̏�����
}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
	Player_Finalize(); // �v���C���[�i���ԁj�̊J��
	Enemy_Finalize(); //�G�Ԃ̊J��
}
//�X�V
void Game_Update() {
	//B�{�^���܂���ESC�{�^���Ń��j���[�ɖ߂�
	if (iKeyFlg == PAD_INPUT_B || (CheckHitKey(KEY_INPUT_ESCAPE) != 0)) {
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	Player_Update();
	Enemy_Update();
}
//�`��
void Game_Draw() {
	//�w�i(�R�[�X)�̕`�揈��
	BackScrool();
	//�G�ԁA�v���C���[�̕`�揈��
	Player_Draw();
	Enemy_Draw();
}
/**********************************
* �w�i�摜�X�N���[������
* �� ���F�Ȃ�
* �߂�l�F�Ȃ�
 **********************************/
void BackScrool(void)
{
	//�X�N���[���̃X�s�[�h��ݒ�
	mPlayer.mileage += mPlayer.speed;
	//�X�N���[���摜�\��
	DrawGraph(0, mPlayer.mileage % 480 - 480, mImageHandle, FALSE);
	DrawGraph(0, mPlayer.mileage % 480, mImageHandle, FALSE);
}