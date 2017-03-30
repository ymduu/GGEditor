#ifndef DEF_MYSHAPE_H
#define DEF_MYSHAPE_H


//形状を定義するインターフェース
class MyShape {
	//型・列挙体

	//定数

	//変数

	//関数
public:
	virtual void VDraw(double x,double y,unsigned int color,int fillFlag,int textureHandle)=0;//形状を描画する
};

#endif // !DEF_MYSHAPE_H
