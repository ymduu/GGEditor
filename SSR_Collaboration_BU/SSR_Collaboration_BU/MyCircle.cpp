#include"DxLib.h"
#include"MyCircle.h"

MyCircle::MyCircle(double i_r):r(i_r) {}

MyCircle::~MyCircle() {}

void MyCircle::VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle) {
	//�ЂƂ܂��e�N�X�`���[���g�킸�Ɏ���
	DrawCircle((int)x, (int)y ,(int)r, color, fillFlag);
}
