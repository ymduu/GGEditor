#ifndef DEF_CONSTPOSSET_H
#define DEF_CONSTPOSSET_H

#include"PosSetting.h"

//�萔�s�N�Z���̕���ɍ��킹�Ĉʒu�ݒ������N���X
//1�s�N�Z���ɂ��鎖�Ŋ��S���R�Ȉʒu�ݒ肪�ł���悤�ɂȂ�
class ConstPosSet:public PosSetting{
	//�^�E�񋓑�
public:
	struct ConstPosSetButton:public PosSettingButton{
		const int m_gridSetSize;//�{�^�����������Ƃō��ConstPosSet�N���X��m_gridSize�̏������ɗp����
		ConstPosSetButton(Vector2D point,Vector2D vec,int gridSetSize);
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���ɍs������
	};
	//�萔

	//�ϐ�
protected:
	const int m_gridSize;//����̃T�C�Y(�R���X�g���N�^�ɂ��1�ȏ�ɂȂ�)

	//�֐�
protected:
	Vector2D CalculateClosestVertex(Vector2D point,Vector2D vec)const;//point����vec�Ƌt���ɂ���ŋߖT�̐����`�̒��_�̍��W��Ԃ�

public:
	ConstPosSet(Vector2D buttonPos,Vector2D buttonSize,unsigned int buttonLightColor,int gridSize);
	void DrawGuide(int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY,Vector2D adjust)const;//����ȂǁA�ʒu�ݒ�̎Q�l�ɂȂ���̂�`�悷��
	Vector2D CalculatePos(Vector2D point,const EditActionSettings &settings)const;//�����������ʂ̈ʒu��Ԃ��Bpoint�̓Q�[����̍��W�ƂȂ�(=adjust�ɂ��ʒu�C���܂ŏI�����Ă���)�B
};

#endif // !DEF_CONSTPOSSET_H
#pragma once
