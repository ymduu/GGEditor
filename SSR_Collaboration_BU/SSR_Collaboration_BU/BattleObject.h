#ifndef DEF_BATTLEOBJECT_H
#define DEF_BATTLEOBJECT_H

//�C���N���[�h�t�@�C��
#include<memory>
#include"ToolsLib.h"
#include"MyShape.h"


//�ʂ̏ꏊ�Ő錾���Ă������ƁB
//struct Position2D;//��ʓI�Ȉʒu��\���\����


//�o�g����ʂɂ�����I�u�W�F�N�g�̊��N���X
class BattleObject {
	//�^

	//�萔

	//�ϐ�
protected:
	
	int m_gHandle;//�I�u�W�F�N�g�̃O���t�B�b�N�n���h��
	int m_kind;//�I�u�W�F�N�g�̕���(�b��I��int�ɂ��Ă���)
	//protected�ɖ߂��܂���(getter�����������)
	Vector2D m_pos;//�I�u�W�F�N�g�̈ʒu
	const std::shared_ptr<MyShape> m_hitJudgeShape;//�����蔻��̌`��

public:
	//�␳����鑤���H(�v���C���[�L�������H)
	bool fixFlag;

	//�֐�
public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	BattleObject(const std::shared_ptr<MyShape> hitJudgeShape,float x,float y,int gHandle,int kind)
		:m_hitJudgeShape(hitJudgeShape),m_pos(x,y),m_gHandle(gHandle),m_kind(kind),fixFlag(false){}
	virtual ~BattleObject() {}

	
	//���z�֐�
	void VDraw(Vector2D adjust=Vector2D(0,0))const;//�`�揈��(�ʒu���炵�܂߂�)
	virtual void VDraw(Vector2D point,Vector2D adjust)const=0;//�`�揈��(�C�Ӎ��W�ɕ`��)
	virtual void VHitProcess(const BattleObject *potherobj)=0;//�����ɓ����������̏���
	virtual std::shared_ptr<BattleObject> VCopy()const=0;//�����I�u�W�F�N�g�𕡐�����(�|�C���^�݈̂قȂ�)

	//�ʏ�֐�
	void ShapeDraw(unsigned int color,int fillFlag,int dx=0,int dy=0)const;//�����蔻��`��Ɋ�Â����`�揈��(dx,dy�̓Y���̒l)
	void PosDraw(unsigned int color,int fillFlag,int size,int dx=0,int dy=0)const;//m_Pos�̈ʒu�ɉ~��`�悷��B
	void Move(Vector2D v);//�x�N�g��v����������(�o�g���̎����ŗp����)
	void Warp(Vector2D v);//�x�N�g��v�֓�����(�X�e�[�W�ҏW�ŗp����)
	void Resize(Vector2D v);//�ʒu�x�N�g��v���Q�l�ɑ傫����ύX����(�X�e�[�W�ҏW�ŗp����)
	bool JudgePointInsideShape(Vector2D point)const;
	float getTop()const;
	float getBottom()const;
	float getLeft()const;
	float getRight()const;
	Vector2D getPos()const;
	Vector2D getResizeVec()const;
	std::shared_ptr<MyShape> getHitJudgeShape()const;
};

#endif // !DEF_BATTLEOBJECT_H
