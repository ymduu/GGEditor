#include"DxLib.h"
#include"BattleObject.h"

void BattleObject::ShapeDraw(unsigned int color,int fillFlag,int dx,int dy){
	m_hitJudgeShape->VDraw(dx+m_pos.x,dy+m_pos.y,color,fillFlag,-1);
}

void BattleObject::Move(float x,float y){
	m_pos.x=x;
	m_pos.y=y;
}
