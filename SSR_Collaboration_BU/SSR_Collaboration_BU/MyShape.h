#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H
#include "ToolsLib.h"

class MyCircle;
class MyRectangle;
class MyAngledTriangle;

//�`����`����C���^�[�t�F�[�X
class MyShape {
	//�^�E�񋓑�
public:
	struct HitInfo {
		//�����蔻����s������ɕԂ����
		bool judge;

		//�R���X�g���N�^
		HitInfo(bool i_judge)
			:judge(i_judge){}
	};
	//�萔

	//�ϐ�

	//�֐�
public:
	virtual void VDraw(double x,double y,unsigned int color,int fillFlag,int textureHandle)=0;//�`���`�悷��

	//�����蔻��֐��A�����ɍ��W����ǉ�
	HitInfo HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	virtual HitInfo HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual HitInfo HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual HitInfo HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;

	//�����蔻��֐��̎���
	static HitInfo HitJudge(const MyCircle *pshape1, const MyCircle *pshape2,const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2);

};

#endif // !DEF_MYSHAPE_H
