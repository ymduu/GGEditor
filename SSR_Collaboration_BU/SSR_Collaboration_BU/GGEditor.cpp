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

//�֐���`
GGEditor::GGEditor()
	:m_actionSettings(std::shared_ptr<EditAction>(nullptr)
		,std::weak_ptr<BattleObject>(std::shared_ptr<BattleObject>(nullptr))
		,std::shared_ptr<PosSetting>(nullptr))
{
	
}

GGEditor::~GGEditor() {}

//�}�E�X�����N���b�N�������̓���
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
	for (std::shared_ptr<BattleObject> obj : m_objects) {
		obj.get()->VDraw(leftUpPosX-(int)m_actionSettings.GetMAdjust().x,leftUpPosY-(int)m_actionSettings.GetMAdjust().y);
	}
	SetDrawAreaFull();
	//���͂���Ă��铮��̃{�^���̕`��

	//�E���̍�ƃt���[���̕`��

}
