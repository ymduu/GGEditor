#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//�����`���`����N���X
class MyRectangle :public MyShape {
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
};

#endif // !DEF_MYRECTANGLE_H
