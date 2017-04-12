#ifndef DEF_MYCIRCLE_H
#define DEF_MYCIRCLE_H

#include"MyShape.h"

//円を定義するクラス
class MyCircle :public MyShape {
	//列挙体・型
	//定数
	//変数
protected:
	double r;
	//関数
public:
	MyCircle(double i_r);
	~MyCircle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
	//図形内に点があるかどうかの判定
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//当たり判定関数
	HitInfo VHitJudge(const MyCircle *pshape);
	HitInfo VHitJudge(const MyRectangle *pshape);
	HitInfo VHitJudge(const MyAngledTriangle *pshape);

};

#endif // !DEF_MYCIRCLE_H
