#ifndef DEF_MYCIRCLE_H
#define DEF_MYCIRCLE_H

#include"MyShape.h"

//�~���`����N���X
class MyCircle :public MyShape {
	//�񋓑́E�^
	//�萔
	//�ϐ�
protected:
	double r;
	//�֐�
public:
	MyCircle(double i_r);
	~MyCircle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
	//�����蔻��֐�
	HitInfo HitJudge(const MyCircle *pshape);
	HitInfo HitJudge(const MyRectangle *pshape);
	HitInfo HitJudge(const MyAngledTriangle *pshape);

};

#endif // !DEF_MYCIRCLE_H
