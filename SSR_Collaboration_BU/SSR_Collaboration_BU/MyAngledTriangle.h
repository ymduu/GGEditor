#ifndef DEF_MYANGLEDTRIANGLE_H
#define DEF_MYANGLEDTRIANGLE_H

#include"MyShape.h"

//���p�O�p�`���`����N���X
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
};

#endif // !DEF_MYANGLEDTRIANGLE_H
