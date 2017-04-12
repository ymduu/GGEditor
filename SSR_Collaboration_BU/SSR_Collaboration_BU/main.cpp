#include<iostream>
#include<memory>
#include"DxLib.h"
#include"input.h"
#include"GGEditor.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//画面モードの設定
	SetGraphMode(GGEditor::leftUpPosX*2+GGEditor::mapSizeX+GGEditor::buttonWidth, GGEditor::leftUpPosY * 2 + GGEditor::mapSizeY,16);
	//タイトルメニュー文字
	SetMainWindowText("GGEditor");
	//ウインドウサイズの変更
	SetWindowSizeExtendRate(1.0);
	//ウインドウサイズの変更をできるようにしない
	SetWindowSizeChangeEnableFlag(FALSE);
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

	/**
	*	以下、円軌道上に等速で直角三角形を描画して回すデモ
	*/

	//入力についての初期化
	InitInputControler();

	std::shared_ptr<GGEditor> ggEditor(new GGEditor());
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		input_update();
		//描画
		ggEditor->Draw();
		//計算処理
		int index = ggEditor->Calculate();
		//終了検出
		if(index<0){
			break;
		}
	}

	//入力関連のメモリ領域開放
	DeleteInputControler();

	DxLib_End();//DXライブラリ終了処理
	return 0;
}
