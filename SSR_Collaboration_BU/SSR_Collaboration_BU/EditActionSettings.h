#ifndef DEF_EDITACTIONSETTINGS_H
#define DEF_EDITACTIONSETTINGS_H

#include<memory>
#include<vector>
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
	//�ҏW�f�[�^
	std::vector<std::shared_ptr<BattleObject>> m_objects;//�}�b�v��ɐݒu���Ă���I�u�W�F�N�g�ꗗ
	Vector2D m_adjust;//�`��̍��E�␳�l(���ۂ̃X�e�[�W��m_adjust�̍��W�_������ɍ��킹�ăG�f�B�^�ɕ\��)

public:
	//�s�ׂɂ��Ẵf�[�^(GGEditor���Ŏ��R�ɕύX�ł���)
	std::shared_ptr<EditAction> m_pEditAction;//�ҏW�s��
	std::shared_ptr<BattleObject> m_pBattleObject;//�ҏW�Ώ�
	std::shared_ptr<PosSetting> m_pPosSetting;//�ʒu���킹�̎�@

	//�֐�
protected:
	std::vector<std::shared_ptr<BattleObject>>::iterator GetMousePointedObject(Vector2D point);

public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	EditActionSettings(std::shared_ptr<EditAction> pEditAction,std::shared_ptr<BattleObject> pBattleObject,std::shared_ptr<PosSetting> pPosSetting);
	~EditActionSettings();
	//�����o�ϐ��̃R�s�[��Ԃ��֐�
	Vector2D GetMAdjust()const{
		return m_adjust;
	}
	const std::vector<std::shared_ptr<BattleObject>> *GetPMObject()const{
		return &m_objects;
	}
	//���ݍs�����Ƃ��Ă���ҏW�����s����
	void PracticeEdit(Vector2D point);
	//���ʂ̊֐�
	void PushScrollBar(float scrollpx,float maxX,float maxY,int mouseX,int mouseY,int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY);//�}�b�v�̃X�N���[���o�[�����������̏���
	void DrawEditButtonPushed()const;//���ݑI������Ă���ҏW�{�^���ɑ΂��ĉ�����Ă���l�q��`�悷��
	void PutObject(Vector2D point);//���݃}�E�X���w���Ă���ʒu�ɃI�u�W�F�N�g��ݒu����
	void RemoveObject(Vector2D point);//���݃}�E�X���w���Ă���ʒu�ɂ���I�u�W�F�N�g����菜��(vector�̓��̕������菜�����)
	void SetEditObject(Vector2D point);//���݃}�E�X���w���Ă���ʒu�ɂ���I�u�W�F�N�g��ҏW�Ώۂɐݒ肷��

};

#endif // !DEF_EDITACTIONSETTINGS_H
#pragma once
