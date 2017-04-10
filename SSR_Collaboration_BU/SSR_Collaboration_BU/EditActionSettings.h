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
	const Position2D<double> m_leftUpPos;//ステージ自身の表示の左上の座標
	Position2D <double> m_adjust;//描画の左右補正値(実際のステージのm_adjustの座標点を左上に合わせてエディタに表示)

	std::shared_ptr<EditAction> m_pEditAction;//編集行為
	std::weak_ptr<BattleObject> m_pBattleObject;//編集対象
	std::shared_ptr<PosSetting> m_pPosSetting;//位置合わせの手法

	//関数
protected:

public:
	EditActionSettings(const Position2D<double> leftUpPos,std::shared_ptr<EditAction> pEditAction,std::weak_ptr<BattleObject> pBattleObject,std::shared_ptr<PosSetting> pPosSetting);
	~EditActionSettings();
};

#endif // !DEF_EDITACTIONSETTINGS_H
#pragma once
