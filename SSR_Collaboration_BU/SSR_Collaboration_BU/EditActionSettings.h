#ifndef DEF_EDITACTIONSETTINGS_H
#define DEF_EDITACTIONSETTINGS_H

#include<memory>
#include"ToolsLib.h"

//�v���g�^�C�v�錾
class EditAction;
class BattleObject;
class PosSetting;

//�X�e�[�W�ҏW�������Ȃ��ۂ́u�����s�����v�̐ݒ���W�񂵂��N���X
class EditActionSettings {
	//�񋓑́E�^

	//�萔

	//�ϐ�
protected:
	const Position2D<double> m_leftUpPos;//�X�e�[�W���g�̕\���̍���̍��W
	Position2D <double> m_adjust;//�`��̍��E�␳�l(���ۂ̃X�e�[�W��m_adjust�̍��W�_������ɍ��킹�ăG�f�B�^�ɕ\��)

	std::shared_ptr<EditAction> m_pEditAction;//�ҏW�s��
	std::weak_ptr<BattleObject> m_pBattleObject;//�ҏW�Ώ�
	std::shared_ptr<PosSetting> m_pPosSetting;//�ʒu���킹�̎�@

	//�֐�
protected:

public:
	EditActionSettings(const Position2D<double> leftUpPos,std::shared_ptr<EditAction> pEditAction,std::weak_ptr<BattleObject> pBattleObject,std::shared_ptr<PosSetting> pPosSetting);
	~EditActionSettings();
};

#endif // !DEF_EDITACTIONSETTINGS_H
#pragma once
