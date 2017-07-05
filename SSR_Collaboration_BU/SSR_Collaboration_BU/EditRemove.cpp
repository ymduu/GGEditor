#include"EditRemove.h"
#include"EditActionSettings.h"

EditRemove::EditRemove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditRemove::VNonPressEditing(Vector2D point,EditActionSettings &settings)const{
	//�������Ȃ�
}

void EditRemove::VProcessAction(Vector2D point,EditActionSettings &settings)const{
	settings.RemoveObject(point);
}
