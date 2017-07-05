#include"EditPut.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditPut::EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditPut::VNonPressEditing(Vector2D point,EditActionSettings &settings)const{
	settings.m_pBattleObject.get()->Warp(point);
}

void EditPut::VProcessAction(Vector2D point,EditActionSettings &settings)const {
	settings.PutObject(point);
}
