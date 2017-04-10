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
	EditPut() {}
	~EditPut() {}

	void VProcessAction();//編集行為を実行する
	void VDrawPushedButton();//該当するボタンが押されているように表示する関数
};

#endif // !DEF_EDITPUT_H
#pragma once
