#ifndef DEF_EDITACTIONSETTINGS_H
#define DEF_EDITACTIONSETTINGS_H

#include<memory>
#include<vector>
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
	//編集データ
	std::vector<std::shared_ptr<BattleObject>> m_objects;//マップ上に設置しているオブジェクト一覧
	Vector2D m_adjust;//描画の左右補正値(実際のステージのm_adjustの座標点を左上に合わせてエディタに表示)

	//行為についてのデータ
	std::shared_ptr<EditAction> m_pEditAction;//編集行為
	std::shared_ptr<BattleObject> m_pBattleObject;//編集対象
	std::shared_ptr<PosSetting> m_pPosSetting;//位置合わせの手法

	//関数
protected:

public:
	//コンストラクタとデストラクタ
	EditActionSettings(std::shared_ptr<EditAction> pEditAction,std::shared_ptr<BattleObject> pBattleObject,std::shared_ptr<PosSetting> pPosSetting);
	~EditActionSettings();
	//メンバ変数のコピーを返す関数
	Vector2D GetMAdjust()const{
		return m_adjust;
	}
	const std::vector<std::shared_ptr<BattleObject>> *GetPMObject()const{
		return &m_objects;
	}
	//現在行おうとしている編集を実行する
	void PracticeEdit(Vector2D point);
	//普通の関数
	void PushScrollBar(float scrollpx,float maxX,float maxY,int mouseX,int mouseY,int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY);//マップのスクロールバーを押した時の処理
	void PutObject(Vector2D point);
};

#endif // !DEF_EDITACTIONSETTINGS_H
#pragma once
