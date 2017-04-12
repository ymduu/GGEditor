#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H

#include"ToolsLib.h"

class MyCircle;
class MyRectangle;
class MyAngledTriangle;

//形状を定義するインターフェース
class MyShape {
	//型・列挙体
public:
	struct HitInfo {
		//当たり判定を行った後に返す情報
		bool judge;

		//コンストラクタ
		HitInfo(bool i_judge)
			:judge(i_judge){}
	};
	//定数

	//変数

	//関数
public:
	virtual void VDraw(double x,double y,unsigned int color,int fillFlag,int textureHandle)=0;//形状を描画する

	//図形内に点があるかどうかの判定
	virtual bool VJudgePosintInsideShape(const Vector2D point,const Vector2D shapePos)=0;
	
	//当たり判定関数
	HitInfo HitJudge(const MyShape *pshape);

protected:
	virtual HitInfo VHitJudge(const MyCircle *pshape) = 0;
	virtual HitInfo VHitJudge(const MyRectangle *pshape) = 0;
	virtual HitInfo VHitJudge(const MyAngledTriangle *pshape) = 0;

	//当たり判定関数の実体
	static HitInfo HitJudge(const MyCircle *pshape1, const MyCircle *pshape2);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2);

};

#endif // !DEF_MYSHAPE_H
