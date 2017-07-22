#ifndef DEF_SCROLLBAR_H
#define DEF_SCROLLBAR_H

#include"ButtonHaving.h"

//�X�N���[���o�[���Ǘ�����N���X
//�㉺���E�̃X�N���[���o�[�S�ĂɑΉ��ł���悤�ɂ��邽�߁A�{�^���̈ʒu��萔�ɂ��Ȃ�
class ScrollBar:public ButtonHaving{
	//�^
public:
	struct ScrollButton:public Button{
		//�ϐ�
		static const int vNum=4;//���_��
		Vector2D m_point[vNum];//�X�N���[���o�[�𐬂��S�_
		Vector2D m_move;//�{�^�������������ɓ����x�N�g��
		
			//�F�E�h��Ԃ��̉ۂȂǂ͌Œ肵�āA�\�[�X�R�[�h�Ƀx�^��������

		//�֐�
		ScrollButton(Vector2D p1,Vector2D p2,Vector2D p3,Vector2D p4,Vector2D v);
		void ButtonDraw(int font,int fillFlag)const;//�{�^�����̂�`�悷��
		bool JudgeInButton(Vector2D point)const;//�{�^���̒��ɂ��邩�̔���
		bool JudgeButtonPushed()const;//�{�^���������ꂽ���𔻒肷��
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���ɍs������
	};
	//�萔
	
	//ScrollBar�N���X�͍���鎖�͂Ȃ��̂ŕϐ��E�֐��͎������Ȃ�

	//�ϐ�
protected:
	

	//�֐�
public:
	
};

#endif // !DEF_SCROLLBAR_H
#pragma once
