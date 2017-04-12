#include"DxLib.h"
#include"MyRectangle.h"

MyRectangle::MyRectangle(double i_dx,double i_dy)
	:dx(i_dx),dy(i_dy){}

MyRectangle::~MyRectangle() {}

void MyRectangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawBox((int)x,(int)y,(int)(x+dx),(int)(y+dy),color,fillFlag);
}

bool MyRectangle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(pshape,this,aMyPos,aOtherPos);
}

bool MyRectangle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this,pshape,aMyPos,aOtherPos);
}

bool MyRectangle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return MyShape::HitJudge(this, pshape,aMyPos,aOtherPos);
}

bool MyRectangle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos) {
	//dxの正負によって条件式が変わる(うまい方法ある気がするんだけどなあ)
	//dx>=0
	//	(point.x-shapePos.x)>=0
	//	(point.x-shapePos.x)<=dx
	//dx<0
	//	(point.x-shapePos.x)<=0
	//	(point.x-shapePos.x)>=dx
	Vector2D sp = point - shapePos;
	return (sp.x >= min(0, dx) && sp.x <= max(0, dx) && sp.y >= min(0, dy) && sp.y <= max(0, dy));
}

//点(円の中心を想定)から四角形に下した垂線の足の座標を求める
Vector2D MyRectangle::GetNearestPoint(Vector2D rectanglePos , Vector2D p)const {
	if (p.x < rectanglePos.x) {
		//もし点(円の中心を想定)が四角形の左端より左にあったら
		p.x = rectanglePos.x;
	}
	if (p.x > rectanglePos.x + dx) {
		//もし点が四角形の右端より右にあったら
		p.x = rectanglePos.x + dx;
	}
	//yにも同様の処理をする
	if (p.y < rectanglePos.y) {
		p.y = rectanglePos.y;
	}
	if (p.y > rectanglePos.y + dy) {
		p.y = rectanglePos.y + dy;
	}
	return p;
}