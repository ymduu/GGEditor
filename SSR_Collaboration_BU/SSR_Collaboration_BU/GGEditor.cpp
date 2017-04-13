#define _USE_MATH_DEFINES	//math.h�̒萔���g�����߂ɕK�{

#include<math.h>

#include"DxLib.h"
#include"GGEditor.h"

#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"
#include"input.h"

//�萔�̒�`
const int GGEditor::mapSizeX = 800;
const int GGEditor::mapSizeY = 600;
const int GGEditor::leftUpPosX = 25;
const int GGEditor::leftUpPosY = 25;
const int GGEditor::buttonWidth = 400;
const std::string GGEditor::actButtonStr[actButtonHeightNum*actButtonWidthNum]={"put","remove","move","expand"};

//�֐���`
GGEditor::GGEditor()
	:m_actionSettings(std::shared_ptr<EditAction>(nullptr)
		,std::weak_ptr<BattleObject>(std::shared_ptr<BattleObject>(nullptr))
		,std::shared_ptr<PosSetting>(nullptr))
{
	//�t�H���g
	m_font=CreateFontToHandle("���C���I",16,1);

	//�����p
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
			,20+m_actionSettings.GetMAdjust().x
			,20+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,40))
			,180+m_actionSettings.GetMAdjust().x
			,180+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,-40))
			,190+m_actionSettings.GetMAdjust().x
			,120+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,-40))
			,280+m_actionSettings.GetMAdjust().x
			,280+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyCircle(40))
			,390+m_actionSettings.GetMAdjust().x
			,390+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(30,40))
			,620+m_actionSettings.GetMAdjust().x
			,620+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-30,40))
			,780+m_actionSettings.GetMAdjust().x
			,780+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(40,-30))
			,790+m_actionSettings.GetMAdjust().x
			,720+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-40,-50))
			,880+m_actionSettings.GetMAdjust().x
			,880+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
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
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
			,((float)mouseX)+m_actionSettings.GetMAdjust().x
			,((float)mouseY)+m_actionSettings.GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
}

//�����[�v���암���̊֐�
int GGEditor::Calculate() {
	//�}�E�X�̈ʒu�v�Z
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//�}�E�X���͎�t
	//���N���b�N�����ꂽ��
	if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
		//�}�b�v��ʓ��Ƀ}�E�X������ꍇ
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			ProcessMapPush(mouseX,mouseY);
		}
	} else if(mouseX>=0 && mouseX<leftUpPosX*2+mapSizeX && mouseY>=0 && mouseY<leftUpPosY*2+mapSizeY){
		//�}�b�v���(���̏ꍇ�͏�ɓ��Ă͂܂�̂ł��肦�Ȃ�)���X�N���[���o�[�Ƀ}�E�X������ꍇ
		float scroll=0;//�X�N���[������s�N�Z����
		if(mouse_get(MOUSE_INPUT_LEFT)==1) {
			scroll=5;
		} else if(mouse_get(MOUSE_INPUT_LEFT)>30){
			scroll=20;
		}
		m_actionSettings.PushScrollBar(scroll,2000,2000,mouseX,mouseY,leftUpPosX,leftUpPosY,mapSizeX,mapSizeY);
	}
	//�L�[�{�[�h���͎�t
	if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
		return -1;
	}
	return 0;
}

void GGEditor::Draw() {
	clsDx();
	for(auto o:m_objects){
		printfDx("%d\n",o.get());
	}
	//�}�b�v����̃X�N���[���{�^���̕`��
	{
		//�ЂƂ܂������������`�̕`��Ƃ���
		int r,g,b;
		GetBackgroundColor(&r,&g,&b);
		DrawBox(0,0,leftUpPosX*2+mapSizeX,leftUpPosY*2+mapSizeY,GetColor(192,192,192),TRUE);
		DrawBox(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX,leftUpPosY+mapSizeY,GetColor(r,g,b),TRUE);
		//�X�Ɏ΂ߐ���
		DrawLine(0,0,leftUpPosX,leftUpPosY,GetColor(0,0,0));//����
		DrawLine(0,leftUpPosY*2+mapSizeY,leftUpPosX,leftUpPosY+mapSizeY,GetColor(0,0,0));//����
		DrawLine(leftUpPosX*2+mapSizeX,0,leftUpPosX+mapSizeX,leftUpPosY,GetColor(0,0,0));//�E��
		DrawLine(leftUpPosX+mapSizeX,leftUpPosY+mapSizeY,leftUpPosX*2+mapSizeX,leftUpPosY*2+mapSizeY,GetColor(0,0,0));//�E��
	}
	//�}�b�v�̕`��
	//�}�b�v�`��o����͈͂𐧌�
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	bool firstflag=true;
	Vector2D mouse=GetMousePointVector2D()-Vector2D((float)leftUpPosX,(float)leftUpPosY)+m_actionSettings.GetMAdjust();//�}�E�X�̈ʒu(�␳�l���l�����}�b�v��̍��W�ŕ\��)
	for (std::shared_ptr<BattleObject> obj : m_objects) {
		obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
		//�}�E�X������Ă���}�`�ɂ͘g��`�悵�t�H�[�J�X��\��
		if(firstflag && obj.get()->JudgePointInsideShape(mouse)){
			obj.get()->ShapeDraw(GetColor(255,255,0),FALSE,leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
			firstflag=false;
		}
	}
	SetDrawAreaFull();
	//���͂���Ă��铮��̃{�^���̕`��

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
