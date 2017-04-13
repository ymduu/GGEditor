#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

//編集行為を表すクラスのインターフェース
class EditAction {
	//型・列挙体

	//定数

	//変数
protected:
	int m_buttonX,m_buttonY,m_buttonDX,m_buttonDY;//ボタンの位置と大きさ
	unsigned int m_pushedColor;//ボタンが押されている時の色

	//関数
public:
	EditAction(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor)
		:m_buttonX(buttonX),m_buttonY(buttonY),m_buttonDX(buttonDX),m_buttonDY(buttonDY),m_pushedColor(pushedColor){}
	virtual ~EditAction() {}

	virtual void VProcessAction()=0;//編集行為を実行する
	void DrawPushedButton();//該当するボタンが押されているように表示する関数
};


#endif // !DEF_EDITACTION_H
#pragma once
