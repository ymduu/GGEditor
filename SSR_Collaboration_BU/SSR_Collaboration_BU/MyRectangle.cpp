#include"DxLib.h"
#include"MyRectangle.h"

MyRectangle::MyRectangle(double i_dx,double i_dy)
	:dx(i_dx),dy(i_dy){}

MyRectangle::~MyRectangle() {}

void MyRectangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
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
	//dx�̐����ɂ���ď��������ς��(���܂����@����C������񂾂��ǂȂ�)
	//dx>=0
	//	(point.x-shapePos.x)>=0
	//	(point.x-shapePos.x)<=dx
	//dx<0
	//	(point.x-shapePos.x)<=0
	//	(point.x-shapePos.x)>=dx
	Vector2D sp = point - shapePos;
	return (sp.x >= min(0, dx) && sp.x <= max(0, dx) && sp.y >= min(0, dy) && sp.y <= max(0, dy));
}

//�_(�~�̒��S��z��)����l�p�`�ɉ����������̑��̍��W�����߂�
Vector2D MyRectangle::GetNearestPoint(Vector2D rectanglePos , Vector2D p)const {
	if (p.x < rectanglePos.x) {
		//�����_(�~�̒��S��z��)���l�p�`�̍��[��荶�ɂ�������
		p.x = rectanglePos.x;
	}
	if (p.x > rectanglePos.x + dx) {
		//�����_���l�p�`�̉E�[���E�ɂ�������
		p.x = rectanglePos.x + dx;
	}
	//y�ɂ����l�̏���������
	if (p.y < rectanglePos.y) {
		p.y = rectanglePos.y;
	}
	if (p.y > rectanglePos.y + dy) {
		p.y = rectanglePos.y + dy;
	}
	return p;
}