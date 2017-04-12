#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//長方形を定義するクラス
class MyRectangle:public MyShape {
	//型・列挙体

	//定数

	//変数
protected:
	double dx, dy;//大きさ

	//関数
public:
	MyRectangle(double i_dx,double i_dy);
	~MyRectangle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);//形状を描画する
	//図形内に点があるかどうかの判定
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//当たり判定関数
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);


};

#endif // !DEF_MYRECTANGLE_H
