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
	MyAngledTriangle(double i_vx,double i_vy);
	~MyAngledTriangle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
	//�����蔻��֐�
	HitInfo HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);

};

#endif // !DEF_MYANGLEDTRIANGLE_H
