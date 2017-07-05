#include"EditMove.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

EditMove::EditMove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditMove::VProcessAction(Vector2D point,EditActionSettings &settings){
	//位置変更を行うBattleObjectが決まっているかどうかで行う行為が変わる
	if(settings.m_pBattleObject.get()!=nullptr){
		//編集対象が決まっている場合、その位置変更を行う
		settings.m_pBattleObject.get()->Warp(point+settings.GetMAdjust());
		settings.m_pBattleObject=std::shared_ptr<BattleObject>(nullptr);
	} else{
		//編集対象が決まっていない場合、pointの地点にあるBattleObjectを探す
		settings.SetEditObject(point);
	}
}
