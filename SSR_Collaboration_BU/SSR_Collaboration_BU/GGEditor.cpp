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
#include"ScrollBar.h"

//�萔�̒�`
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;
const int GGEditor::buttonHeight=(leftUpPosY*2+mapSizeY)/4;
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
	:m_actionSettings(EditPutFactory()
		,std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false))
		,std::shared_ptr<PosSetting>(nullptr))
{
	//�{�^���ꗗ
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
	}else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseY>=0 && mouseY<buttonHeight/actButtonHeightNum*1){
		//�ݒu�{�^���Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.CancelEditing();
			m_actionSettings.m_pEditAction=EditPutFactory();
			m_actionSettings.m_pBattleObject=std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40)),0,0,-1,0,GetColor(128,128,128),false));
		}
	}else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*2 && mouseY>=0 && mouseY<buttonHeight/actButtonHeightNum*1){
		//���O�{�^���Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.CancelEditing();
			m_actionSettings.m_pEditAction=EditRemoveFactory();
			m_actionSettings.InitEditObject();
		}
	}else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*0 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseY>=buttonHeight/actButtonHeightNum*1 && mouseY<buttonHeight/actButtonHeightNum*2){
		//�ύX�{�^���Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.CancelEditing();
			m_actionSettings.m_pEditAction=EditMoveFactory();
			m_actionSettings.InitEditObject();
		}
	}else if(mouseX>=leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*1 && mouseX<leftUpPosX*2+mapSizeX+buttonWidth/actButtonWidthNum*2 && mouseY>=buttonHeight/actButtonHeightNum*1 && mouseY<buttonHeight/actButtonHeightNum*2){
		//�T�C�Y�ύX�{�^���Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			m_actionSettings.CancelEditing();
			m_actionSettings.m_pEditAction=EditResizeFactory();
			m_actionSettings.InitEditObject();
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
	printfDx("%d\n",m_actionSettings.m_pBattleObject.get());

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
	
	//�{�^���Q�̕`��
	for(std::shared_ptr<ButtonHaving::Button> &pb:m_buttons){
		pb.get()->ButtonDraw(m_font,TRUE);
	}

	//�E���̍�ƃt���[���̕`��
	{
		const int bx=leftUpPosX*2+mapSizeX,by=0;//�{�^���Q�̈ʒu
		const int bdx=buttonWidth/actButtonWidthNum,bdy=(leftUpPosY*2+mapSizeY)/4/actButtonHeightNum;//�{�^���̑傫��
		//����{�^���Q�̕`��
		for(unsigned int y=0;y<actButtonHeightNum;y++){
			for(unsigned int x=0;x<actButtonWidthNum;x++){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
				DrawBox(bx+x*bdx,by+y*bdy,bx+(x+1)*bdx,by+(y+1)*bdy,GetColor(192,192,192),TRUE);//���g(���傢���߂�����)
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
				DrawBox(bx+x*bdx,by+y*bdy,bx+(x+1)*bdx,by+(y+1)*bdy,GetColor(192,192,64),FALSE);//�O�g
				//����
				DrawStringCenterBaseToHandle(bx+x*bdx+bdx/2,by+y*bdy+bdy/2,actButtonStr[x+y*actButtonHeightNum].c_str(),GetColor(255,255,255),m_font,true);
			}
		}
	}

}
