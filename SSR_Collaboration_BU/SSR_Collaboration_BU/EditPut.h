#ifndef DEF_EDITPUT_H
#define DEF_EDITPUT_H

#include<memory>
#include"EditAction.h"
#include"BattleObject.h"

//��ʂɃI�u�W�F�N�g��u���s�ׂ��L�q����N���X
class EditPut :public EditAction {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:
	std::shared_ptr<BattleObject> m_putObject;//�z�u����I�u�W�F�N�g
	
	//�֐�
public:
	EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditPut() {}

	void VProcessAction(Vector2D point,EditActionSettings &settings);//�ҏW�s�ׂ����s����
};

#endif // !DEF_EDITPUT_H
#pragma once
