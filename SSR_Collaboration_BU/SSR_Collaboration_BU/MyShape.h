#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H
#include "ToolsLib.h"

#include"ToolsLib.h"

class MyCircle;
class MyRectangle;
class MyAngledTriangle;

//�`����`����C���^�[�t�F�[�X
class MyShape {
	//�^�E�񋓑�
public:
	//�萔

	//�ϐ�

	//�֐�
public:
	virtual void VDraw(float x,float y,unsigned int color,int fillFlag,int textureHandle)=0;//�`���`�悷��

	//�}�`���ɓ_�����邩�ǂ����̔���
	virtual bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)=0;
	
	//�����蔻��֐��A�����ɍ��W����ǉ�
	bool HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	virtual bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;

	//�����蔻��֐��̎���
	static bool HitJudge(const MyCircle *pshape1, const MyCircle *pshape2,const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static bool HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);

	//�O�ڎl�p�`�̏㉺���E���擾(4���؂ɓo�^���邽��)
	virtual float getTop(Vector2D aPos) = 0;
	virtual float getBottom(Vector2D aPos) = 0;
	virtual float getLeft(Vector2D aPos) = 0;
	virtual float getRight(Vector2D aPos) = 0;
};

#endif // !DEF_MYSHAPE_H
