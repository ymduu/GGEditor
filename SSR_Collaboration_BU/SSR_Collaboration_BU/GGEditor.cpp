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
	:m_actionSettings(Vector2D(25, 25)
		, std::shared_ptr<EditAction>(nullptr)
		,std::weak_ptr<BattleObject>(std::shared_ptr<BattleObject>(nullptr))
		,std::shared_ptr<PosSetting>(nullptr))
{
	
}

GGEditor::~GGEditor() {}

int GGEditor::Calculate() {
	//�}�E�X�̈ʒu�v�Z
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	//�}�E�X���͎�t
	if (mouse_get(MOUSE_INPUT_LEFT)==1) {
		//���N���b�N�����ꂽ��
		if(mouseX>=leftUpPosX && mouseX<leftUpPosX+mapSizeX && mouseY>=leftUpPosY && mouseY<leftUpPosY+mapSizeY){
			//�}�b�v��ʂ������ꂽ�ꍇ
			m_objects.push_back(std::shared_ptr<BattleObject>(
				new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
					,(float)mouseX,(float)mouseY,-1,0,GetColor(128,128,128),false)
				));
		}
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
	}
	//�}�b�v�̕`��
	//�}�b�v�`��o����͈͂𐧌�
	SetDrawArea(leftUpPosX,leftUpPosY,leftUpPosX+mapSizeX, leftUpPosY + mapSizeY);
	for (std::shared_ptr<BattleObject> obj : m_objects) {
		obj.get()->VDraw();
	}
	SetDrawAreaFull();
	//���͂���Ă��铮��̃{�^���̕`��

	//�E���̍�ƃt���[���̕`��

}
