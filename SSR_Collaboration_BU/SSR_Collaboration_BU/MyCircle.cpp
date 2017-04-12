#include"DxLib.h"
#include"MyCircle.h"

MyCircle::MyCircle(double i_r):r(i_r) {}

MyCircle::~MyCircle() {}

void MyCircle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawCircle((int)x, (int)y ,(int)r, color, fillFlag);
}

MyShape::HitInfo MyCircle::HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this,pshape,aMyPos,aOtherPos);
}

MyShape::HitInfo MyCircle::HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape);
}

MyShape::HitInfo MyCircle::HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape);
}
