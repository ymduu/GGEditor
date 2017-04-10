#ifndef DEF_GGEDITOR_H
#define DEF_GGEDITOR_H

#include"EditActionSettings.h"

//ステージエディタ自身
class GGEditor {
	//列挙体・型

	//定数

	//変数
protected:
	
	//関数
public:
	//コンストラクタとデストラクタ
	GGEditor();
	~GGEditor();

	//毎ループ更新部分
	int Calculate();
	void Draw();
};

#endif // !DEF_GGEDITOR_H
#pragma once
