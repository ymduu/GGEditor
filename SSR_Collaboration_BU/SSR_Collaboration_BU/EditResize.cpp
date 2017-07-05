#include"EditResize.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditResize::EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

EditResize::~EditResize(){}

void EditResize::VNonPressEditing(Vector2D point,EditActionSettings &settings)const{
	//�����蔻��}�`�ɑ΂���Resize����ɍs��
	if(settings.m_pBattleObject.get()!=nullptr){
		settings.m_pBattleObject.get()->Resize(point);
	}
}

void EditResize::VProcessAction(Vector2D point,EditActionSettings &settings)const{
	//�T�C�Y�ύX���s��BattleObject�����܂��Ă��邩�ǂ����ōs���s�ׂ��ς��
	if(settings.m_pBattleObject.get()!=nullptr){
		//�ҏW�Ώۂ����܂��Ă���ꍇ�A���̃T�C�Y�ύX���s��
		settings.m_pBattleObject.get()->Resize(point);
		settings.InitEditObject();
	} else{
		//�ҏW�Ώۂ����܂��Ă��Ȃ��ꍇ�Apoint�̒n�_�ɂ���BattleObject��T��
		settings.SetEditObject(point);
	}
}
