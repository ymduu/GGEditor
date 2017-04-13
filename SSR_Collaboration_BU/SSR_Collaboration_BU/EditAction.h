#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

//�ҏW�s�ׂ�\���N���X�̃C���^�[�t�F�[�X
class EditAction {
	//�^�E�񋓑�

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

	virtual void VProcessAction()=0;//�ҏW�s�ׂ����s����
	void DrawPushedButton();//�Y������{�^����������Ă���悤�ɕ\������֐�
};


#endif // !DEF_EDITACTION_H
#pragma once
