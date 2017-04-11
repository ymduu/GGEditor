#define _USE_MATH_DEFINES	//math.hの定数を使うために必須

#include<iostream>
#include"DxLib.h"

#include<math.h>
#include<memory>
#include<vector>
#include"input.h"
#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//画面モードの設定
	SetGraphMode(800, 600, 16);
	//タイトルメニュー文字
	SetMainWindowText("SSRunGame");
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
	*	以下、円軌道上に等速で直角三角形を描画して回すデモ
	*/

	//入力についての初期化
	InitInputControler();

	//描画させるものを宣言
	int t = 0;
	const int x = 200, y = 200, r = 100, maxt = 330;

	std::vector<std::shared_ptr<BattleObject>> objects;
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(45 + 20 * (i - 2)))
			, (float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI))
			, -1, 0, GetColor(255, 255, i * 50), false)));
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		t++;
		input_update();
		//描画
		for (int i = 0; i < 4; i++) {
			objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
			objects[i].get()->VDraw();
		}
		//計算処理
		//終了検出
		if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
			break;
		}
	}

	//入力関連のメモリ領域開放
	DeleteInputControler();

	DxLib_End();//DXライブラリ終了処理
	return 0;
}
