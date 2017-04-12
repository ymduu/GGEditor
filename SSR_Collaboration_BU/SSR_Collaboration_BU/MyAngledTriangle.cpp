#include"DxLib.h"
#include"MyAngledTriangle.h"

MyAngledTriangle::MyAngledTriangle(double i_vx, double i_vy)
	:vx(i_vx),vy(i_vy){}

MyAngledTriangle::~MyAngledTriangle() {}

void MyAngledTriangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawTriangle((int)x,(int)y
		,(int)(x+vx),(int)y
		,(int)x,(int)(y+vy)
		,color, fillFlag);
}

MyShape::HitInfo MyAngledTriangle::HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(pshape, this);
}

MyShape::HitInfo MyAngledTriangle::HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(pshape,this);
}

MyShape::HitInfo MyAngledTriangle::HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape);
}
