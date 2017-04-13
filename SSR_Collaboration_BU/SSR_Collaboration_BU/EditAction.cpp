#include"DxLib.h"
#include"EditAction.h"

void EditAction::DrawPushedButton(){
	DrawBox(m_buttonX,m_buttonY,m_buttonX+m_buttonDX,m_buttonY+m_buttonDY,m_pushedColor,TRUE);
}
