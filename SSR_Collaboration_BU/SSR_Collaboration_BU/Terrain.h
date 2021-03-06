#ifndef DEF_TERRAIN_H
#define DEF_TERRAIN_H

//地形・障害物についての情報の宣言
#include"BattleObject.h"

class Terrain :public BattleObject {
	//型・列挙体

	//定数

	//変数
protected:
	unsigned int m_color;//地形の塗りつぶしの色(そのうちテクスチャ情報に変わると思われる)
	bool m_breakable;//破壊できるかどうか

	//関数
public:
	Terrain(const std::shared_ptr<MyShape> hitJudgeShape, float x, float y, int gHandle, int kind,unsigned int color,bool breakable);
	~Terrain();
	void VDraw(int x,int y);//描画処理
	void VHitProcess(const BattleObject *potherobj);
	std::shared_ptr<BattleObject> VCopy()const;
};


#endif // !DEF_TERRAIN_H
