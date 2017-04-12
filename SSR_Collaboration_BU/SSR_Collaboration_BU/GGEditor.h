#ifndef DEF_GGEDITOR_H
#define DEF_GGEDITOR_H

#include<vector>
#include<memory>
#include"EditActionSettings.h"
#include"ToolsLib.h"

//ステージエディタ自身
class GGEditor {
	//列挙体・型

	//定数
public:
	static const int mapSizeX,mapSizeY;//マップの表示部分の大きさ
	static const int leftUpPosX,leftUpPosY;//マップの左上の座標
	static const int buttonWidth;//ボタン部分の横幅

	//変数
protected:
	std::vector<std::shared_ptr<BattleObject>> m_objects;//マップ上に設置しているオブジェクト一覧
	EditActionSettings m_actionSettings;//現在行おうとしている編集行為のまとめ

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
