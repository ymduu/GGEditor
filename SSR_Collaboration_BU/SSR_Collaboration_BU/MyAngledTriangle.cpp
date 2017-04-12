#include"DxLib.h"
#include"MyAngledTriangle.h"

MyAngledTriangle::MyAngledTriangle(double i_vx, double i_vy)
	:vx(i_vx),vy(i_vy){}

MyAngledTriangle::~MyAngledTriangle() {}

void MyAngledTriangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
	DrawTriangle((int)x,(int)y
		,(int)(x+vx),(int)y
		,(int)x,(int)(y+vy)
		,color, fillFlag);
}

bool MyAngledTriangle::VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos){
	//�܂������`�����ɂ��邩�ǂ����̔���
	const Vector2D sp=point-shapePos;
	if(sp.x>=min(0,vx) && sp.x<=max(0,vx) && sp.y>=min(0,vy) && sp.y<=max(0,vy)){
		//������point��shapePos���Ίp���ɑ΂��ē������ɂ��邩�𔻒肷��΂悢
		//shapePos�����_�Ƃ������̑Ίp���̕�����:y=(vy-0)/(0-vx)*(x-vx) -> y*vx+vy*(x-vx)=0
		//�������ɂ��邩�̔��������΂悢�̂ŁAvx�̐������l����K�v�͂Ȃ�
		return ((-vy*vx)*(sp.y*vx+vy*(sp.x-vx))>=0);
	}
	return false;
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyCircle *pshape) {
	return MyShape::HitJudge(pshape, this);
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyRectangle *pshape) {
	return MyShape::HitJudge(pshape,this);
}

MyShape::HitInfo MyAngledTriangle::VHitJudge(const MyAngledTriangle *pshape) {
	return MyShape::HitJudge(this, pshape);
}
