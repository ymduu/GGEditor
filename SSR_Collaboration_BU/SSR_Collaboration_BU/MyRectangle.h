#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//�����`���`����N���X
class MyRectangle:public MyShape {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:
	float dx, dy;//�傫��

	//�֐�
public:
	MyRectangle(float i_dx,float i_dy);
	~MyRectangle();
	void VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle)const;//�`���`�悷��
	std::shared_ptr<MyShape> VCopy()const;//���e�������Ń|�C���^�̈ʒu�݂̂��قȂ�I�u�W�F�N�g�̃|�C���^��Ԃ�

	//�}�`���ɓ_�����邩�ǂ����̔���
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)const;
	//�����蔻��֐�
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	//�l�p�`���̂��̂̍��W�Ɠ_�������Ɏ��A�ŋߖT�̓_��Ԃ�
	Vector2D GetNearestPoint(Vector2D rectanglePos , Vector2D p)const;	
	//�㉺���E�̍��W���擾(4���؂̂���)
	float getTop(Vector2D aPos)const;
	float getBottom(Vector2D aPos)const;
	float getLeft(Vector2D aPos)const;
	float getRight(Vector2D aPos)const;


};

#endif // !DEF_MYRECTANGLE_H
