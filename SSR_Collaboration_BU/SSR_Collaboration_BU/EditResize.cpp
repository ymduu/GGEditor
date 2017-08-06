#include"DxLib.h"
#include"EditResize.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

//---------------------EditResize::EditResizeButton---------------------
EditResize::EditResizeButton::EditResizeButton(Vector2D point,Vector2D vec)
	:EditActionButton(point,vec,"resize"){}

void EditResize::EditResizeButton::PushedProcess(EditActionSettings &settings)const{
	settings.CancelEditing();
	settings.m_pEditAction=std::shared_ptr<EditAction>(new EditResize(
		(int)m_point.x
		,(int)m_point.y
		,(int)m_vec.x
		,(int)m_vec.y
		,GetColor(255,255,0)));;
	settings.InitEditObject();
}



//---------------------EditResize---------------------
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
	if(VGetPosSetKind(settings)==BASEEXIST){
		//�ҏW�Ώۂ����܂��Ă���ꍇ�A���̃T�C�Y�ύX���s��
		settings.m_pBattleObject.get()->Resize(point);
		settings.InitEditObject();
	} else{
		//�ҏW�Ώۂ����܂��Ă��Ȃ��ꍇ�Apoint�̒n�_�ɂ���BattleObject��T��
		settings.SetEditObject(point);
	}
}

EditAction::PosSetKind EditResize::VGetPosSetKind(const EditActionSettings &settings)const{
	if(settings.m_pBattleObject.get()!=nullptr){
		//�ҏW�Ώۂ����܂��Ă���ꍇ
		return BASEEXIST;
	}else{
		//�ҏW�Ώۂ����܂��Ă��Ȃ��ꍇ
		return NONEDIT;
	}
}
