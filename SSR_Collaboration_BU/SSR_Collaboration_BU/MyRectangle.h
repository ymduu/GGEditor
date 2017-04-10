#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//長方形を定義するクラス
class MyRectangle :public MyShape {
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
	//当たり判定関数
	HitInfo HitJudge(const MyCircle *pshape);
	HitInfo HitJudge(const MyRectangle *pshape);
	HitInfo HitJudge(const MyAngledTriangle *pshape);

};

#endif // !DEF_MYRECTANGLE_H
