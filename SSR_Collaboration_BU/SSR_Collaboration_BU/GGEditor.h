#ifndef DEF_GGEDITOR_H
#define DEF_GGEDITOR_H

#include<string>
#include<vector>
#include<memory>
#include"EditActionSettings.h"
#include"ToolsLib.h"

//�X�e�[�W�G�f�B�^���g
class GGEditor {
	//�񋓑́E�^
protected:
	

	//�萔
public:
	static const int mapSizeX,mapSizeY;//�}�b�v�̕\�������̑傫��
	static const int leftUpPosX,leftUpPosY;//�}�b�v�̍���̍��W
	static const int buttonWidth,buttonHeight;//�{�^�������̉���,�c��
	static const int actButtonHeightNum=2,actButtonWidthNum=2;//�u����v�{�^���̏c���̐�
	static const std::string actButtonStr[actButtonHeightNum*actButtonWidthNum];//�u����v�{�^���ɏ���������

	//�ϐ�
protected:
	EditActionSettings m_actionSettings;//���ݍs�����Ƃ��Ă���ҏW�s�ׂƕҏW�f�[�^�̂܂Ƃ�

	//�`��p�f�[�^
	int m_font;//�t�H���g

	//�֐�
protected:
	//�}�E�X�����N���b�N�������̓���
	void ProcessMapPush(int mouseX,int mouseY);//�}�b�v��ʂ����������̓���

public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	GGEditor();
	~GGEditor();

	//�����[�v���암��
	int Calculate();
	void Draw();

	//�ÓI�֐�
private:
	static std::shared_ptr<EditAction> EditPutFactory();//�I�u�W�F�N�g�ݒu�̕ҏW�s�ׂ����֐�
	static std::shared_ptr<EditAction> EditRemoveFactory();//�I�u�W�F�N�g�폜�̕ҏW�s�ׂ����֐�

};

#endif // !DEF_GGEDITOR_H
#pragma once
