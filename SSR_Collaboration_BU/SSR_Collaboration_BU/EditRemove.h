#ifndef DEF_EDITMOVE_H

#include"EditAction.h"

//�I�u�W�F�N�g����菜��������L�q�����N���X
class EditRemove:public EditAction{
	//�^�E�񋓑�
public:
	struct EditRemoveButton:public EditActionButton{
		EditRemoveButton(Vector2D point,Vector2D vec);
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���̏���
	};

	//�萔

	//�ϐ�
protected:

	//�֐�
protected:

public:
	EditRemove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditRemove(){}

	void VNonPressEditing(Vector2D point,EditActionSettings &settings)const;//�}�E�X�������Ă��Ȃ������ҏW���s���ҏW�s�ׂɂ��āA���̂悤�ȕҏW�s�ׂ��s��
	void VProcessAction(Vector2D point,EditActionSettings &settings)const;
};

#endif // !DEF_EDITMOVE_H
