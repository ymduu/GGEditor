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
	
	int m_gHandle;//オブジェクトのグラフィックハンドル
	int m_kind;//オブジェクトの分類(暫定的にintにしている)
	//protectedに戻しました(getterを作ったため)
	Vector2D m_pos;//オブジェクトの位置
	std::shared_ptr<MyShape> m_hitJudgeShape;//当たり判定の形状

public:
	//補正される側か？(プレイヤーキャラか？)
	bool fixFlag;

	//関数
public:
	//コンストラクタとデストラクタ
	BattleObject(const std::shared_ptr<MyShape> hitJudgeShape,float x,float y,int gHandle,int kind)
		:m_hitJudgeShape(hitJudgeShape),m_pos(x,y),m_gHandle(gHandle),m_kind(kind),fixFlag(false){}
	virtual ~BattleObject() {}

	
	//仮想関数
	void VDraw(Vector2D adjust=Vector2D(0,0))const;//描画処理(位置ずらし含める)
	virtual void VDraw(Vector2D point,Vector2D adjust)const=0;//描画処理(任意座標に描画)
	virtual void VHitProcess(const BattleObject *potherobj)=0;//何かに当たった時の処理
	virtual std::shared_ptr<BattleObject> VCopy()const=0;//同じオブジェクトを複製する(ポインタのみ異なる)

	//通常関数
	void ShapeDraw(unsigned int color,int fillFlag,int dx=0,int dy=0)const;//当たり判定形状に基づいた描画処理(dx,dyはズレの値)
	void PosDraw(unsigned int color,int fillFlag,int size,int dx=0,int dy=0)const;//m_Posの位置に円を描画する。
	void Move(Vector2D v);//ベクトルvだけ動かす(バトルの時等で用いる)
	void Warp(Vector2D v);//ベクトルvへ動かす(ステージ編集で用いる)
	void Resize(Vector2D v);//位置ベクトルvを参考に大きさを変更する(ステージ編集で用いる)
	void ChangeShape(std::shared_ptr<MyShape> pShape);//当たり判定図形を変更する
	bool JudgePointInsideShape(Vector2D point)const;
	float getTop()const;
	float getBottom()const;
	float getLeft()const;
	float getRight()const;
	Vector2D getPos()const;
	Vector2D getResizeVec()const;
	std::shared_ptr<MyShape> getHitJudgeShape()const;
};

#endif // !DEF_BATTLEOBJECT_H
