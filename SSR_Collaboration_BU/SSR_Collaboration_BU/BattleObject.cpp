#include"DxLib.h"
#include"BattleObject.h"

void BattleObject::ShapeDraw(unsigned int color,int fillFlag,int dx,int dy){
	m_hitJudgeShape->VDraw(dx+m_pos.x,dy+m_pos.y,color,fillFlag,-1);
}

void BattleObject::Move(Vector2D v){
	m_pos=m_pos+v;
}

void BattleObject::Warp(Vector2D v){
	m_pos=v;
}

bool BattleObject::JudgePointInsideShape(Vector2D point){
	return m_hitJudgeShape.get()->VJudgePosintInsideShape(point,m_pos);
}

float BattleObject::getTop() {
	return m_hitJudgeShape->getTop(m_pos);
}
float BattleObject::getBottom() {
	return m_hitJudgeShape->getBottom(m_pos);
}
float BattleObject::getLeft() {
	return m_hitJudgeShape->getLeft(m_pos);
}
float BattleObject::getRight() {
	return m_hitJudgeShape->getRight(m_pos);
}
Vector2D BattleObject::getPos() {
	return m_pos;
}
std::shared_ptr<MyShape> BattleObject::getHitJudgeShape() {
	return m_hitJudgeShape;
}