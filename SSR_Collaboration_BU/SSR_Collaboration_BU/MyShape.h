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
	struct HitInfo {
		//�����蔻����s������ɕԂ����
		bool judge;
		Vector2D fixVec;	//�␳�x�N�g��
		
				//�R���X�g���N�^
		HitInfo(bool i_judge,Vector2D v)
			:judge(i_judge),fixVec(Vector2D(v.x,v.y)) {}
		
	};
	//�ϐ�

	//�֐�
public:
	virtual void VDraw(float x,float y,unsigned int color,int fillFlag,int textureHandle)const=0;//�`���`�悷��

	//�}�`���ɓ_�����邩�ǂ����̔���
	virtual bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)const=0;
	
	//�����蔻��֐��A�����ɍ��W����ǉ�
	HitInfo HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const;
	virtual HitInfo VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const = 0;
	virtual HitInfo VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const = 0;
	virtual HitInfo VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const = 0;

	//�����蔻��֐��̎���
	static HitInfo HitJudge(const MyCircle *pshape1, const MyCircle *pshape2,const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos);

	//�O�ڎl�p�`�̏㉺���E���擾(4���؂ɓo�^���邽��)
	virtual float getTop(Vector2D aPos)const = 0;
	virtual float getBottom(Vector2D aPos)const = 0;
	virtual float getLeft(Vector2D aPos)const = 0;
	virtual float getRight(Vector2D aPos)const = 0;
};

#endif // !DEF_MYSHAPE_H
