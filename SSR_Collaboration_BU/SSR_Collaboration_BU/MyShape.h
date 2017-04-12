#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H
#include "ToolsLib.h"

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

	//当たり判定関数、引数に座標情報を追加
	HitInfo HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos);
	virtual HitInfo HitJudge(const MyCircle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual HitInfo HitJudge(const MyRectangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;
	virtual HitInfo HitJudge(const MyAngledTriangle *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) = 0;

	//当たり判定関数の実体
	static HitInfo HitJudge(const MyCircle *pshape1, const MyCircle *pshape2,const Vector2D aMyPos, const Vector2D aOtherPos);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2);
	static HitInfo HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2);
	static HitInfo HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2);

};

#endif // !DEF_MYSHAPE_H
