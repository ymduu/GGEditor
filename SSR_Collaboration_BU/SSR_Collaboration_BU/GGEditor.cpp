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

//定数の定義
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;
const int GGEditor::buttonHeight=(leftUpPosY*2+mapSizeY)/4;
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


//動的関数
GGEditor::GGEditor()
	:m_actionSettings(EditPutFactory()
		,std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false))
		,std::shared_ptr<PosSetting>(nullptr))
{
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
	} else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseY>=0 && mouseY<buttonHeight/actButtonHeightNum*1){
		//設置ボタンにマウスがある場合
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.m_pEditAction=EditPutFactory();
			m_actionSettings.m_pBattleObject=std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false));
		}
	} else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*2 && mouseY>=0 && mouseY<buttonHeight/actButtonHeightNum*1){
		//除外ボタンにマウスがある場合
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.m_pEditAction=EditRemoveFactory();
			m_actionSettings.m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
		}
	} else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseY>=buttonHeight/actButtonHeightNum*1 && mouseY<buttonHeight/actButtonHeightNum*2){
		//変更ボタンにマウスがある場合
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.m_pEditAction=EditMoveFactory();
			m_actionSettings.m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
		}
	}
	//キーボード入力受付
	if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
		return -1;
	}
	return 0;
}

void GGEditor::Draw() {
	clsDx();
	for(auto o:*m_actionSettings.GetPMObject()){
		printfDx("%d\n",o.get());
	}
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
	//マップ全体の描画
	bool firstflag=true;
	Vector2D mouse=GetMousePointVector2D()-Vector2D((float)leftUpPosX,(float)leftUpPosY)+m_actionSettings.GetMAdjust();//マウスの位置(補正値を考慮しマップ上の座標で表す)
	for (const std::shared_ptr<BattleObject> &obj : *m_actionSettings.GetPMObject()) {
		//obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
		obj.get()->VDraw(Vector2D((float)leftUpPosX,(float)leftUpPosY)-m_actionSettings.GetMAdjust());
		//マウスが被っている図形には黄色い枠を描画しフォーカスを表現
		if(firstflag && obj.get()->JudgePointInsideShape(mouse)){
			obj.get()->ShapeDraw(GetColor(255,255,0),FALSE,leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
			firstflag=false;
		}
		//選択中の図形については赤い枠を描画しフォーカスを表現
		if(obj.get()==m_actionSettings.m_pBattleObject.get()){
			obj.get()->ShapeDraw(GetColor(255,0,0),FALSE,leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
		}
	}
	//編集するBattleObjectをマップに仮想的に描画
	if(m_actionSettings.m_pBattleObject.get()!=nullptr){
		int mode,pal;
		GetDrawBlendMode(&mode,&pal);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		m_actionSettings.m_pBattleObject.get()->VDraw(GetMousePointVector2D(),Vector2D(0,0));
		SetDrawBlendMode(mode,pal);
	}
	SetDrawAreaFull();

	//入力されている動作のボタンの描画
	m_actionSettings.DrawEditButtonPushed();
	
	//右側の作業フレームの描画
	{
		const int bx=leftUpPosX*2+mapSizeX,by=0;//ボタン群の位置
		const int bdx=buttonWidth/actButtonWidthNum,bdy=(leftUpPosY*2+mapSizeY)/4/actButtonHeightNum;//ボタンの大きさ
		//動作ボタン群の描画
		for(unsigned int y=0;y<actButtonHeightNum;y++){
			for(unsigned int x=0;x<actButtonWidthNum;x++){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
				DrawBox(bx+x*bdx,by+y*bdy,bx+(x+1)*bdx,by+(y+1)*bdy,GetColor(192,192,192),TRUE);//内枠(ちょい透過させる)
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
				DrawBox(bx+x*bdx,by+y*bdy,bx+(x+1)*bdx,by+(y+1)*bdy,GetColor(192,192,64),FALSE);//外枠
				//文字
				DrawStringCenterBaseToHandle(bx+x*bdx+bdx/2,by+y*bdy+bdy/2,actButtonStr[x+y*actButtonHeightNum].c_str(),GetColor(255,255,255),m_font,true);
			}
		}
	}

}
