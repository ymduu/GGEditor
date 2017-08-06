#ifndef DEF_EDITRESIZE_H
#define DEF_EDITRESIZE_H

#include"EditAction.h"

class EditResize:public EditAction{
	//�^�E�񋓑�
public:
	struct EditResizeButton:public EditActionButton{
		EditResizeButton(Vector2D point,Vector2D vec);
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���̏���
	};

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditResize();

	void VNonPressEditing(Vector2D point,EditActionSettings &settings)const;//�}�E�X�������Ă��Ȃ������ҏW���s���ҏW�s�ׂɂ��āA���̂悤�ȕҏW�s�ׂ��s��
	void VProcessAction(Vector2D point,EditActionSettings &settings)const;//�ҏW�s�ׂ����s����
	PosSetKind VGetPosSetKind(const EditActionSettings &settings)const;//�ҏW�󋵂Ɉ˂��ĕԂ��l���قȂ邽��
};

#endif // !DEF_EDITRESIZE_H
#pragma once
