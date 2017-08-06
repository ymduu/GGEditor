#include"DxLib.h"
#include"CircleFactory.h"
#include"MyCircle.h"
#include"EditActionSettings.h"
#include"BattleObject.h"
#include"GGEditor.h"

//-----------------------CircleFactory::CircleFactoryButton-----------------------
CircleFactory::CircleFactoryButton::CircleFactoryButton(Vector2D point,Vector2D vec)
	:ShapeFactoryButton(point,vec){}

void CircleFactory::CircleFactoryButton::ButtonDraw(int font,int fillFlag)const{
	//�����������ă{�^���̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,192),fillFlag);//���g(���傢���߂�����)
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	//�g���̕`��
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,64),FALSE);//�O�g
	//�����蔻��}�`�̕`��
	const int r=20;//���a
	DrawCircle((int)(m_point+m_vec/2).x,(int)(m_point+m_vec/2).y,r,GetColor(255,255,255),TRUE);
}

void CircleFactory::CircleFactoryButton::PushedProcess(EditActionSettings &settings)const{
	settings.m_pShapeFactory=std::shared_ptr<ShapeFactory>(new CircleFactory(m_point,m_vec,GetColor(255,255,0)));
	//���ݑI�����Ă���I�u�W�F�N�g���A�����蔻��}�`��ύX����
	if(settings.m_pBattleObject.get()!=nullptr){
		settings.m_pBattleObject->ChangeShape(settings.m_pShapeFactory->CreateMyShape());
	}
}

//-----------------------CircleFactory-----------------------
CircleFactory::CircleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor)
	:ShapeFactory(buttonPos,buttonSize,lightcolor){}

CircleFactory::~CircleFactory(){}

std::shared_ptr<MyShape> CircleFactory::CreateMyShape()const{
	return std::shared_ptr<MyShape>(new MyCircle((float)GGEditor::baseSize));
}
