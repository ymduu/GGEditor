#include"DxLib.h"

#include"EditPut.h"
#include"EditActionSettings.h"

#include"BattleObject.h"
#include"Terrain.h"
#include"MyRectangle.h"

//---------------------EditPut::EditPutButton---------------------
EditPut::EditPutButton::EditPutButton(Vector2D point,Vector2D vec)
	:EditActionButton(point,vec,"put"){}

void EditPut::EditPutButton::PushedProcess(EditActionSettings &settings)const{
	settings.CancelEditing();
	settings.m_pEditAction=std::shared_ptr<EditAction>(new EditPut(
		(int)m_point.x
		,(int)m_point.y
		,(int)m_vec.x
		,(int)m_vec.y
		,GetColor(255,255,0)));;
	settings.m_pBattleObject=std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false));
}



//---------------------EditMove---------------------
EditPut::EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditPut::VNonPressEditing(Vector2D point,EditActionSettings &settings)const{
	settings.m_pBattleObject.get()->Warp(point);
}

void EditPut::VProcessAction(Vector2D point,EditActionSettings &settings)const {
	settings.PutObject(point);
}
