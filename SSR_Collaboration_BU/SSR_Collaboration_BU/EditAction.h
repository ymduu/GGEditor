#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

//編集行為を表すクラスのインターフェース
class EditAction {
	//型・列挙体

	//定数

	//変数
protected:

	//関数
public:
	EditAction() {}
	virtual ~EditAction() {}

	virtual void VProcessAction()=0;//編集行為を実行する
	virtual void VDrawPushedButton() = 0;//該当するボタンが押されているように表示する関数
};


#endif // !DEF_EDITACTION_H
#pragma once
