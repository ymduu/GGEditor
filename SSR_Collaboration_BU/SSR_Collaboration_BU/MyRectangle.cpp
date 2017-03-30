#include"DxLib.h"
#include"MyRectangle.h"

MyRectangle::MyRectangle(double i_dx,double i_dy)
	:dx(i_dx),dy(i_dy){}

MyRectangle::~MyRectangle() {}

void MyRectangle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//ひとまずテクスチャーを使わずに実装
	DrawBox((int)x,(int)y,(int)(x+dx),(int)(y+dy),color,fillFlag);
}
