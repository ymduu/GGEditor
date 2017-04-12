#include"DxLib.h"
#include"MyRectangle.h"

MyRectangle::MyRectangle(double i_dx,double i_dy)
	:dx(i_dx),dy(i_dy){}

MyRectangle::~MyRectangle() {}

void MyRectangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
	DrawBox((int)x,(int)y,(int)(x+dx),(int)(y+dy),color,fillFlag);
}

bool MyRectangle::VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos){
	//dx�̐����ɂ���ď��������ς��(���܂����@����C������񂾂��ǂȂ�)
	//dx>=0
	//	(point.x-shapePos.x)>=0
	//	(point.x-shapePos.x)<=dx
	//dx<0
	//	(point.x-shapePos.x)<=0
	//	(point.x-shapePos.x)>=dx
	Vector2D sp=point-shapePos;
	return (sp.x>=min(0,dx) && sp.x<=max(0,dx) && sp.y>=min(0,dy) && sp.y<=max(0,dy));
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyCircle *pshape) {
	return MyShape::HitJudge(pshape,this);
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyRectangle *pshape) {
	return MyShape::HitJudge(this,pshape);
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyAngledTriangle *pshape) {
	return MyShape::HitJudge(this, pshape);
}
