#include"DxLib.h"
#include"MyCircle.h"

MyCircle::MyCircle(double i_r):r(i_r) {}

MyCircle::~MyCircle() {}

void MyCircle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawCircle((int)x, (int)y ,(int)r, color, fillFlag);
}

bool MyCircle::VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos){
	return ((point-shapePos).size()<=r);
}

MyShape::HitInfo MyCircle::VHitJudge(const MyCircle *pshape) {
	return MyShape::HitJudge(this,pshape);
}

MyShape::HitInfo MyCircle::VHitJudge(const MyRectangle *pshape) {
	return MyShape::HitJudge(this, pshape);
}

MyShape::HitInfo MyCircle::VHitJudge(const MyAngledTriangle *pshape) {
	return MyShape::HitJudge(this, pshape);
}
