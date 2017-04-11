#include"EditActionSettings.h"

EditActionSettings::EditActionSettings(const Vector2D leftUpPos, std::shared_ptr<EditAction> pEditAction, std::weak_ptr<BattleObject> pBattleObject, std::shared_ptr<PosSetting> pPosSetting)
	:m_leftUpPos(leftUpPos),m_adjust(0,0),m_pEditAction(pEditAction),m_pBattleObject(pBattleObject),m_pPosSetting(pPosSetting){}

EditActionSettings::~EditActionSettings() {}
