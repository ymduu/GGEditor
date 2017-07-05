#include"EditResize.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditResize::EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

EditResize::~EditResize(){}

void EditResize::VProcessAction(Vector2D point,EditActionSettings &settings){
	//�T�C�Y�ύX���s��BattleObject�����܂��Ă��邩�ǂ����ōs���s�ׂ��ς��
	if(settings.m_pBattleObject.get()!=nullptr){
		//�ҏW�Ώۂ����܂��Ă���ꍇ�A���̃T�C�Y�ύX���s��
		settings.m_pBattleObject.get()->Resize(point+settings.GetMAdjust());
		settings.m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
	} else{
		//�ҏW�Ώۂ����܂��Ă��Ȃ��ꍇ�Apoint�̒n�_�ɂ���BattleObject��T��
		settings.SetEditObject(point);
	}
}
