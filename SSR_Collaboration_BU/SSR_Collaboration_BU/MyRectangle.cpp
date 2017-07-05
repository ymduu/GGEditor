#include"DxLib.h"
#include"MyRectangle.h"

MyRectangle::MyRectangle(float i_dx,float i_dy)
	:dx(i_dx),dy(i_dy){}

MyRectangle::~MyRectangle() {}

void MyRectangle::VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle)const{
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
	DrawBox((int)x,(int)y,(int)(x+dx),(int)(y+dy),color,fillFlag);
}

std::shared_ptr<MyShape> MyRectangle::VCopy()const{
	return std::shared_ptr<MyShape>(new MyRectangle(dx,dy));
}

void MyRectangle::Resize(Vector2D v){
	dx=v.x;
	dy=v.y;
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	//�����͑������������̂��߁AaMyPos�͑�l�����ɂ��Ȃ��Ƃ�������
	return MyShape::HitJudge(pshape,this,aOtherPos, aMyPos);
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	return MyShape::HitJudge(this,pshape,aMyPos,aOtherPos);
}

MyShape::HitInfo MyRectangle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	return MyShape::HitJudge(this, pshape,aMyPos,aOtherPos);
}

bool MyRectangle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos)const{
	//dx�̐����ɂ���ď��������ς��(���܂����@����C������񂾂��ǂȂ�)
	//dx>=0
	//	(point.x-shapePos.x)>=0
	//	(point.x-shapePos.x)<=dx
	//dx<0
	//	(point.x-shapePos.x)<=0
	//	(point.x-shapePos.x)>=dx
	Vector2D sp = point - shapePos;
	return (sp.x >= getLeft(Vector2D(0,0)) && sp.x <= getRight(Vector2D(0,0)) && sp.y >= getTop(Vector2D(0,0)) && sp.y <= getBottom(Vector2D(0,0)));
}

//�_(�~�̒��S��z��)����l�p�`�ɉ����������̑��̍��W�����߂�
Vector2D MyRectangle::GetNearestPoint(Vector2D rectanglePos , Vector2D p)const{
	if (p.x < getLeft(rectanglePos)) {
		//�����_(�~�̒��S��z��)���l�p�`�̍��[��荶�ɂ�������
		p.x = getLeft(rectanglePos);
	}
	if (p.x > getRight(rectanglePos)) {
		//�����_���l�p�`�̉E�[���E�ɂ�������
		p.x = getRight(rectanglePos);
	}
	//y�ɂ����l�̏���������
	if (p.y < getTop(rectanglePos)) {
		p.y = getTop(rectanglePos);
	}
	if (p.y > getBottom(rectanglePos)) {
		p.y = getBottom(rectanglePos);
	}
	return p;
}
float MyRectangle::getTop(Vector2D aPos)const{
	return min(aPos.y,aPos.y+dy);
}
float MyRectangle::getBottom(Vector2D aPos)const{
	return max(aPos.y,aPos.y+dy);
}
float MyRectangle::getLeft(Vector2D aPos)const{
	return min(aPos.x,aPos.x+dx);
}
float MyRectangle::getRight(Vector2D aPos)const{
	return max(aPos.x,aPos.x+dx);
}