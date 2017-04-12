#include"DxLib.h"
#include"MyCircle.h"

MyCircle::MyCircle(double i_r):r(i_r) {}

MyCircle::~MyCircle() {}

void MyCircle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawCircle((int)x, (int)y ,(int)r, color, fillFlag);
}

bool MyCircle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this,pshape,aMyPos,aOtherPos);
}

bool MyCircle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape,aMyPos,aOtherPos);
}

bool MyCircle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape,aMyPos,aOtherPos);
}

bool MyCircle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos) {
	return ((point - shapePos).size() <= r);
}

float MyCircle::getTop(Vector2D aPos) {
	return aPos.y - r;
}
float MyCircle::getBottom(Vector2D aPos) {
	return aPos.y + r;
}
float MyCircle::getLeft(Vector2D aPos) {
	return aPos.x - r;
}
float MyCircle::getRight(Vector2D aPos) {
	return aPos.x + r;
}