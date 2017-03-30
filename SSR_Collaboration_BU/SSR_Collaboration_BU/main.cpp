#define _USE_MATH_DEFINES	//math.h�̒萔���g�����߂ɕK�{

#include<iostream>
#include<boost\shared_ptr.hpp>
#include"DxLib.h"

#include<math.h>
#include"input.h"
#include"Terrain.h"
#include"MyRectangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//��ʃ��[�h�̐ݒ�
	SetGraphMode(800,600,16);
	//�^�C�g�����j���[����
	SetMainWindowText("SSR_Collaboration_BU");
	//�E�C���h�E�T�C�Y�̕ύX
	SetWindowSizeExtendRate(1.0);
	//�E�C���h�E�T�C�Y�̕ύX���ł���悤�ɂ���
	SetWindowSizeChangeEnableFlag(TRUE);
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
	*	�ȉ��A�~�O����ɓ����Œ����`��`�悵�ĉ񂷃f��
	*/

	//���͂ɂ��Ă̏�����
	InitInputControler();

	//�`�悳������̂�錾
	int t = 0;
	const int x = 200, y = 200, r = 100,maxt=330;
	Terrain t1(boost::shared_ptr<MyShape>(new MyRectangle(50,20))
		, x + r*cos((double)t / maxt*M_PI), y + r*sin((double)t / maxt*M_PI)
		,-1,0,GetColor(255,0,0),false);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//�Q�[���{��
		//�L�[���X�V
		t++;
		keyboard_update();
		//�`��
		t1.Move(x + r*cos((double)t / maxt*M_PI), y + r*sin((double)t / maxt*M_PI));
		t1.VDraw();
		//�v�Z����
		//�I�����o
		if(keyboard_get(KEY_INPUT_NUMPADENTER)==1){
			break;
		}
	}

	DxLib_End();//DX���C�u�����I������
	return 0;
}
