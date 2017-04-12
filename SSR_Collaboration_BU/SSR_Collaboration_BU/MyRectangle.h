#ifndef DEF_MYRECTANGLE_H
#define DEF_MYRECTANGLE_H

#include"MyShape.h"

//長方形を定義するクラス
class MyRectangle:public MyShape {
	//型・列挙体

	//定数

	//変数
protected:
	double dx, dy;//大きさ

	//関数
public:
	MyRectangle(double i_dx,double i_dy);
	~MyRectangle();
	void VDraw(double x, double y, unsigned int color, int fillFlag, int textureHandle);//形状を描画する
	//図形内に点があるかどうかの判定
	bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos);
	//当たり判定関数
	bool VHitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	bool VHitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	//四角形そのものの座標と点を引数に取り、最近傍の点を返す
	Vector2D GetNearestPoint(Vector2D rectanglePos , Vector2D p)const;	
	//上下左右の座標を取得(4分木のため)
	float getTop(Vector2D aPos);
	float getBottom(Vector2D aPos);
	float getLeft(Vector2D aPos);
	float getRight(Vector2D aPos);


};

#endif // !DEF_MYRECTANGLE_H
