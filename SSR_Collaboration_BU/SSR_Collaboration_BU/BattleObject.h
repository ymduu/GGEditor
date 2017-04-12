#ifndef DEF_BATTLEOBJECT_H
#define DEF_BATTLEOBJECT_H

//インクルードファイル
#include<memory>
#include"ToolsLib.h"
#include"MyShape.h"


//別の場所で宣言しておくこと。
//struct Position2D;//一般的な位置を表す構造体


//バトル画面におけるオブジェクトの基底クラス
class BattleObject {
	//型

	//定数

	//変数
protected:
	const std::shared_ptr<MyShape> m_hitJudgeShape;//当たり判定の形状
	Vector2D m_pos;//オブジェクトの位置
	int m_gHandle;//オブジェクトのグラフィックハンドル
	int m_kind;//オブジェクトの分類(暫定的にintにしている)

	//関数
public:
	//コンストラクタとデストラクタ
	BattleObject(const std::shared_ptr<MyShape> hitJudgeShape,float x,float y,int gHandle,int kind)
		:m_hitJudgeShape(hitJudgeShape),m_pos(x,y),m_gHandle(gHandle),m_kind(kind){}
	virtual ~BattleObject() {}

	//仮想関数
	virtual void VDraw(int x=0,int y=0)=0;//描画処理(位置ずらし含める)
	virtual void VHitProcess(const BattleObject *potherobj)=0;//何かに当たった時の処理

	//通常関数
	void ShapeDraw(unsigned int color,int fillFlag,int dx=0,int dy=0);//当たり判定形状に基づいた描画処理(dx,dyはズレの値)
	void Move(float x,float y);
	bool JudgePointInsideShape(Vector2D point);
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
};

#endif // !DEF_BATTLEOBJECT_H
