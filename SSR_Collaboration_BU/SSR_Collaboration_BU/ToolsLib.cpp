#include"ToolsLib.h"
#include"DxLib.h"

Vector2D GetMousePointVector2D(){
	int x,y;
	GetMousePoint(&x,&y);
	return Vector2D((float)x,(float)y);
}
