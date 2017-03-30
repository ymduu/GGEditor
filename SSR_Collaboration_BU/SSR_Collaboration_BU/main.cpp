#include<iostream>
#include"DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//画面モードの設定
	SetGraphMode(800,600,16);
	//タイトルメニュー文字
	SetMainWindowText("うえぽんでこれーしょん！");
	//ウインドウサイズの変更
	SetWindowSizeExtendRate(1.0);
	//ウインドウサイズの変更をできるようにする
	SetWindowSizeChangeEnableFlag(TRUE);
	//アイコンの設定
	SetWindowIconID(101);

	if (ChangeWindowMode(TRUE) != 0) {
		return 0;
	}
	if (DxLib_Init() != 0) {
		return 0;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		DxLib_End();
		return 0;
	}


	WaitKey();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		//描画
		//計算処理
		//終了検出
		if(true){
			break;
		}
	}

	DxLib_End();//DXライブラリ終了処理
	return 0;
}
