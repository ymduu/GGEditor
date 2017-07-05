#ifndef DEF_EDITRESIZE_H
#define DEF_EDITRESIZE_H

#include"EditAction.h"

class EditResize:public EditAction{
	//型・列挙体

	//定数

	//変数
protected:

	//関数
public:
	EditResize(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditResize();

	void VProcessAction(Vector2D point,EditActionSettings &settings);//編集行為を実行する
};

#endif // !DEF_EDITRESIZE_H
#pragma once
