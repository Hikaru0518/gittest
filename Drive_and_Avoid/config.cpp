#include"Config.h"
#include"SceneMgr.h"
#include"DxLib.h"

static int mImageHandle;

//������
void Config_Initialize() {
	mImageHandle = LoadGraph("images1/Scene_Config.bmp");
}

//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);
}

//�X�V
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
		SceneMgr_ChangeScene(eScene_Menu);
	}
}


void Config_Draw() {
	DrawGraph(0, 0,mImageHandle, FALSE);
	DrawString(20, 380,"�ݒ��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(136, 136, 255));
}