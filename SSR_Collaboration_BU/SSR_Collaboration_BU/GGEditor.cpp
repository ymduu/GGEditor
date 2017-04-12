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
	:m_actionSettings(std::shared_ptr<EditAction>(nullptr)
		,std::weak_ptr<BattleObject>(std::shared_ptr<BattleObject>(nullptr))
		,std::shared_ptr<PosSetting>(nullptr))
{
	
}

GGEditor::~GGEditor() {}

//マウスを左クリックした時の動作
void GGEditor::ProcessMapPush(int mouseX,int mouseY){
	//ゲーム画面上の座標に変換(残りは描画補正値m_adjustのみを適用すればよい)
	mouseX-=leftUpPosX;
	mouseY-=leftUpPosY;
	//動作
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
			,((float)mouseX)+m_actionSettings.GetMAdjust().x
			,((float)mouseY)+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
}

//毎ループ動作部分の関数
int GGEditor::Calculate() {
	//マウスの位置計算
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//マウス入力受付
	//左クリックをされたら
	if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
		//マップ画面内にマウスがある場合
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			ProcessMapPush(mouseX,mouseY);
		}
	} else if(mouseX>=0 && mouseX<leftUpPosX*2+mapSizeX && mouseY>=0 && mouseY<leftUpPosY*2+mapSizeY){
		//マップ画面(この場合は上に当てはまるのでありえない)かスクロールバーにマウスがある場合
		float scroll=0;//スクロールするピクセル数
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			scroll=5;
		} else if(mouse_get(MOUSE_INPUT_LEFT)>30){
			scroll=20;
		}
		m_actionSettings.PushScrollBar(scroll,2000,2000,mouseX,mouseY,leftUpPosX,leftUpPosY,mapSizeX,mapSizeY);
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
		//更に斜め線も
		DrawLine(0,0,leftUpPosX,leftUpPosY,GetColor(0,0,0));//左上
		DrawLine(0,leftUpPosY*2+mapSizeY,leftUpPosX,leftUpPosY+mapSizeY,GetColor(0,0,0));//左下
		DrawLine(leftUpPosX*2+mapSizeX,0,leftUpPosX+mapSizeX,leftUpPosY,GetColor(0,0,0));//右上
		DrawLine(leftUpPosX+mapSizeX,leftUpPosY+mapSizeY,leftUpPosX*2+mapSizeX,leftUpPosY*2+mapSizeY,GetColor(0,0,0));//右下
	}
	//マップの描画
	//マップ描画出来る範囲を制限
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	for (std::shared_ptr<BattleObject> obj : m_objects) {
		obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
	}
	SetDrawAreaFull();
	//入力されている動作のボタンの描画

	//右側の作業フレームの描画

}
