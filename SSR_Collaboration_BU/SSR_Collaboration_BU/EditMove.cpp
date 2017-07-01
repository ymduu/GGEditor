#include"EditMove.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditMove::EditMove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditMove::VProcessAction(Vector2D point,EditActionSettings &settings){
	//�ʒu�ύX���s��BattleObject�����܂��Ă��邩�ǂ����ōs���s�ׂ��ς��
	if(settings.m_pBattleObject.get()!=nullptr){
		//�ҏW�Ώۂ����܂��Ă���ꍇ�A���̈ʒu�ύX���s��
		settings.m_pBattleObject.get()->Warp(point);
		settings.m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
	} else{
		//�ҏW�Ώۂ����܂��Ă��Ȃ��ꍇ�Apoint�̒n�_�ɂ���BattleObject��T��
		settings.SetEditObject(point);
	}
}
