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

	const int x = 200, y = 200, r = 100, maxt = 330 ,move=4;
	const float accel = 0.2f ,maxVel=4.0f;
	Vector2D Vel(0.0f, 0.0f);

	std::vector<std::shared_ptr<BattleObject>> objects;
	std::vector< std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>>> spOFTVec;	//四分木に追加するオブジェクト

	//デモ用に円と四角形の物体を用意、見栄えがいいように配置
	for (int i = 0; i < 1; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
			, (float)(i+1)*100, 500, -1, 0, GetColor(255, 255, 255), false)));
	}
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(800, 30))
		, 0, 570, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(150, 30))
		, 40, 200, -1, 0, GetColor(255, 255, 255), false)));

	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(150, 30))
		, 530, 150, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(800, 30))
		, 0, 570, -1, 0, GetColor(255, 255, 255), false)));

	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-200, -100))
		, 230, 110, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(200, -100))
		, 570, 110, -1, 0, GetColor(255, 255, 255), false)));

	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-300, -300))
		, 800, 500, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(300, -300))
		, 0, 500, -1, 0, GetColor(255, 255, 255), false)));
	
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
		, 200, 300, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
		, 290, 300, -1, 0, GetColor(255, 255, 255), false)));
	objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
		, 370, 300, -1, 0, GetColor(255, 255, 255), false)));

	objects[0]->fixFlag = true;
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
		for (size_t i = 0; i < objects.size();i++) {
			//objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
			objects[i].get()->VDraw(Vector2D(0,0));
		}

		//移動させる
		Vector2D v = objects[0]->getPos();
		GetHitKeyStateAll(key);

		if (key[KEY_INPUT_DOWN] == 1) {
			//objects[0].get()->Move(v.x, v.y + move);
			Vel.y += accel;
			if (Vel.sqSize() > maxVel*maxVel) {
				Vel = Vel.norm()*maxVel;
			}
		}
		if (key[KEY_INPUT_UP] == 1) {
			//objects[0].get()->Move(v.x, v.y - move);
			Vel.y -= accel;
			if (Vel.sqSize() > maxVel*maxVel) {
				Vel = Vel.norm()*maxVel;
			}
		}
		if (key[KEY_INPUT_LEFT] == 1) {
			//objects[0].get()->Move(v.x - move, v.y);
			Vel.x -= accel;
			if (Vel.sqSize() > maxVel*maxVel) {
				Vel = Vel.norm()*maxVel;
			}
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			//objects[0].get()->Move(v.x + move, v.y);
			Vel.x += accel;
			if (Vel.sqSize() > maxVel*maxVel) {
				Vel = Vel.norm()*maxVel;
			}
		}

		Vel.y += 0.05f;
		if (Vel.sqSize() > maxVel*maxVel) {
			Vel = Vel.norm()*maxVel;
		}

		objects[0].get()->Move(Vector2D(Vel.x,Vel.y));
		Vel = Vel*0.99;
		//あたり判定、出力
		Vector2D fix(0.0f, 0.0f);
		v = objects[0]->getPos();
		BattleObject** pRoot = ColVect->getRootPtr();
		for (int i = 0; i < ColNum; i++) {
			MyShape::HitInfo res = pRoot[i * 2]->getHitJudgeShape()->HitJudge(pRoot[i * 2 + 1]->getHitJudgeShape().get(), pRoot[i * 2]->getPos(), pRoot[i * 2 + 1]->getPos());
			if (pRoot[i * 2 + 1]->fixFlag) {
				res = pRoot[i * 2+1]->getHitJudgeShape()->HitJudge(pRoot[i * 2 ]->getHitJudgeShape().get(), pRoot[i * 2+1]->getPos(), pRoot[i * 2 ]->getPos());
			}
			if (res.judge) {
				printfDx("Hit\n");
				fix = fix + res.fixVec;
			}
		}
		objects[0].get()->Move(fix);

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
