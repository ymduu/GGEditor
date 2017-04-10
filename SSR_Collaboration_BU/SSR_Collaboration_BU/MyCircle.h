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
	//当たり判定関数
	HitInfo HitJudge(const MyCircle *pshape);
	HitInfo HitJudge(const MyRectangle *pshape);
	HitInfo HitJudge(const MyAngledTriangle *pshape);

};

#endif // !DEF_MYCIRCLE_H
