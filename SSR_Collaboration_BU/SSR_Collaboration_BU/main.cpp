#define _USE_MATH_DEFINES	//math.hの定数を使うために必須

#include<iostream>
#include<boost\shared_ptr.hpp>
#include"DxLib.h"

#include<math.h>
#include"input.h"
#include"Terrain.h"
#include"MyRectangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//画面モードの設定
	SetGraphMode(800,600,16);
	//タイトルメニュー文字
	SetMainWindowText("SSR_Collaboration_BU");
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

	/**
	*	以下、円軌道上に等速で長方形を描画して回すデモ
	*/

	//入力についての初期化
	InitInputControler();

	//描画させるものを宣言
	int t = 0;
	const int x = 200, y = 200, r = 100,maxt=330;
	Terrain t1(boost::shared_ptr<MyShape>(new MyRectangle(50,20))
		, x + r*cos((double)t / maxt*M_PI), y + r*sin((double)t / maxt*M_PI)
		,-1,0,GetColor(255,0,0),false);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		t++;
		keyboard_update();
		//描画
		t1.Move(x + r*cos((double)t / maxt*M_PI), y + r*sin((double)t / maxt*M_PI));
		t1.VDraw();
		//計算処理
		//終了検出
		if(keyboard_get(KEY_INPUT_NUMPADENTER)==1){
			break;
		}
	}

	DxLib_End();//DXライブラリ終了処理
	return 0;
}
