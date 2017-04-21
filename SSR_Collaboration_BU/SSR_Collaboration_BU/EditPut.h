#ifndef DEF_EDITPUT_H
#define DEF_EDITPUT_H

#include<memory>
#include"EditAction.h"
#include"BattleObject.h"

//画面にオブジェクトを置く行為を記述するクラス
class EditPut :public EditAction {
	//型・列挙体

	//定数

	//変数
protected:
	std::shared_ptr<BattleObject> m_putObject;//配置するオブジェクト
	
	//関数
public:
	EditPut(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditPut() {}

	void VProcessAction(Vector2D point,EditActionSettings &settings);//編集行為を実行する
};

#endif // !DEF_EDITPUT_H
#pragma once
