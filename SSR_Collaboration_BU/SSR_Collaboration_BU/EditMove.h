#ifndef DEF_EDITMOVE_H
#define DEF_EDITMOVE_H

#include"EditAction.h"

//�ݒu�ꏊ�𓮂����s�ׂ��L�q����N���X
class EditMove:public EditAction{
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:

	//�֐�
public:
	EditMove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditMove() {}

	void VProcessAction(Vector2D point,EditActionSettings &settings);//�ҏW�s�ׂ����s����
};


#endif // !DEF_EDITMOVE_H
