#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("Drive_and_Avoid");
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SceneMgr_Initialize();

	while(ProcessMessage() == 0){

		if (SceneMgr_GameEnd_Status()) {
			break;
		}

		ClearDrawScreen();

		InputKey();

		SceneMgr_Update();
		SceneMgr_Draw();

		ScreenFlip();
	}

	SceneMgr_Finalize();

	DxLib_End();
	return 0;
}