#ifndef DEF_EDITMOVE_H

#include"EditAction.h"

//�I�u�W�F�N�g����菜��������L�q�����N���X
class EditRemove:public EditAction{
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:

	//�֐�
protected:

public:
	EditRemove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditRemove(){}

	void VProcessAction(Vector2D point,EditActionSettings &settings);
};

#endif // !DEF_EDITMOVE_H
