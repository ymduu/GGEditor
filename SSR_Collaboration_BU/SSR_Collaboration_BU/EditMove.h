#ifndef DEF_EDITMOVE_H
#define DEF_EDITMOVE_H

#include"EditAction.h"

//�ݒu�ꏊ�𓮂����s�ׂ��L�q����N���X
class EditMove:public EditAction{
	//�^�E�񋓑�
public:
	struct EditMoveButton:public EditActionButton{
		EditMoveButton(Vector2D point,Vector2D vec);
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���̏���
	};

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditMove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditMove() {}

	void VNonPressEditing(Vector2D point,EditActionSettings &settings)const;//�}�E�X�������Ă��Ȃ������ҏW���s���ҏW�s�ׂɂ��āA���̂悤�ȕҏW�s�ׂ��s��
	void VProcessAction(Vector2D point,EditActionSettings &settings)const;//�ҏW�s�ׂ����s����
};


#endif // !DEF_EDITMOVE_H
