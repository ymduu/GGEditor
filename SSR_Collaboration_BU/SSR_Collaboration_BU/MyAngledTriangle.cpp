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


bool MyAngledTriangle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(pshape, this,aMyPos,aOtherPos);
}

bool MyAngledTriangle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(pshape,this, aMyPos, aOtherPos);
}

bool MyAngledTriangle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape, aMyPos, aOtherPos);
}

bool MyAngledTriangle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos) {
	//まず長方形内部にあるかどうかの判定
	const Vector2D sp = point - shapePos;
	if (sp.x >= min(0, vx) && sp.x <= max(0, vx) && sp.y >= min(0, vy) && sp.y <= max(0, vy)) {
		//そしてpointとshapePosが対角線に対して同じ側にあるかを判定すればよい
		//shapePosを原点とした時の対角線の方程式:y=(vy-0)/(0-vx)*(x-vx) -> y*vx+vy*(x-vx)=0
		//同じ側にあるかの判定をすればよいので、vxの正負を考える必要はない
		return ((-vy*vx)*(sp.y*vx + vy*(sp.x - vx)) >= 0);
	}
	return false;
}

float MyAngledTriangle::getTop(Vector2D aPos) {
	return aPos.y;
}
float MyAngledTriangle::getBottom(Vector2D aPos) {
	return aPos.y;
}
float MyAngledTriangle::getLeft(Vector2D aPos) {
	return aPos.x;
}
float MyAngledTriangle::getRight(Vector2D aPos) {
	return aPos.x;
}