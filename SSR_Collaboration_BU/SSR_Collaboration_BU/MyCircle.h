#ifndef DEF_MYCIRCLE_H
#define DEF_MYCIRCLE_H

#include"MyShape.h"
#include "ToolsLib.h"

//�~���`����N���X
class MyCircle :public MyShape {
	//�񋓑́E�^
	//�萔
	//�ϐ�
protected:
	//�֐�
public:
	double r;
	MyCircle(double i_r);
	~MyCircle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
	//�����蔻��֐�
	HitInfo HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	HitInfo HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);

};

#endif // !DEF_MYCIRCLE_H
