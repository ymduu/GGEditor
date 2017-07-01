#include"DxLib.h"
#include"Terrain.h"


Terrain::Terrain(const std::shared_ptr<MyShape> hitJudgeShape, float x, float y, int gHandle, int kind, unsigned int color, bool breakable)
	:BattleObject(hitJudgeShape,x,y,gHandle,kind),m_color(color),m_breakable(breakable){}

Terrain::~Terrain() {}

void Terrain::VDraw(Vector2D point,Vector2D adjust) {
	m_hitJudgeShape->VDraw(adjust.x+point.x,adjust.y+point.y,m_color,TRUE,-1);
}

void Terrain::VHitProcess(const BattleObject *potherobj) {
	//�����_�ł͓��ɉ������Ȃ�
}

std::shared_ptr<BattleObject> Terrain::VCopy()const{
	return std::shared_ptr<BattleObject>(new Terrain(m_hitJudgeShape.get()->VCopy(),m_pos.x,m_pos.y,m_gHandle,m_kind,m_color,m_breakable));
}
