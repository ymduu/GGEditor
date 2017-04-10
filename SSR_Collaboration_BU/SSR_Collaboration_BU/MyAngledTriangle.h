#ifndef DEF_MYANGLEDTRIANGLE_H
#define DEF_MYANGLEDTRIANGLE_H

#include"MyShape.h"

//直角三角形を定義するクラス
class MyAngledTriangle :public MyShape {
	//列挙体・型
	//定数
	//変数
protected:
	double vx, vy;//直角頂からのx,y方向の正の方向ベクトルの長さ。負の値だと負の方向に伸びている事を示している。
	//関数
public:
	MyAngledTriangle(double i_vx,double i_vy);
	~MyAngledTriangle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);
};

#endif // !DEF_MYANGLEDTRIANGLE_H
