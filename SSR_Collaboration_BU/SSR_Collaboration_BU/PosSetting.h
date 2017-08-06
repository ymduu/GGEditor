#ifndef DEF_POSSETTING_H
#define DEF_POSSETTING_H

#include"ButtonHaving.h"

class EditActionSettings;

//�ʒu���킹�ݒ�������N���X�Q�̊��N���X
class PosSetting:public ButtonHaving{
	//�^�E�N���X
public:
	struct PosSettingButton:public Button{
		//�ϐ�
		Vector2D m_point,m_vec;//�ʒu�Ƒ傫��
		std::string m_str;//�\��������
		//�֐�
		PosSettingButton(Vector2D point,Vector2D vec,const std::string &str);
		void ButtonDraw(int font,int fillFlag)const;//�{�^�����̂�`�悷��
		bool JudgeInButton(Vector2D point)const;//�{�^���̒��ɂ��邩�̔���
		bool JudgeButtonPushed()const;//�{�^�����������삪���ꂽ���𔻒肷��
		//virtual void PushedProcess(EditActionSettings &settings)const=0;//�{�^���������ꂽ���ɍs������(�p����Ŏ���)
	};

	//�萔
protected:

	//�ϐ�
protected:
	//�{�^���̃��C�g�A�b�v�̂��߂̏��
	Vector2D m_buttonPos,m_buttonSize;//�{�^���̈ʒu�Ƒ傫��
	unsigned int m_buttonLightColor;//���C�g�A�b�v�̐F

	//�֐�
protected:

public:
	PosSetting(Vector2D buttonPos,Vector2D buttonSize,unsigned int buttonLightColor);
	void DrawPushedButtonLight()const;//�Y������{�^����������Ă���悤�ɕ\������֐�
	virtual void DrawGuide(int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY,Vector2D adjust)const=0;//����ȂǁA�ʒu�ݒ�̎Q�l�ɂȂ���̂�`�悷��
	virtual Vector2D CalculatePos(Vector2D point,const EditActionSettings &settings)const=0;//�����������ʂ̈ʒu��Ԃ�
};

#endif // !DEF_POSSETTING_H
#pragma once
