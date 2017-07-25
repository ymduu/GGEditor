#include"DxLib.h"
#include"MyAngledTriangle.h"
#include"AngledTriangleFactory.h"
#include"EditActionSettings.h"
#include"BattleObject.h"

//-----------------------AngledTriangleFactory::AngledTriangleFactoryButton-----------------------
AngledTriangleFactory::AngledTriangleFactoryButton::AngledTriangleFactoryButton(Vector2D point,Vector2D vec)
	:ShapeFactoryButton(point,vec){}

void AngledTriangleFactory::AngledTriangleFactoryButton::ButtonDraw(int font,int fillFlag)const{
	//半透明化してボタンの描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,192),fillFlag);//内枠(ちょい透過させる)
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	//枠線の描画
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,64),FALSE);//外枠
	//当たり判定図形の描画
	const int halfdx=20,halfdy=20;//大きさ(縦横それぞれ1/2した状態)
	DrawTriangle((int)(m_point+m_vec/2).x-halfdx,(int)(m_point+m_vec/2).y-halfdy,(int)(m_point+m_vec/2).x+halfdx,(int)(m_point+m_vec/2).y+halfdy,(int)(m_point+m_vec/2).x-halfdx,(int)(m_point+m_vec/2).y+halfdy,GetColor(255,255,255),TRUE);
}

void AngledTriangleFactory::AngledTriangleFactoryButton::PushedProcess(EditActionSettings &settings)const{
	settings.m_pShapeFactory=std::shared_ptr<ShapeFactory>(new AngledTriangleFactory(m_point,m_vec,GetColor(255,255,0)));
	//現在選択しているオブジェクトも、当たり判定図形を変更する
	if(settings.m_pBattleObject.get()!=nullptr){
		settings.m_pBattleObject->ChangeShape(settings.m_pShapeFactory->CreateMyShape());
	}
}

//-----------------------AngledTriangleFactory-----------------------
AngledTriangleFactory::AngledTriangleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor)
	:ShapeFactory(buttonPos,buttonSize,lightcolor){}

AngledTriangleFactory::~AngledTriangleFactory(){}

std::shared_ptr<MyShape> AngledTriangleFactory::CreateMyShape()const{
	return std::shared_ptr<MyShape>(new MyAngledTriangle(40,-40));
}

