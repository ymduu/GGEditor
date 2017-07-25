#include<math.h>
#include"EditActionSettings.h"

#include"DxLib.h"
#include"GGEditor.h"
#include"EditAction.h"
#include"ShapeFactory.h"

#include"Terrain.h"
#include"MyAngledTriangle.h"
#include"MyCircle.h"
#include"MyRectangle.h"
#include"RectangleFactory.h"

EditActionSettings::EditActionSettings(std::shared_ptr<EditAction> pEditAction, std::shared_ptr<BattleObject> pBattleObject,std::shared_ptr<ShapeFactory> pShapeFactory,std::shared_ptr<PosSetting> pPosSetting)
	:m_adjust(0,0),m_pEditAction(pEditAction),m_pBattleObject(pBattleObject),m_pShapeFactory(pShapeFactory),m_pPosSetting(pPosSetting),m_pOriginObject(std::shared_ptr<BattleObject>(nullptr))
{
	//実験用
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
			,20+GetMAdjust().x
			,20+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,40))
			,180+GetMAdjust().x
			,180+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,-40))
			,190+GetMAdjust().x
			,120+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,-40))
			,280+GetMAdjust().x
			,280+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyCircle(40))
			,390+GetMAdjust().x
			,390+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(30,40))
			,620+GetMAdjust().x
			,620+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-30,40))
			,780+GetMAdjust().x
			,780+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(40,-30))
			,790+GetMAdjust().x
			,720+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-40,-50))
			,880+GetMAdjust().x
			,880+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
}

EditActionSettings::~EditActionSettings() {}

std::vector<std::shared_ptr<BattleObject>>::iterator EditActionSettings::GetMousePointedObject(Vector2D point){
	std::vector<std::shared_ptr<BattleObject>>::iterator it=m_objects.begin(),ite=m_objects.end();
	for(;it!=ite;it++) {
		//マウスが被っている図形には枠を描画しフォーカスを表現
		if(it->get()->JudgePointInsideShape(point)){
			break;
		}
	}
	return it;
}

void EditActionSettings::PracticeEdit(Vector2D point){
	//マウス座標をマップ実座標に変換してから編集
	m_pEditAction.get()->VProcessAction(point+m_adjust,*this);
}

void EditActionSettings::PracticeNonPressEdit(Vector2D point){
	//マウス座標をマップ実座標に変換してから編集
	m_pEditAction.get()->VNonPressEditing(point+m_adjust,*this);
}

void EditActionSettings::PushScrollBar(float scrollpx,float maxX,float maxY,int mouseX,int mouseY,int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY){
	if(mouseY*leftUpPosX-mouseX*leftUpPosY<0 && (mouseY-leftUpPosY)*leftUpPosX+(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY<0){
		//上部分(1より下、2より下)
		m_adjust.y=fmax((float)0,m_adjust.y-scrollpx);
	} else if(mouseY*leftUpPosX-mouseX*leftUpPosY>=0 && (mouseY-(leftUpPosY+mapSizeY))*leftUpPosX+(mouseX-leftUpPosX)*leftUpPosY<0){
		//左部分(1より上、2より下)
		m_adjust.x=fmax((float)0,m_adjust.x-scrollpx);
	} else if((mouseY-leftUpPosY)*leftUpPosX+(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY>=0 && (mouseY-(leftUpPosY+mapSizeY))*leftUpPosX-(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY<0){
		//右部分(1より下、2より上)
		m_adjust.x=fmin(maxX-mapSizeX,m_adjust.x+scrollpx);
	} else{
		//下部分(1より上、2より上)
		m_adjust.y=fmin(maxY-mapSizeY,m_adjust.y+scrollpx);
	}
}

void EditActionSettings::PushScrollBar(Vector2D move){
	//最大値最小値を考慮する
	Vector2D a=m_adjust+move;
	float maxX=2000-(float)GGEditor::mapSizeX,maxY=2000-(float)GGEditor::mapSizeY;
	m_adjust=Vector2D(
		a.x>=0 ? (a.x<maxX ? a.x : maxX) : 0
		,a.y>=0 ? (a.y<maxY ? a.y : maxY) : 0
	);
}

void EditActionSettings::DrawEditButtonPushed()const{
	m_pEditAction.get()->DrawPushedButton();
}

void EditActionSettings::DrawShapeFactoryButtonPushed()const{
	m_pShapeFactory->DrawPushedButtonLight();
}

void EditActionSettings::PutObject(Vector2D point){
	if(m_pBattleObject.get()!=nullptr){
		//オブジェクトを現在のマウスの位置に合わせてから設置
		m_pBattleObject.get()->Warp(point);
		m_objects.push_back(m_pBattleObject);
		//m_pBattleObjectをそのままにすると同じポインタのオブジェクトを違う場所に置こうとしてしまうので、ポインタは新しくする
		m_pBattleObject=m_pBattleObject->VCopy();
	}
}

void EditActionSettings::RemoveObject(Vector2D point){
	//取り除くオブジェクトを探す
	std::vector<std::shared_ptr<BattleObject>>::iterator it=GetMousePointedObject(point);
	if(it!=m_objects.end()){
		m_objects.erase(it);
	}
}

void EditActionSettings::SetEditObject(Vector2D point){
	std::vector<std::shared_ptr<BattleObject>>::iterator it=GetMousePointedObject(point);
	if(it!=m_objects.end()){
		m_pBattleObject=*it;
		m_pOriginObject=it->get()->VCopy();
	}
}

void EditActionSettings::CancelEditing(){
	//エディタで変更できるのは位置と大きさのみ
	if(m_pBattleObject.get()!=nullptr && m_pOriginObject.get()!=nullptr){
		m_pBattleObject.get()->Warp(m_pOriginObject.get()->getPos());
		m_pBattleObject.get()->Resize(m_pOriginObject.get()->getResizeVec());
	}
}

void EditActionSettings::InitEditObject(){
	m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
	m_pOriginObject=std::shared_ptr<BattleObject>(nullptr);
}
