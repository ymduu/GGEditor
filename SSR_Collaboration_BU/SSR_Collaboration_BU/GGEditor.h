#ifndef DEF_GGEDITOR_H
#define DEF_GGEDITOR_H

#include<vector>
#include<memory>
#include"EditActionSettings.h"
#include"ToolsLib.h"

//�X�e�[�W�G�f�B�^���g
class GGEditor {
	//�񋓑́E�^

	//�萔
public:
	static const int mapSizeX,mapSizeY;//�}�b�v�̕\�������̑傫��
	static const int leftUpPosX,leftUpPosY;//�}�b�v�̍���̍��W
	static const int buttonWidth;//�{�^�������̉���

	//�ϐ�
protected:
	std::vector<std::shared_ptr<BattleObject>> m_objects;//�}�b�v��ɐݒu���Ă���I�u�W�F�N�g�ꗗ
	EditActionSettings m_actionSettings;//���ݍs�����Ƃ��Ă���ҏW�s�ׂ̂܂Ƃ�

	//�֐�
public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	GGEditor();
	~GGEditor();

	//�����[�v�X�V����
	int Calculate();
	void Draw();
};

#endif // !DEF_GGEDITOR_H
#pragma once
