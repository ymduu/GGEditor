#include"EditPut.h"
#include"EditActionSettings.h"


EditPut::EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
	:EditAction(buttonX,buttonY,buttonDX,buttonDY,pushedColor){}

void EditPut::VProcessAction(Vector2D point,EditActionSettings &settings) {
	settings.PutObject(point);
}
