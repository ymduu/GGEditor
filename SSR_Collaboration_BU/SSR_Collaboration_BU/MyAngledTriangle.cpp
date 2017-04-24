#include"DxLib.h"
#include"MyAngledTriangle.h"

MyAngledTriangle::MyAngledTriangle(float i_vx, float i_vy)
	:vx(i_vx),vy(i_vy){}

MyAngledTriangle::~MyAngledTriangle() {}

void MyAngledTriangle::VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle)const {
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
	DrawTriangle((int)x,(int)y
		,(int)(x+vx),(int)y
		,(int)x,(int)(y+vy)
		,color, fillFlag);
}

std::shared_ptr<MyShape> MyAngledTriangle::VCopy()const{
	return std::shared_ptr<MyShape>(new MyAngledTriangle(vx,vy));
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	//�����͑������������̂��߁AaMyPos�͑�l�����ɂ��Ȃ��Ƃ�������
	return MyShape::HitJudge(pshape, this,aOtherPos,aMyPos);
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	//�����͑������������̂��߁AaMyPos�͑�l�����ɂ��Ȃ��Ƃ�������
	return MyShape::HitJudge(pshape,this,aOtherPos,aMyPos);
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const{
	return MyShape::HitJudge(this, pshape, aMyPos, aOtherPos);
}

bool MyAngledTriangle::VJudgePosintInsideShape(const Vector2D point, const Vector2D shapePos)const{
	//�܂������`�����ɂ��邩�ǂ����̔���
	const Vector2D sp = point - shapePos;
	if (sp.x >= getLeft(Vector2D(0,0)) && sp.x <= getRight(Vector2D(0,0)) && sp.y >= getTop(Vector2D(0,0)) && sp.y <= getBottom(Vector2D(0,0))) {
		//������point��shapePos���Ίp���ɑ΂��ē������ɂ��邩�𔻒肷��΂悢
		//shapePos�����_�Ƃ������̑Ίp���̕�����:y=(vy-0)/(0-vx)*(x-vx) -> y*vx+vy*(x-vx)=0
		//�������ɂ��邩�̔��������΂悢�̂ŁAvx�̐������l����K�v�͂Ȃ�
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

Vector2D MyAngledTriangle::GetNearestPoint(Vector2D trianglePos, Vector2D p)const {
	bool top = false, left = false;
	
	if (p.x < getLeft(trianglePos)) {
		//�����_(�~�̒��S��z��)���O�p�`�̍��[��荶�ɂ�������
		p.x = getLeft(trianglePos);
		left = true;
	}
	//y�ɂ����l�̏���������
	if (p.y < getTop(trianglePos)) {
		p.y = getTop(trianglePos);
		top = true;
	}
	if (left || top) {
		if (p.x > getRight(trianglePos)) {
			//�����_���O�p�`�̉E�[���E�ɂ�������
			p.x = getRight(trianglePos);
		}
		if (p.y > getBottom(trianglePos)) {
			p.y = getBottom(trianglePos);
		}
		return p;
	}
	//�����ɂ��㑤�ɂ��Ȃ��ꍇ�A�ΕӂƂ̍ŋߖT�_�����߂�
	Vector2D endPoint1(trianglePos.x,trianglePos.y+vy), endPoint2(trianglePos.x+vx,trianglePos.y);
	Vector2D hypoVec = endPoint2 - endPoint1;
	Vector2D pointVec = p - endPoint1;			//endpoint1���n�_�ɂ��ăx�N�g���𒣂�
	//���ςɂ���Đ����̑������߂�B
	Vector2D hoot = hypoVec.norm()*pointVec.dot(hypoVec.norm())+endPoint1;
	if (min(endPoint1.x, endPoint2.x) < hoot.x && max(endPoint1.x, endPoint2.x) > hoot.x) {
		return hoot;
	}
	else if (min(endPoint1.x, endPoint2.x) >= hoot.x) {
		if (endPoint1.x < endPoint2.x) return endPoint1;
		else return endPoint2;
	}
	else {
		if (endPoint1.x > endPoint2.x) return endPoint1;
		else return endPoint2;
	}


	return Vector2D(-1.0f,-1.0f);
};