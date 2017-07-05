#ifndef DEF_EDITACTION_H
#define DEF_EDITACTION_H

#include"ToolsLib.h"
class EditActionSettings;

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
	virtual void VNonPressEditing(Vector2D point,EditActionSettings &settings)const=0;//マウスを押していない時も編集を行う編集行為について、そのような編集行為を行う
	virtual void VProcessAction(Vector2D point,EditActionSettings &settings)const=0;//マップ上の点の座標を取得しsettingsに対し編集行為を実行する
	void DrawPushedButton();//該当するボタンが押されているように表示する関数
};


#endif // !DEF_EDITACTION_H
#pragma once
