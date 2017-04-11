#include<iostream>
#include<memory>
#include"DxLib.h"
#include"input.h"
#include"GGEditor.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//��ʃ��[�h�̐ݒ�
	SetGraphMode(GGEditor::leftUpPosX*2+GGEditor::mapSizeX+GGEditor::buttonWidth, GGEditor::leftUpPosY * 2 + GGEditor::mapSizeY,16);
	//�^�C�g�����j���[����
	SetMainWindowText("GGEditor");
	//�E�C���h�E�T�C�Y�̕ύX
	SetWindowSizeExtendRate(1.0);
	//�E�C���h�E�T�C�Y�̕ύX���ł���悤�ɂ��Ȃ�
	SetWindowSizeChangeEnableFlag(FALSE);
	//�A�C�R���̐ݒ�
	SetWindowIconID(101);

	if (ChangeWindowMode(TRUE) != 0) {
		return 0;
	}
	if (DxLib_Init() != 0) {
		return 0;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		DxLib_End();
		return 0;
	}

	/**
	*	�ȉ��A�~�O����ɓ����Œ��p�O�p�`��`�悵�ĉ񂷃f��
	*/

	//���͂ɂ��Ă̏�����
	InitInputControler();

	std::shared_ptr<GGEditor> ggEditor(new GGEditor());
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//�Q�[���{��
		//�L�[���X�V
		input_update();
		//�`��
		ggEditor->Draw();
		//�v�Z����
		int index = ggEditor->Calculate();
		//�I�����o
		if(index<0){
			break;
		}
	}

	//���͊֘A�̃������̈�J��
	DeleteInputControler();

	DxLib_End();//DX���C�u�����I������
	return 0;
}
