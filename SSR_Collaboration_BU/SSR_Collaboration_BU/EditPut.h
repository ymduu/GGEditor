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
	EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditPut() {}

	void VNonPressEditing(Vector2D point,EditActionSettings &settings)const;//�}�E�X�������Ă��Ȃ������ҏW���s���ҏW�s�ׂɂ��āA���̂悤�ȕҏW�s�ׂ��s��
	void VProcessAction(Vector2D point,EditActionSettings &settings)const;//�ҏW�s�ׂ����s����
};

#endif // !DEF_EDITPUT_H
#pragma once
