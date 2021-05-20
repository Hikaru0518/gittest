#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;
static int StopTime;

//������
void End_Initialize(){
	mImageHandle = LoadGraph("images/Scene_End.png");
	StopTime = 0;
}

//�I������
void End_Finalize() {
	DeleteGraph(mImageHandle);
}

//�X�V

//�`��
void End_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//�^�C���̉��Z�������I���i3�b��j
	if (++StopTime > 180) {
		SceneMgr_ChangeScene(eScene_Stop);
	}
}