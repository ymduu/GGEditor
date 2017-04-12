#ifndef DEF_EDITACTIONSETTINGS_H
#define DEF_EDITACTIONSETTINGS_H

#include<memory>
#include"ToolsLib.h"

//プロトタイプ宣言
class EditAction;
class BattleObject;
class PosSetting;

//ステージ編集をおこなう際の「何を行うか」の設定を集約したクラス
class EditActionSettings {
	//列挙体・型

	//定数

	//変数
protected:
	Vector2D m_adjust;//描画の左右補正値(実際のステージのm_adjustの座標点を左上に合わせてエディタに表示)

	std::shared_ptr<EditAction> m_pEditAction;//編集行為
	std::weak_ptr<BattleObject> m_pBattleObject;//編集対象
	std::shared_ptr<PosSetting> m_pPosSetting;//位置合わせの手法

	//関数
protected:

public:
	//コンストラクタとデストラクタ
	EditActionSettings(std::shared_ptr<EditAction> pEditAction,std::weak_ptr<BattleObject> pBattleObject,std::shared_ptr<PosSetting> pPosSetting);
	~EditActionSettings();
	//メンバ関数のコピーを返す関数
	Vector2D GetMAdjust(){
		return m_adjust;
	}
	//普通の関数
	void PushScrollBar(float scrollpx,float maxX,float maxY,int mouseX,int mouseY,int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY);//マップのスクロールバーを押した時の処理
};

#endif // !DEF_EDITACTIONSETTINGS_H
#pragma once
