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
	double vx, vy;//���p�������x,y�����̐��̕����x�N�g���̒����B���̒l���ƕ��̕����ɐL�тĂ��鎖�������Ă���B
	//�֐�
public:
	MyAngledTriangle(float i_vx,float i_vy);
	~MyAngledTriangle();
	void VDraw(float x, float y, unsigned int color, int fillFlag, int textureHandle);
	//�}�`���ɓ_�����邩�ǂ����̔���
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//�����蔻��֐�
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	//4���؂̂��߂ɏ㉺���E�̍��W���擾����
	float getTop(Vector2D aPos);
	float getBottom(Vector2D aPos);
	float getLeft(Vector2D aPos);
	float getRight(Vector2D aPos);

};

#endif // !DEF_MYANGLEDTRIANGLE_H
