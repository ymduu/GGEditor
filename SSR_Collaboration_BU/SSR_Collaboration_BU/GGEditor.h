#ifndef DEF_GGEDITOR_H
#define DEF_GGEDITOR_H

#include<string>
#include<vector>
#include<memory>
#include"EditActionSettings.h"
#include"ToolsLib.h"

//ステージエディタ自身
class GGEditor {
	//列挙体・型
protected:
	

	//定数
public:
	static const int mapSizeX,mapSizeY;//マップの表示部分の大きさ
	static const int leftUpPosX,leftUpPosY;//マップの左上の座標
	static const int buttonWidth,buttonHeight;//ボタン部分の横幅,縦幅
	static const int actButtonHeightNum=2,actButtonWidthNum=2;//「動作」ボタンの縦横の数
	static const std::string actButtonStr[actButtonHeightNum*actButtonWidthNum];//「動作」ボタンに書く文字列

	//変数
protected:
	EditActionSettings m_actionSettings;//現在行おうとしている編集行為と編集データのまとめ

	//描画用データ
	int m_font;//フォント

	//関数
protected:
	//マウスを左クリックした時の動作
	void ProcessMapPush(int mouseX,int mouseY);//マップ画面を押した時の動作

public:
	//コンストラクタとデストラクタ
	GGEditor();
	~GGEditor();

	//毎ループ動作部分
	int Calculate();
	void Draw();

	//静的関数
private:
	static std::shared_ptr<EditAction> EditPutFactory();//オブジェクト設置の編集行為を作る関数
	static std::shared_ptr<EditAction> EditRemoveFactory();//オブジェクト削除の編集行為を作る関数

};

#endif // !DEF_GGEDITOR_H
#pragma once
