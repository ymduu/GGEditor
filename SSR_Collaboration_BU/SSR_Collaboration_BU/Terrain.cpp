#include"DxLib.h"
#include"Terrain.h"


Terrain::Terrain(const std::shared_ptr<MyShape> hitJudgeShape, float x, float y, int gHandle, int kind, unsigned int color, bool breakable)
	:BattleObject(hitJudgeShape,x,y,gHandle,kind),m_color(color),m_breakable(breakable){}

Terrain::~Terrain() {}

void Terrain::VDraw() {
	m_hitJudgeShape->VDraw(m_pos.x,m_pos.y,m_color,TRUE,-1);
}

void Terrain::VHitProcess(const BattleObject *potherobj) {
	//現時点では特に何もしない
}
