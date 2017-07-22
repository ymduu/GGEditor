#ifndef DEF_MYANGLEDTRIANGLE_H
#define DEF_MYANGLEDTRIANGLE_H

#include"MyShape.h"

//���p�O�p�`���`����N���X
//3�_��(0,0)(dx,0)(0,dy)�ŕ\����A���p����(0,0)�ł���B
class MyAngledTriangle :public MyShape {
	//�񋓑́E�^
	//�萔
	//�ϐ�
protected:
	float vx, vy;//���p�������x,y�����̐��̕����x�N�g���̒����B���̒l���ƕ��̕����ɐL�тĂ��鎖�������Ă���B
	//�֐�
public:
	MyAngledTriangle(float i_vx,float i_vy);
	~MyAngledTriangle();
	void VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle)const;
	std::shared_ptr<MyShape> VCopy()const;//���e�������Ń|�C���^�̈ʒu�݂̂��قȂ�I�u�W�F�N�g�̃|�C���^��Ԃ�
	void Resize(Vector2D v);//�t�̒��p�O�p�`�������������̂Q���p�������񂾂̃x�N�g����p���đ傫����ύX����
	Vector2D GetRetResize()const;//Resize�̋t�֐��B����r��Resize����ƌ��݂̐}�`�ɂȂ�悤��r��Ԃ��B

	//�}�`���ɓ_�����邩�ǂ����̔���
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)const;
	//�����蔻��֐�
	MyShape::HitInfo VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	MyShape::HitInfo VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	MyShape::HitInfo VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	//4���؂̂��߂ɏ㉺���E�̍��W���擾����
	float getTop(Vector2D aPos)const;
	float getBottom(Vector2D aPos)const;
	float getLeft(Vector2D aPos)const;
	float getRight(Vector2D aPos)const;
	Vector2D GetNearestPoint(Vector2D trianglePos, Vector2D p)const;

};

#endif // !DEF_MYANGLEDTRIANGLE_H
