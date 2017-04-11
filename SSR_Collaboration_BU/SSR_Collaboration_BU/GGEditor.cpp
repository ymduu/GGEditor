#define _USE_MATH_DEFINES	//math.hの定数を使うために必須

#include<math.h>

#include"DxLib.h"
#include"GGEditor.h"

#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"
#include"input.h"

//定数の定義
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;

//関数定義
GGEditor::GGEditor()
	:m_actionSettings(Vector2D(25, 25)
		, std::shared_ptr<EditAction>(nullptr)
		,std::weak_ptr<BattleObject>(std::shared_ptr<BattleObject>(nullptr))
		,std::shared_ptr<PosSetting>(nullptr))
{
	
}

GGEditor::~GGEditor() {}

int GGEditor::Calculate() {
	//マウスの位置計算
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//マウス入力受付
	if (mouse_get(MOUSE_INPUT_LEFT)==1) {
		//左クリックをされたら
		if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
			//マップ画面が押された場合
			m_objects.push_back(std::shared_ptr<BattleObject>(
				new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
					,(float)mouseX,(float)mouseY,-1,0,GetColor(128,128,128),false)
				));
		}
	}
	//キーボード入力受付
	if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
		return -1;
	}
	return 0;
}

void GGEditor::Draw() {
	//マップ周りのスクロールボタンの描画
	{
		//ひとまず中抜き長方形の描画とする
		int r,g,b;
		GetBackgroundColor(&r,&g,&b);
		DrawBox(0,0,leftUpPosX*2+mapSizeX,leftUpPosY*2+mapSizeY,GetColor(192,192,192),TRUE);
		DrawBox(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX,leftUpPosY+mapSizeY,GetColor(r,g,b),TRUE);
	}
	//マップの描画
	//マップ描画出来る範囲を制限
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	for (std::shared_ptr<BattleObject> obj : m_objects) {
		obj.get()->VDraw();
	}
	SetDrawAreaFull();
	//入力されている動作のボタンの描画

	//右側の作業フレームの描画

}
