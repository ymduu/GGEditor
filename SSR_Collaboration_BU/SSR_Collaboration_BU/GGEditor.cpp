#define _USE_MATH_DEFINES	//math.h�̒萔���g�����߂ɕK�{

#include<math.h>

#include"DxLib.h"
#include"GGEditor.h"
#include"input.h"

#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"

#include"EditPut.h"
#include"EditRemove.h"
#include"EditMove.h"
#include"EditResize.h"

#include"RectangleFactory.h"

#include"ScrollBar.h"

//�萔�̒�`
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;
const int GGEditor::buttonHeight=(leftUpPosY*2+mapSizeY)/4;
const int GGEditor::shapeButtonHeightNum=1;
const int GGEditor::shapeButtonWidthNum=3;
const int GGEditor::shapeButtonHeight=GGEditor::buttonHeight/2;
const int GGEditor::shapeButtonWidth=GGEditor::buttonWidth;
const std::string GGEditor::actButtonStr[actButtonHeightNum*actButtonWidthNum]={"put","remove","move","expand"};

//�֐���`
//�ÓI�֐�
std::shared_ptr<EditAction> GGEditor::EditPutFactory(){
	return std::shared_ptr<EditAction>(new EditPut(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0,0,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditRemoveFactory(){
	return std::shared_ptr<EditAction>(new EditRemove(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1,0,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditMoveFactory(){
	return std::shared_ptr<EditAction>(new EditMove(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0,buttonHeight/actButtonHeightNum*1,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

std::shared_ptr<EditAction> GGEditor::EditResizeFactory(){
	return std::shared_ptr<EditAction>(new EditResize(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1,buttonHeight/actButtonHeightNum*1,buttonWidth/actButtonWidthNum,buttonHeight/actButtonHeightNum,GetColor(255,255,0)));
}

//���I�֐�
GGEditor::GGEditor()
	:m_actionSettings(
		//EditPutFactory()
		std::shared_ptr<EditAction>(nullptr)
		,std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false))
		//,std::shared_ptr<ShapeFactory>(new RectangleFactory(Vector2D((float)(leftUpPosX*2+mapSizeX+shapeButtonWidth/shapeButtonWidthNum*0),(float)(buttonHeight+shapeButtonHeight/shapeButtonHeightNum*0)),Vector2D((float)(shapeButtonWidth/shapeButtonWidthNum),(float)(shapeButtonHeight/shapeButtonHeightNum)),GetColor(255,255,0)))
		,std::shared_ptr<ShapeFactory>(nullptr)
		,std::shared_ptr<PosSetting>(nullptr))
{
	//�{�^���ꗗ
	
	//�ŏ����牟����Ă���悤�ɂ���{�^�������X�g�A�b�v���Ȃ���s��
	std::shared_ptr<ButtonHaving::Button> pPutButton,pRectangleFactoryButton;
	
	//��X�N���[���{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D(0,0)
		,Vector2D((float)(leftUpPosX*2+mapSizeX),0)
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)leftUpPosY)
		,Vector2D((float)leftUpPosX,(float)leftUpPosY)
		,Vector2D(0,-1)
	)));
	//���X�N���[���{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D(0,0)
		,Vector2D((float)leftUpPosX,(float)leftUpPosY)
		,Vector2D((float)leftUpPosX,(float)(leftUpPosY+mapSizeY))
		,Vector2D(0,(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(-1,0)
	)));
	//�E�X�N���[���{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX),0)
		,Vector2D((float)(leftUpPosX*2+mapSizeX),(float)(leftUpPosY*2+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)leftUpPosY)
		,Vector2D(1,0)
	)));
	//���X�N���[���{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new ScrollBar::ScrollButton(
		Vector2D((float)leftUpPosX,(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX+mapSizeX),(float)(leftUpPosY+mapSizeY))
		,Vector2D((float)(leftUpPosX*2+mapSizeX),(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(0,(float)(leftUpPosY*2+mapSizeY))
		,Vector2D(0,1)
	)));

	//put�{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditPut::EditPutButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0),0)
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	pPutButton=m_buttons.back();//�ŏ����牟����Ă���悤�ɂ���{�^��
	//remove�{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditRemove::EditRemoveButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1),0)
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	//move�{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditMove::EditMoveButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0),(float)(buttonHeight/actButtonHeightNum*1))
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));
	//resize�{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new EditResize::EditResizeButton(
		Vector2D((float)(leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1),(float)(buttonHeight/actButtonHeightNum*1))
		,Vector2D((float)(buttonWidth/actButtonWidthNum),(float)(buttonHeight/actButtonHeightNum))
	)));

	//RectangleFactory�{�^��
	m_buttons.push_back(std::shared_ptr<ButtonHaving::Button>(new RectangleFactory::RectangleFactoryButton(
		Vector2D(
			(float)(leftUpPosX*2+mapSizeX+shapeButtonWidth/shapeButtonWidthNum*0)
			,(float)(buttonHeight+shapeButtonHeight/shapeButtonHeightNum*0)
		)
		,Vector2D((float)(shapeButtonWidth/shapeButtonWidthNum),(float)(shapeButtonHeight/shapeButtonHeightNum))
	)));
	pRectangleFactoryButton=m_buttons.back();//�ŏ����牟����Ă���悤�ɂ���

	//�ŏ����牟����Ă���悤�ɂ���{�^��������(���Ԃɒ��ӁI)
	pRectangleFactoryButton->PushedProcess(m_actionSettings);
	pPutButton->PushedProcess(m_actionSettings);
	
	//�t�H���g
	m_font=CreateFontToHandle("���C���I",16,1);

	
}

GGEditor::~GGEditor() {
	//�t�H���g
	DeleteFontToHandle(m_font);
}

//�}�E�X�����N���b�N�������̓���Q
void GGEditor::ProcessMapPush(int mouseX,int mouseY){
	//�Q�[����ʏ�̍��W�ɕϊ�(�c��͕`��␳�lm_adjust�݂̂�K�p����΂悢)
	mouseX-=leftUpPosX;
	mouseY-=leftUpPosY;
	//����
	m_actionSettings.PracticeEdit(Vector2D((float)mouseX,(float)mouseY));
}

//��ɍs���ҏW�s��
void GGEditor::NonPressEdit(int mouseX,int mouseY){
	//�Q�[����ʏ�̍��W�ɕϊ�(�c��͕`��␳�lm_adjust�݂̂�K�p����΂悢)
	mouseX-=leftUpPosX;
	mouseY-=leftUpPosY;
	//����
	m_actionSettings.PracticeNonPressEdit(Vector2D((float)mouseX,(float)mouseY));
}

//�����[�v���암���̊֐�
int GGEditor::Calculate() {
	//�}�E�X�̈ʒu�v�Z
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//�}�E�X���͎�t
	NonPressEdit(mouseX,mouseY);

	//�{�^���Q�̓��͔���
	for(std::shared_ptr<ButtonHaving::Button> &pb:m_buttons){
		if(pb.get()->JudgeButtonPushed() && pb.get()->JudgeInButton(GetMousePointVector2D())){
			pb.get()->PushedProcess(m_actionSettings);
			break;
		}
	}

	//���N���b�N�����ꂽ��
	if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
		//�}�b�v��ʓ��Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			ProcessMapPush(mouseX,mouseY);
		}
	}

	//�L�[�{�[�h���͎�t
	if(keyboard_get(KEY_INPUT_NUMPADENTER) == 1){
		return -1;
	}
	return 0;
}

void GGEditor::Draw() {
	//�f�o�b�O�`��
	clsDx();
	printfDx("(%f,%f)\n",GetMousePointVector2D().x,GetMousePointVector2D().y);
	for(auto o:*m_actionSettings.GetPMObject()){
		printfDx("%d\n",o.get());
	}
	printfDx("m_pBattleObject:%d\n",m_actionSettings.m_pBattleObject.get());

	//�}�b�v�̕`��
	//�}�b�v�`��o����͈͂𐧌�
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	//�}�b�v�S�̂̕`��
	bool firstflag=true;
	Vector2D mouse=GetMousePointVector2D()-Vector2D((float)leftUpPosX,(float)leftUpPosY)+m_actionSettings.GetMAdjust();//�}�E�X�̈ʒu(�␳�l���l�����}�b�v��̍��W�ŕ\��)
	Vector2D adjust=Vector2D((float)leftUpPosX,(float)leftUpPosY)-m_actionSettings.GetMAdjust();//�`��̑S�̒����ʒu
	//���݂̕ҏW�Ώې}�`��`��
	if(m_actionSettings.m_pBattleObject.get()!=nullptr){
		int mode,pal;
		GetDrawBlendMode(&mode,&pal);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		m_actionSettings.m_pBattleObject.get()->VDraw(adjust);
		SetDrawBlendMode(mode,pal);
	}
	//�}�b�v�ɑ��݂��Ă�����̂�S�ĕ`��
	for (const std::shared_ptr<BattleObject> &obj : *m_actionSettings.GetPMObject()) {
		//obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
		obj.get()->VDraw(adjust);
		//�}�E�X������Ă���}�`�ɂ͉��F���g��`�悵�t�H�[�J�X��\��
		if(firstflag && obj.get()->JudgePointInsideShape(mouse)){
			obj.get()->ShapeDraw(GetColor(255,255,0),FALSE,(int)(adjust.x),(int)(adjust.y));
			obj.get()->PosDraw(GetColor(255,255,0),TRUE,2,(int)(adjust.x),(int)(adjust.y));
			firstflag=false;
		}
		//�I�𒆂̐}�`�ɂ��Ă͐Ԃ��g��`�悵�t�H�[�J�X��\��
		if(obj.get()==m_actionSettings.m_pBattleObject.get()){
			obj.get()->ShapeDraw(GetColor(255,0,0),FALSE,(int)(adjust.x),(int)(adjust.y));
			obj.get()->PosDraw(GetColor(255,0,0),TRUE,2,(int)(adjust.x),(int)(adjust.y));
		}
	}
	
	//�ҏW�O��BattleObject���}�b�v�ɉ��z�I�ɕ`��
	if(m_actionSettings.GetMPOriginObject()!=nullptr){
		int mode,pal;
		GetDrawBlendMode(&mode,&pal);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		m_actionSettings.GetMPOriginObject()->VDraw(adjust);
		SetDrawBlendMode(mode,pal);
	}
	SetDrawAreaFull();

	//���͂���Ă��铮��̃{�^���̕`��
	m_actionSettings.DrawEditButtonPushed();

	//���͂���Ă���}�`�ݒ�{�^���̕`��
	m_actionSettings.DrawShapeFactoryButtonPushed();
	
	//�{�^���Q�̕`��
	for(std::shared_ptr<ButtonHaving::Button> &pb:m_buttons){
		pb.get()->ButtonDraw(m_font,TRUE);
	}


}
