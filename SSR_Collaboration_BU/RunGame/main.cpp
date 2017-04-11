#define _USE_MATH_DEFINES	//math.h�̒萔���g�����߂ɕK�{

#include<iostream>
#include"DxLib.h"

#include<math.h>
#include<memory>
#include<vector>
#include"input.h"
#include"Terrain.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//��ʃ��[�h�̐ݒ�
	SetGraphMode(800, 600, 16);
	//�^�C�g�����j���[����
	SetMainWindowText("SSRunGame");
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
	*	�ȉ��A�~�O����ɓ����Œ��p�O�p�`��`�悵�ĉ񂷃f��
	*/

	//���͂ɂ��Ă̏�����
	InitInputControler();

	//�`�悳������̂�錾
	int t = 0;
	const int x = 200, y = 200, r = 100, maxt = 330;

	std::vector<std::shared_ptr<BattleObject>> objects;
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(45 + 20 * (i - 2)))
			, (float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI))
			, -1, 0, GetColor(255, 255, i * 50), false)));
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//�Q�[���{��
		//�L�[���X�V
		t++;
		input_update();
		//�`��
		for (int i = 0; i < 4; i++) {
			objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
			objects[i].get()->VDraw();
		}
		//�v�Z����
		//�I�����o
		if (keyboard_get(KEY_INPUT_NUMPADENTER) == 1) {
			break;
		}
	}

	//���͊֘A�̃������̈�J��
	DeleteInputControler();

	DxLib_End();//DX���C�u�����I������
	return 0;
}
