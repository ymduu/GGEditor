#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

//�ҏW�s�ׂ�\���N���X�̃C���^�[�t�F�[�X
class EditAction {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditAction() {}
	virtual ~EditAction() {}

	virtual void VProcessAction()=0;//�ҏW�s�ׂ����s����
	virtual void VDrawPushedButton() = 0;//�Y������{�^����������Ă���悤�ɕ\������֐�
};


#endif // !DEF_EDITACTION_H
#pragma once
