#ifndef DEF_EDITPUT_H
#define DEF_EDITPUT_H

#include"EditAction.h"

//��ʂɃI�u�W�F�N�g��u���s�ׂ��L�q����N���X
class EditPut :public EditAction {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditPut() {}
	~EditPut() {}

	void VProcessAction();//�ҏW�s�ׂ����s����
	void VDrawPushedButton();//�Y������{�^����������Ă���悤�ɕ\������֐�
};

#endif // !DEF_EDITPUT_H
#pragma once
