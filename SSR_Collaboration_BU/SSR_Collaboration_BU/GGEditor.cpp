#define _USE_MATH_DEFINES	//math.hの定数を使うために必須

#include<math.h>

#include"DxLib.h"
#include"GGEditor.h"
#include"input.h"

#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"

#include"EditPut.h"
#include"EditRemove.h"
#include"EditMove.h"
#include"EditResize.h"

#include"RectangleFactory.h"

#include"ScrollBar.h"

//定数の定義
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;
const int GGEditor::buttonHeight=(leftUpPosY*2+mapSizeY)/4;
const int GGEditor::shapeButtonHeightNum=1;
const int GGEditor::shapeButtonWidthNum=3;
const int GGEditor::shapeButtonHeight=GGEditor::buttonHeight/2;
const int GGEditor::shapeButtonWidth=GGEditor::buttonWidth;
const std::string GGEditor::actButtonStr[actButtonHeightNum*actButtonWidthNum]={"put","remove","move","expand"};

//関数定義
//静的関数
std::shared_ptr<EditAction> GGEditor::EditPutFactory(){
	return std::shared_ptr<EditAction>(new EditPut(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0,0,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditRemoveFactory(){
	return std::shared_ptr<EditAction>(new EditRemove(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1,0,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditMoveFactory(){
	return std::shared_ptr<EditAction>(new EditMove(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0,buttonHeight/actButtonHeightNum*1,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditResizeFactory(){
	return std::shared_ptr<EditAction>(new EditResize(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1,buttonHeight/actButtonHeightNum*1,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

//動的関数
GGEditor::GGEditor()
	:m_actionSettings(
		//EditPutFactory()
		std::shared_ptr<EditAction>(nullptr)
		,std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false))
		//,std::shared_ptr<ShapeFactory>(new RectangleFactory(Vector2D((float)(leftUpPosX*2+mapSizeX+shapeButtonWidth/shapeButtonWidthNum*0),(float)(buttonHeight+shapeButtonHeight/shapeButtonHeightNum*0)),Vector2D((float)(shapeButtonWidth/shapeButtonWidthNum),(float)(shapeButtonHeight/shapeButtonHeightNum)),GetColor(255,255,0)))
		,std::shared_ptr<ShapeFactory>(nullptr)
		,std::shared_ptr<PosSetting>(nullptr))
{
	//ボタン一覧
	
	//最初から押されているようにするボタンをリストアップしながら行う
	std::shared_ptr<ButtonHaving::Button> pPutButton,pRectangleFactoryButton;
	
	//上スクロールボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D(0,0)
		,Vector2D((float)(leftUpPosX*2+mapSizeX),0)
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)leftUpPosY)
		,Vector2D((float)leftUpPosX,(float)leftUpPosY)
		,Vector2D(0,-1)
	)));
	//左スクロールボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D(0,0)
		,Vector2D((float)leftUpPosX,(float)leftUpPosY)
		,Vector2D((float)leftUpPosX,(float)(leftUpPosY+mapSizeY))
		,Vector2D(0,(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(-1,0)
	)));
	//右スクロールボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX),0)
		,Vector2D((float)(leftUpPosX*2+mapSizeX),(float)(leftUpPosY*2+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)leftUpPosY)
		,Vector2D(1,0)
	)));
	//下スクロールボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D((float)leftUpPosX,(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX*2+mapSizeX),(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(0,(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(0,1)
	)));

	//putボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditPut::EditPutButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0),0)
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	pPutButton=m_buttons.back();//最初から押されているようにするボタン
	//removeボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditRemove::EditRemoveButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1),0)
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	//moveボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditMove::EditMoveButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0),(float)(buttonHeight/actButtonHeightNum*1))
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	//resizeボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditResize::EditResizeButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1),(float)(buttonHeight/actButtonHeightNum*1))
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));

	//RectangleFactoryボタン
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new RectangleFactory::RectangleFactoryButton(
		Vector2D(
			(float)(leftUpPosX*2+mapSizeX+shapeButtonWidth/shapeButtonWidthNum*0)
			,(float)(buttonHeight+shapeButtonHeight/shapeButtonHeightNum*0)
		)
		,Vector2D((float)(shapeButtonWidth/shapeButtonWidthNum),(float)(shapeButtonHeight/shapeButtonHeightNum))
	)));
	pRectangleFactoryButton=m_buttons.back();//最初から押されているようにする

	//最初から押されているようにするボタンを押す(順番に注意！)
	pRectangleFactoryButton->PushedProcess(m_actionSettings);
	pPutButton->PushedProcess(m_actionSettings);
	
	//フォント
	m_font=CreateFontToHandle("メイリオ",16,1);

	
}

GGEditor::~GGEditor() {
	//フォント
	DeleteFontToHandle(m_font);
}

//マウスを左クリックした時の動作群
void GGEditor::ProcessMapPush(int mouseX,int mouseY){
	//ゲーム画面上の座標に変換(残りは描画補正値m_adjustのみを適用すればよい)
	mouseX-=leftUpPosX;
	mouseY-=leftUpPosY;
	//動作
	m_actionSettings.PracticeEdit(Vector2D((float)mouseX,(float)mouseY));
}

//常に行う編集行為
void GGEditor::NonPressEdit(int mouseX,int mouseY){
	//ゲーム画面上の座標に変換(残りは描画補正値m_adjustのみを適用すればよい)
	mouseX-=leftUpPosX;
	mouseY-=leftUpPosY;
	//動作
	m_actionSettings.PracticeNonPressEdit(Vector2D((float)mouseX,(float)mouseY));
}

//毎ループ動作部分の関数
int GGEditor::Calculate() {
	//マウスの位置計算
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//マウス入力受付
	NonPressEdit(mouseX,mouseY);

	//ボタン群の入力判定
	for(std::shared_ptr<ButtonHaving::Button> &pb:m_buttons){
		if(pb.get()->JudgeButtonPushed() && pb.get()->JudgeInButton(GetMousePointVector2D())){
			pb.get()->PushedProcess(m_actionSettings);
			break;
		}
	}

	//左クリックをされたら
	if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
		//マップ画面内にマウスがある場合
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			ProcessMapPush(mouseX,mouseY);
		}
	}

	//キーボード入力受付
	if(keyboard_get(KEY_INPUT_NUMPADENTER) == 1){
		return -1;
	}
	return 0;
}

void GGEditor::Draw() {
	//デバッグ描画
	clsDx();
	printfDx("(%f,%f)\n",GetMousePointVector2D().x,GetMousePointVector2D().y);
	for(auto o:*m_actionSettings.GetPMObject()){
		printfDx("%d\n",o.get());
	}
	printfDx("m_pBattleObject:%d\n",m_actionSettings.m_pBattleObject.get());

	//マップの描画
	//マップ描画出来る範囲を制限
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	//マップ全体の描画
	bool firstflag=true;
	Vector2D mouse=GetMousePointVector2D()-Vector2D((float)leftUpPosX,(float)leftUpPosY)+m_actionSettings.GetMAdjust();//マウスの位置(補正値を考慮しマップ上の座標で表す)
	Vector2D adjust=Vector2D((float)leftUpPosX,(float)leftUpPosY)-m_actionSettings.GetMAdjust();//描画の全体調整位置
	//現在の編集対象図形を描画
	if(m_actionSettings.m_pBattleObject.get()!=nullptr){
		int mode,pal;
		GetDrawBlendMode(&mode,&pal);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		m_actionSettings.m_pBattleObject.get()->VDraw(adjust);
		SetDrawBlendMode(mode,pal);
	}
	//マップに存在しているものを全て描画
	for (const std::shared_ptr<BattleObject> &obj : *m_actionSettings.GetPMObject()) {
		//obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
		obj.get()->VDraw(adjust);
		//マウスが被っている図形には黄色い枠を描画しフォーカスを表現
		if(firstflag && obj.get()->JudgePointInsideShape(mouse)){
			obj.get()->ShapeDraw(GetColor(255,255,0),FALSE,(int)(adjust.x),(int)(adjust.y));
			obj.get()->PosDraw(GetColor(255,255,0),TRUE,2,(int)(adjust.x),(int)(adjust.y));
			firstflag=false;
		}
		//選択中の図形については赤い枠を描画しフォーカスを表現
		if(obj.get()==m_actionSettings.m_pBattleObject.get()){
			obj.get()->ShapeDraw(GetColor(255,0,0),FALSE,(int)(adjust.x),(int)(adjust.y));
			obj.get()->PosDraw(GetColor(255,0,0),TRUE,2,(int)(adjust.x),(int)(adjust.y));
		}
	}
	
	//編集前のBattleObjectをマップに仮想的に描画
	if(m_actionSettings.GetMPOriginObject()!=nullptr){
		int mode,pal;
		GetDrawBlendMode(&mode,&pal);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		m_actionSettings.GetMPOriginObject()->VDraw(adjust);
		SetDrawBlendMode(mode,pal);
	}
	SetDrawAreaFull();

	//入力されている動作のボタンの描画
	m_actionSettings.DrawEditButtonPushed();

	//入力されている図形設定ボタンの描画
	m_actionSettings.DrawShapeFactoryButtonPushed();
	
	//ボタン群の描画
	for(std::shared_ptr<ButtonHaving::Button> &pb:m_buttons){
		pb.get()->ButtonDraw(m_font,TRUE);
	}


}
