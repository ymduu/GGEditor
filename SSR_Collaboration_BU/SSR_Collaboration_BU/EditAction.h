#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

#include"ButtonHaving.h"

//�ҏW�s�ׂ�\���N���X�̃C���^�[�t�F�[�X
class EditAction:public ButtonHaving{
	//�^�E�񋓑�
public:
	struct EditActionButton:public Button{
		//���̃N���X�̐}�`�͑S�Ē����`
		//�ϐ�
		Vector2D m_point;//����̒��_�̍��W
		Vector2D m_vec;//�Ίp���̃x�N�g��
		std::string m_str;//�{�^�����ɕ`�悷�镶����
		//�֐�
		EditActionButton(Vector2D point,Vector2D vec,const std::string &str);
		void ButtonDraw(int font,int fillFlag)const;//�{�^�����̂�`�悷��
		bool JudgeInButton(Vector2D point)const;//�{�^���̒��ɂ��邩�̔���
		bool JudgeButtonPushed()const;//�{�^�����������삪���ꂽ���𔻒肷��
		//void PushedProcess(EditActionSettings &settings)const;//�p����Ŏ���
	};
	//�萔

	//�ϐ�
protected:
	int m_buttonX,m_buttonY,m_buttonDX,m_buttonDY;//�{�^���̈ʒu�Ƒ傫��
	unsigned int m_pushedColor;//�{�^����������Ă��鎞�̐F

	//�֐�
public:
	EditAction(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
		:m_buttonX(buttonX),m_buttonY(buttonY),m_buttonDX(buttonDX),m_buttonDY(buttonDY),m_pushedColor(pushedColor){}
	virtual ~EditAction() {}
	virtual void VNonPressEditing(Vector2D point,EditActionSettings &settings)const=0;//�}�E�X�������Ă��Ȃ������ҏW���s���ҏW�s�ׂɂ��āA���̂悤�ȕҏW�s�ׂ��s��
	virtual void VProcessAction(Vector2D point,EditActionSettings &settings)const=0;//�}�b�v��̓_�̍��W���擾��settings�ɑ΂��ҏW�s�ׂ����s����
	void DrawPushedButton();//�Y������{�^����������Ă���悤�ɕ\������֐�
};


#endif // !DEF_EDITACTION_H
#pragma once
