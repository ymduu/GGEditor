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

	void VNonPressEditing(Vector2D point,EditActionSettings &settings)const;//マウスを押していない時も編集を行う編集行為について、そのような編集行為を行う
	void VProcessAction(Vector2D point,EditActionSettings &settings)const;//編集行為を実行する
};

#endif // !DEF_EDITPUT_H
#pragma once
