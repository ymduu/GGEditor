#include"DxLib.h"
#include"RectangleFactory.h"
#include"EditActionSettings.h"
#include"MyRectangle.h"
#include"BattleObject.h"
#include"GGEditor.h"

//--------------------------RectangleFactory::RectangleFactoryButton--------------------------
RectangleFactory::RectangleFactoryButton::RectangleFactoryButton(Vector2D point,Vector2D vec)
	:ShapeFactoryButton(point,vec){}

void RectangleFactory::RectangleFactoryButton::ButtonDraw(int font,int fillFlag)const{
	//�����������ă{�^���̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,192),fillFlag);//���g(���傢���߂�����)
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	//�g���̕`��
	DrawBox((int)m_point.x,(int)m_point.y,(int)(m_point+m_vec).x,(int)(m_point+m_vec).y,GetColor(192,192,64),FALSE);//�O�g
	//�����蔻��}�`�̕`��
	const int halfdx=20,halfdy=20;//�傫��(�c�����ꂼ��1/2�������)
	DrawBox((int)(m_point+m_vec/2).x-halfdx,(int)(m_point+m_vec/2).y-halfdy,(int)(m_point+m_vec/2).x+halfdx,(int)(m_point+m_vec/2).y+halfdy,GetColor(255,255,255),TRUE);
}

void RectangleFactory::RectangleFactoryButton::PushedProcess(EditActionSettings &settings)const{
	//pShapeFactory��ύX����
	settings.m_pShapeFactory=std::shared_ptr<ShapeFactory>(new RectangleFactory(m_point,m_vec,GetColor(255,255,0)));
	//���ݑI�����Ă���I�u�W�F�N�g���A�����蔻��}�`��ύX����
	if(settings.m_pBattleObject.get()!=nullptr){
		settings.m_pBattleObject->ChangeShape(settings.m_pShapeFactory->CreateMyShape());
	}
}

//--------------------------RectangleFactory--------------------------
RectangleFactory::RectangleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor)
	:ShapeFactory(buttonPos,buttonSize,lightcolor){}

RectangleFactory::~RectangleFactory(){}

std::shared_ptr<MyShape> RectangleFactory::CreateMyShape()const{
	return std::shared_ptr<MyShape>(new MyRectangle((float)GGEditor::baseSize,(float)GGEditor::baseSize));
}
