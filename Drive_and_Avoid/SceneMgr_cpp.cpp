#include "DxLib.h"
#include"Game.h"
#include"Menu.h"
#include "Help.h"
#include "End.h"
#include "SceneMgr.h"

static eScene mScene = eScene_Menu; //�V�[���Ǘ��ϐ�
static eScene mNextScene = eScene_None; //���̃V�[���Ǘ��ϐ�

static void SceneMgr_InitializeModule(eScene scene);//�w�胂�W���[��������������
static void SceneMgr_FinalizeModule(eScene scene);//�w�胂�W���[���̏I���������s��

//������
void SceneMgr_Initialize() {
	SceneMgr_InitializeModule(mScene);
}

//�I������
void SceneMgr_Finalize() {
	SceneMgr_FinalizeModule(mScene);
}

//�X�V
void SceneMgr_Update() {
	if (mNextScene != eScene_None) {//���̃V�[�����Z�b�g����Ă�����
		SceneMgr_FinalizeModule(mScene);//���݂̃V�[���̏I�����������s
		mScene = mNextScene;//���̃V�[�������݂̃V�[���Z�b�g
		mNextScene = eScene_None;  //���̃V�[�������N���A
		SceneMgr_InitializeModule(mScene);  //���݂̃V�[����������
	}
	switch (mScene) {
	case eScene_Menu:
		Menu_Update();
		break;
	case eScene_Game:
		Game_Update();
		break;
	case eScene_Help:
		Help_Update();
		break;
	case eScene_End:
		break;
}
}

//�`��
void SceneMgr_Draw() {
	switch (mScene) {
	case eScene_Menu:
		Menu_Draw();
		break;
	case eScene_Game:
		Game_Draw();
		break;
	case eScene_Help:
		Help_Draw();
		break;
	case eScene_End:
		End_Draw();
		break;
	}
}

//����nextScene�ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
	mNextScene = NextScene; //���̃V�[�����Z�b�g����
}

//����scene���W���[��������������
static void SceneMgr_InitializeModule(eScene scene) {
	switch (scene) {
	case eScene_Menu:
			Menu_Initialize();
			break;
	case eScene_Game:
			Game_Initialize();
			break;
	case eScene_Help:
		Help_Initialize();
		break;
	case eScene_End:
		End_Initialize();
		break;
	}
}

//����scene���W���[���̏I���������s��
static void SceneMgr_FinalizeModule(eScene scene) {
	switch (scene) {
	case eScene_Menu:
			Menu_Finalize();
			break;
	case eScene_Game:
			Game_Finalize();
			break;
	case eScene_Help:
		Help_Finalize();
		break;
	case eScene_End:
		End_Finalize();
		break;
	}
}


int SceneMgr_GameEnd_Status() {
	if (mScene == eScene_End) {
		return 1;
	}
	else {
		return 0;
	}
}