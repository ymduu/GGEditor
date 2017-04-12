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
#include "libQTree.h"

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
	VECTOR po,poi;

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
	const int x = 200, y = 200, r = 100, maxt = 330 ,move=4;

	std::vector<std::shared_ptr<BattleObject>> objects;
	std::vector< std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>>> spOFTVec;	//�l���؂ɒǉ�����I�u�W�F�N�g

	//�f���p�ɉ~�Ǝl�p�`�̕��̂�p��
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyCircle(30))
			, (i+1)*100, 300, -1, 0, GetColor(255, 255, 255), false)));
	}
	for (int i = 0; i < 4; i++) {
		objects.push_back(std::shared_ptr<BattleObject>(new Terrain(std::shared_ptr<MyShape>(new MyRectangle(100, 200))
			, 150 * i, 10, -1, 0, GetColor(255, 255, 255), false)));
	}
	//4���؂ɒǉ��Ashared_ptr�������|�C���^�͎w���悪�ω����Ȃ����Ƃ�O��Ƃ��Ă���(���v���H)
	for (std::shared_ptr<BattleObject> sp : objects) {
		std::shared_ptr<IKD::OBJECT_FOR_TREE<BattleObject>> newObj = std::make_shared<IKD::OBJECT_FOR_TREE<BattleObject>>(0);
		newObj->m_pObject = sp.get();
		spOFTVec.push_back(newObj);
	}
	
	IKD::CLiner4TreeManager<BattleObject> LTree;
	IKD::CollisionList<BattleObject>* ColVect;		
	if (!LTree.Init(8, 0.0, 0.0, 800.0, 600.0))
	{
		MessageBox(NULL, _T("���`4���؋�Ԃ̏������Ɏ��s���܂����B"), NULL, NULL);
		return;
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//�Q�[���{��
		//�L�[���X�V
		t++;
		input_update();

		//�ēo�^(�ړ��𔽉f�����邽��)

		for (size_t count = 0; count < spOFTVec.size(); count++) {
			//i=cn
			BattleObject *pTmp = spOFTVec[count]->m_pObject;
			spOFTVec[count]->Remove();		// ��x���X�g����O���
			// �ēo�^
			LTree.Regist(pTmp->x - pTmp->r, pTmp->y - pTmp->r, pTmp->x + pTmp->r, pTmp->y + pTmp->r, spOFTVec[count].get());
		}
		
		//�`��
		for (int i = 0; i < 8; i++) {
			//objects[i].get()->Move((float)(x + i * 50 + r*cos((float)t / maxt*M_PI)), (float)(y + i * 50 + r*sin((float)t / maxt*M_PI)));
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
