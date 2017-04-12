#ifndef DEF_MYANGLEDTRIANGLE_H
#define DEF_MYANGLEDTRIANGLE_H

#include"MyShape.h"

//直角三角形を定義するクラス
//3点は(0,0)(dx,0)(0,dy)で表され、直角頂は(0,0)である。
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
	//図形内に点があるかどうかの判定
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//当たり判定関数
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	//4分木のために上下左右の座標を取得する
	float getTop(Vector2D aPos);
	float getBottom(Vector2D aPos);
	float getLeft(Vector2D aPos);
	float getRight(Vector2D aPos);

};

#endif // !DEF_MYANGLEDTRIANGLE_H
