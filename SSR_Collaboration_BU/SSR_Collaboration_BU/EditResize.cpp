#include"EditResize.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditResize::EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

EditResize::~EditResize(){}

void EditResize::VNonPressEditing(Vector2D point,EditActionSettings &settings)const{
	//当たり判定図形に対してResizeを常に行う
	if(settings.m_pBattleObject.get()!=nullptr){
		settings.m_pBattleObject.get()->Resize(point);
	}
}

void EditResize::VProcessAction(Vector2D point,EditActionSettings &settings)const{
	//サイズ変更を行うBattleObjectが決まっているかどうかで行う行為が変わる
	if(settings.m_pBattleObject.get()!=nullptr){
		//編集対象が決まっている場合、そのサイズ変更を行う
		settings.m_pBattleObject.get()->Resize(point);
		settings.InitEditObject();
	} else{
		//編集対象が決まっていない場合、pointの地点にあるBattleObjectを探す
		settings.SetEditObject(point);
	}
}
