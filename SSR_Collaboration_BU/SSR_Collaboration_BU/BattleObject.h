#ifndef DEF_BATTLEOBJECT_H
#define DEF_BATTLEOBJECT_H

//�C���N���[�h�t�@�C��
#include<boost\shared_ptr.hpp>
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
	const boost::shared_ptr<MyShape> m_hitJudgeShape;//�����蔻��̌`��
	Position2D<double> m_pos;//�I�u�W�F�N�g�̈ʒu
	int m_gHandle;//�I�u�W�F�N�g�̃O���t�B�b�N�n���h��
	int m_kind;//�I�u�W�F�N�g�̕���(�b��I��int�ɂ��Ă���)

	//�֐�
public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	BattleObject(const boost::shared_ptr<MyShape> hitJudgeShape,double x,double y,int gHandle,int kind)
		:m_hitJudgeShape(hitJudgeShape),m_pos(x,y),m_gHandle(gHandle),m_kind(kind){}
	virtual ~BattleObject() {}

	//���z�֐�
	virtual void VDraw()=0;//�`�揈��
	virtual void VHitProcess(const BattleObject *potherobj)=0;//�����ɓ����������̏���

	//�ʏ�֐�
	void Move(double x, double y) {
		m_pos.x = x;
		m_pos.y = y;
	}
};

#endif // !DEF_BATTLEOBJECT_H
