#include"DxLib.h"
#include"MyAngledTriangle.h"

MyAngledTriangle::MyAngledTriangle(float i_vx, float i_vy)
	:vx(i_vx),vy(i_vy){}

MyAngledTriangle::~MyAngledTriangle() {}

void MyAngledTriangle::VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle)const {
	//ひとまずテクスチャーを使わずに実装
	DrawTriangle((int)x,(int)y
		,(int)(x+vx),(int)y
		,(int)x,(int)(y+vy)
		,color, fillFlag);
}


bool MyAngledTriangle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	//ここは第二引数が自分のため、aMyPosは第四引数にしないとおかしい
	return MyShape::HitJudge(pshape, this,aOtherPos,aMyPos);
}

bool MyAngledTriangle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	//ここは第二引数が自分のため、aMyPosは第四引数にしないとおかしい
	return MyShape::HitJudge(pshape,this,aOtherPos,aMyPos);
}

bool MyAngledTriangle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	return MyShape::HitJudge(this, pshape, aMyPos, aOtherPos);
}

bool MyAngledTriangle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos)const{
	//まず長方形内部にあるかどうかの判定
	const Vector2D sp = point - shapePos;
	if (sp.x >= getLeft(Vector2D(0,0)) && sp.x <= getRight(Vector2D(0,0)) && sp.y >= getTop(Vector2D(0,0)) && sp.y <= getBottom(Vector2D(0,0))) {
		//そしてpointとshapePosが対角線に対して同じ側にあるかを判定すればよい
		//shapePosを原点とした時の対角線の方程式:y=(vy-0)/(0-vx)*(x-vx) -> y*vx+vy*(x-vx)=0
		//同じ側にあるかの判定をすればよいので、vxの正負を考える必要はない
		return ((-vy*vx)*(sp.y*vx + vy*(sp.x - vx)) >= 0);
	}
	return false;
}

float MyAngledTriangle::getTop(Vector2D aPos)const{
	return min(aPos.y,aPos.y+vy);
}
float MyAngledTriangle::getBottom(Vector2D aPos)const{
	return max(aPos.y,aPos.y+vy);
}
float MyAngledTriangle::getLeft(Vector2D aPos)const{
	return min(aPos.x,aPos.x+vx);
}
float MyAngledTriangle::getRight(Vector2D aPos)const{
	return max(aPos.x,aPos.x+vx);
}