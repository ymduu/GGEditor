#ifndef DEF_EDITPUT_H
#define DEF_EDITPUT_H

#include"EditAction.h"

//画面にオブジェクトを置く行為を記述するクラス
class EditPut :public EditAction {
	//型・列挙体

	//定数

	//変数
protected:

	//関数
public:
	EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditPut() {}

	void VProcessAction();//編集行為を実行する
};

#endif // !DEF_EDITPUT_H
#pragma once
