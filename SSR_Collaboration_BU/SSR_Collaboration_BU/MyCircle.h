#ifndef DEF_MYCIRCLE_H
#define DEF_MYCIRCLE_H

#include"MyShape.h"
#include "ToolsLib.h"

//円を定義するクラス
class MyCircle :public MyShape {
	//列挙体・型
	//定数
	//変数
protected:
	//関数
public:
	double r;
	MyCircle(double i_r);
	~MyCircle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
	//当たり判定関数
	HitInfo HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);

};

#endif // !DEF_MYCIRCLE_H
