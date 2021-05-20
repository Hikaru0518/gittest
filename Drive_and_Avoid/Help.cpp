#include "Help.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle;

//������
void Help_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Menu.png");

}

//�I������
void Help_Finalize() {
	DeleteGraph(mImageHandle);

}

//�X�V
void Help_Update() {
	if (iKeyFlg == PAD_INPUT_2) {
		SceneMgr_ChangeScene(eScene_Menu);
	}
}

//�`��
void Help_Draw(){
	DrawGraph(0,0,mImageHandle,FALSE);

	SetFontSize(16);
	DrawString(20, 120, "�w���v���", 0xffffff, 0);

	DrawString(20,160, "����͏�Q��������Ȃ���", 0xffffff, 0);
	DrawString(20, 180, "���葱����Q�[���ł�", 0xffffff, 0);
	DrawString(20, 200, "�R�����s���邩�A��Q����", 0xffffff, 0);
	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł�", 0xffffff, 0);

	DrawString(20, 450, "----�@�X�y�[�X�L�[�������ă^�C�g���֖߂�@----", 0xffffff, 0);
}