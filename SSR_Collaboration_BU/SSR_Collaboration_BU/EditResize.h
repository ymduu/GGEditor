#ifndef DEF_EDITRESIZE_H
#define DEF_EDITRESIZE_H

#include"EditAction.h"

class EditResize:public EditAction{
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditResize();

	void VProcessAction(Vector2D point,EditActionSettings &settings);//�ҏW�s�ׂ����s����
};

#endif // !DEF_EDITRESIZE_H
#pragma once
