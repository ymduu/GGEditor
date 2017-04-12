#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//�����`���`����N���X
class MyRectangle:public MyShape {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:
	double dx, dy;//�傫��

	//�֐�
public:
	MyRectangle(double i_dx,double i_dy);
	~MyRectangle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);//�`���`�悷��
	//�}�`���ɓ_�����邩�ǂ����̔���
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//�����蔻��֐�
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);


};

#endif // !DEF_MYRECTANGLE_H
