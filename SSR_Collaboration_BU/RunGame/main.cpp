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
	const int x = 200,y = 200,r = 100,maxt = 330;
	const float move=4;

	std::vector<std::shared_ptr<BattleObject>> objects;
	std::vector< std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>>> spOFTVec;	//四分木に追加するオブジェクト

	//デモ用に円と四角形の物体を用意
	for (int i = 0; i < 2; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
			, (float)(i+1)*100, 500, -1, 0, GetColor(255, 255, 255), false)));
	}
	for (int i = 0; i < 1; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(100, 200))
			, (float)150 * (i+1), 10, -1, 0, GetColor(255, 255, 255), false)));
	}
	for (int i = 0; i < 2; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(200, 100))
			, (float)250 * (i+1), 80, -1, 0, GetColor(255, 255, 255), false)));
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
		return -1;
	}
	char key[256];

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//ゲーム本体
		//キー情報更新
		clsDx();
		t++;
		input_update();

		//再登録(移動を反映させるため)

		for (size_t count = 0; count < spOFTVec.size(); count++) {
			//i=cn
			BattleObject *pTmp = spOFTVec[count]->m_pObject;
			spOFTVec[count]->Remove();		// 一度リストから外れる
			// 再登録
			LTree.Regist(pTmp->getLeft(),pTmp->getTop(),pTmp->getRight(),pTmp->getBottom(), spOFTVec[count].get());
		}
		
		int ColNum = LTree.GetAllCollisionList(&ColVect)/2;

		//描画
		for (int i = 0; i < 5; i++) {
			//objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
			objects[i].get()->VDraw();
		}
		//あたり判定、出力
		BattleObject** pRoot = ColVect->getRootPtr();
		for (int i = 0; i < ColNum; i++) {
			if (pRoot[i * 2]->getHitJudgeShape()->HitJudge(pRoot[i*2+1]->getHitJudgeShape().get(),pRoot[i*2]->getPos(),pRoot[i*2+1]->getPos())) {
				printfDx("Hit\n");
			}
		}

		//計算処理
		//終了検出
		if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
			break;
		}
		Vector2D v = objects[0]->getPos();
		GetHitKeyStateAll(key);
		if (key[KEY_INPUT_DOWN] == 1) {
			objects[0].get()->Move(Vector2D(0,move));
		}
		if (key[KEY_INPUT_UP] == 1) {
			objects[0].get()->Move(Vector2D(0,-move));
		}
		if (key[KEY_INPUT_LEFT] == 1) {
			objects[0].get()->Move(Vector2D(-move,0));
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			objects[0].get()->Move(Vector2D(move,0));
		}
	}

	//入力関連のメモリ領域開放
	DeleteInputControler();

	DxLib_End();//DXライブラリ終了処理
	return 0;
}
