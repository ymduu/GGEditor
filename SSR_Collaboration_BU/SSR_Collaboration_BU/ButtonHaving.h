#ifndef DEF_BUTTONHAVING_H
#define DEF_BUTTONHAVING_H

#include"ToolsLib.h"

class EditActionSettings;

//���̃N���X���p�����Ă���ꍇ�͑Ή�����{�^�����K�����݂���
//�{�^���������ƑΉ�����N���X��EditActionSettings�̒��ɓ���悤�ɂȂ�

class ButtonHaving{
	//�^�E�񋓑�
public:
	struct Button{
		//Factory�N���X���`��N���X
		virtual void ButtonDraw(int font,int fillFlag)const=0;//�{�^�����̂�`�悷��
		virtual bool JudgeInButton(Vector2D point)const=0;//�{�^���̒��ɂ��邩�̔���
		virtual bool JudgeButtonPushed()const=0;//�{�^���������ꂽ���𔻒肷��
		virtual void PushedProcess(EditActionSettings &settings)const=0;//�{�^���������ꂽ���ɍs������
	};

	//�萔

	//�ϐ�

	//�֐�

};

#endif // !DEF_BUTTONHAVING_H
#pragma once
