#include"DxLib.h"
#include"BattleObject.h"

void BattleObject::VDraw(Vector2D adjust)const{
	VDraw(m_pos,adjust);
}

void BattleObject::ShapeDraw(unsigned int color,int fillFlag,int dx,int dy)const{
	m_hitJudgeShape->VDraw(dx+m_pos.x,dy+m_pos.y,color,fillFlag,-1);
}

void BattleObject::PosDraw(unsigned int color,int fillFlag,int size,int dx,int dy)const{
	DrawCircle(dx+m_pos.x,dy+m_pos.y,size,color,fillFlag);
}

void BattleObject::Move(Vector2D v){
	m_pos=m_pos+v;
}

void BattleObject::Warp(Vector2D v){
	m_pos=v;
}

void BattleObject::Resize(Vector2D v){
	//基準点からマウスを結んだベクトルを引数に渡す
	m_hitJudgeShape.get()->Resize(v-m_pos);
}

bool BattleObject::JudgePointInsideShape(Vector2D point)const{
	return m_hitJudgeShape.get()->VJudgePosintInsideShape(point,m_pos);
}

float BattleObject::getTop()const {
	return m_hitJudgeShape->getTop(m_pos);
}
float BattleObject::getBottom()const {
	return m_hitJudgeShape->getBottom(m_pos);
}
float BattleObject::getLeft()const {
	return m_hitJudgeShape->getLeft(m_pos);
}
float BattleObject::getRight()const {
	return m_hitJudgeShape->getRight(m_pos);
}
Vector2D BattleObject::getPos()const {
	return m_pos;
}
std::shared_ptr<MyShape> BattleObject::getHitJudgeShape()const {
	return m_hitJudgeShape;
}
Vector2D BattleObject::getResizeVec()const{
	//m_hitJudgeShapeのものはオブジェクトの位置を考慮していないのでそれを足して返す
	return m_hitJudgeShape.get()->GetRetResize()+m_pos;
}

