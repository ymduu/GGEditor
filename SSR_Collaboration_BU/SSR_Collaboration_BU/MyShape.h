#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H
#include "ToolsLib.h"

#include"ToolsLib.h"

class MyCircle;
class MyRectangle;
class MyAngledTriangle;

//形状を定義するインターフェース
class MyShape {
	//型・列挙体
public:
	//定数

	//変数

	//関数
public:
	virtual void VDraw(double x,double y,unsigned int color,int fillFlag,int textureHandle)=0;//形状を描画する

	//図形内に点があるかどうかの判定
	virtual bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)=0;
	
	//当たり判定関数、引数に座標情報を追加
	bool HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	virtual bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;

	//当たり判定関数の実体
	static bool HitJudge(const MyCircle *pshape1, const MyCircle *pshape2,const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);

};

#endif // !DEF_MYSHAPE_H
