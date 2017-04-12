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
#include "libQTree.h"

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
	VECTOR po,poi;

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
	const int x = 200, y = 200, r = 100, maxt = 330 ,move=4;

	std::vector<std::shared_ptr<BattleObject>> objects;
	std::vector< std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>>> spOFTVec;	//四分木に追加するオブジェクト

	//デモ用に円と四角形の物体を用意
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
			, (i+1)*100, 300, -1, 0, GetColor(255, 255, 255), false)));
	}
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(100, 200))
			, 150 * i, 10, -1, 0, GetColor(255, 255, 255), false)));
	}
	//4分木に追加、shared_ptrが持つ生ポインタは指す先が変化しないことを前提としている(大丈夫か？)
	for (std::shared_ptr<BattleObject> sp : objects) {
		std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>> newObj = std::make_shared<IKD::OBJECT_FOR_TREE<BattleObject>>(0);
		newObj->m_pObject = sp.get();
		spOFTVec.push_back(newObj);
	}
	
	IKD::CLiner4TreeManager<BattleObject> LTree;
	IKD::CollisionList<BattleObject>* ColVect;		
	if (!LTree.Init(8, 0.0, 0.0, 800.0, 600.0))
	{
		MessageBox(NULL, _T("線形4分木空間の初期化に失敗しました。"), NULL, NULL);
		return;
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		t++;
		input_update();

		//再登録(移動を反映させるため)

		for (size_t count = 0; count < spOFTVec.size(); count++) {
			//i=cn
			BattleObject *pTmp = spOFTVec[count]->m_pObject;
			spOFTVec[count]->Remove();		// 一度リストから外れる
			// 再登録
			LTree.Regist(pTmp->x - pTmp->r, pTmp->y - pTmp->r, pTmp->x + pTmp->r, pTmp->y + pTmp->r, spOFTVec[count].get());
		}
		
		//描画
		for (int i = 0; i < 8; i++) {
			//objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
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
