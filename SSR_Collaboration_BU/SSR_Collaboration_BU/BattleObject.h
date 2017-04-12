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
	const std::shared_ptr<MyShape> m_hitJudgeShape;//�����蔻��̌`��
	Vector2D m_pos;//�I�u�W�F�N�g�̈ʒu
	int m_gHandle;//�I�u�W�F�N�g�̃O���t�B�b�N�n���h��
	int m_kind;//�I�u�W�F�N�g�̕���(�b��I��int�ɂ��Ă���)

	//�֐�
public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	BattleObject(const std::shared_ptr<MyShape> hitJudgeShape,float x,float y,int gHandle,int kind)
		:m_hitJudgeShape(hitJudgeShape),m_pos(x,y),m_gHandle(gHandle),m_kind(kind){}
	virtual ~BattleObject() {}

	//���z�֐�
	virtual void VDraw(int x=0,int y=0)=0;//�`�揈��(�ʒu���炵�܂߂�)
	virtual void VHitProcess(const BattleObject *potherobj)=0;//�����ɓ����������̏���

	//�ʏ�֐�
	void ShapeDraw(unsigned int color,int fillFlag,int dx=0,int dy=0);//�����蔻��`��Ɋ�Â����`�揈��(dx,dy�̓Y���̒l)
	void Move(float x,float y);
	bool JudgePointInsideShape(Vector2D point);
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
};

#endif // !DEF_BATTLEOBJECT_H
