#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include "Input.h"

#define PI 3.1415926535897932384626433832795f

static int mImageHandle;  //�摜�n���h���i�[�p�ϐ�
static int mImageMenu;
static int mImageCone;

static int MenuNumber = 0;

//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Menu.png");  //�摜�̃��[�h
	mImageMenu = LoadGraph("images/menu.png");
	mImageCone = LoadGraph("images/cone.png");
}

//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle);  //�摜�̉��
	DeleteGraph(mImageMenu);
	DeleteGraph(mImageCone);
}

//�X�V
void Menu_Update() {

	if (iKeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNumber > 2)MenuNumber = 0;
	}
	if (iKeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0)MenuNumber = 2;
	}

	if (iKeyFlg == PAD_INPUT_1) {
		switch (MenuNumber) {
		case 0:
			SceneMgr_ChangeScene(eScene_Game);
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Help);
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_End);
			break;
		}
	}
}


void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);


	DrawGraph(120, 240, mImageMenu, TRUE);

	DrawRotaGraph(90, 260 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);
}