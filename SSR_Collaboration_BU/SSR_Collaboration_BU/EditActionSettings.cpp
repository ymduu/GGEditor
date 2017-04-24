#include<math.h>
#include"EditActionSettings.h"

#include"DxLib.h"
#include"EditAction.h"
#include"Terrain.h"
#include"MyAngledTriangle.h"
#include"MyCircle.h"
#include"MyRectangle.h"

EditActionSettings::EditActionSettings(std::shared_ptr<EditAction> pEditAction, std::shared_ptr<BattleObject> pBattleObject, std::shared_ptr<PosSetting> pPosSetting)
	:m_adjust(0,0),m_pEditAction(pEditAction),m_pBattleObject(pBattleObject),m_pPosSetting(pPosSetting)
{
	//�����p
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,40))
			,20+GetMAdjust().x
			,20+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,40))
			,180+GetMAdjust().x
			,180+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(40,-40))
			,190+GetMAdjust().x
			,120+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyRectangle(-40,-40))
			,280+GetMAdjust().x
			,280+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyCircle(40))
			,390+GetMAdjust().x
			,390+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(30,40))
			,620+GetMAdjust().x
			,620+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-30,40))
			,780+GetMAdjust().x
			,780+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(40,-30))
			,790+GetMAdjust().x
			,720+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
	m_objects.push_back(std::shared_ptr<BattleObject>(
		new Terrain(std::shared_ptr<MyShape>(new MyAngledTriangle(-40,-50))
			,880+GetMAdjust().x
			,880+GetMAdjust().y
			,-1,0,GetColor(128,128,128),false)
		));
}

EditActionSettings::~EditActionSettings() {}

std::vector<std::shared_ptr<BattleObject>>::iterator EditActionSettings::GetMousePointedObject(Vector2D point){
	std::vector<std::shared_ptr<BattleObject>>::iterator it=m_objects.begin(),ite=m_objects.end();
	for(;it!=ite;it++) {
		//�}�E�X������Ă���}�`�ɂ͘g��`�悵�t�H�[�J�X��\��
		if(it->get()->JudgePointInsideShape(point)){
			break;
		}
	}
	return it;
}

void EditActionSettings::PracticeEdit(Vector2D point){
	m_pEditAction.get()->VProcessAction(point,*this);
}

void EditActionSettings::PushScrollBar(float scrollpx,float maxX,float maxY,int mouseX,int mouseY,int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY){
	if(mouseY*leftUpPosX-mouseX*leftUpPosY<0 && (mouseY-leftUpPosY)*leftUpPosX+(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY<0){
		//�㕔��(1��艺�A2��艺)
		m_adjust.y=fmax((float)0,m_adjust.y-scrollpx);
	} else if(mouseY*leftUpPosX-mouseX*leftUpPosY>=0 && (mouseY-(leftUpPosY+mapSizeY))*leftUpPosX+(mouseX-leftUpPosX)*leftUpPosY<0){
		//������(1����A2��艺)
		m_adjust.x=fmax((float)0,m_adjust.x-scrollpx);
	} else if((mouseY-leftUpPosY)*leftUpPosX+(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY>=0 && (mouseY-(leftUpPosY+mapSizeY))*leftUpPosX-(mouseX-(mapSizeX+leftUpPosX))*leftUpPosY<0){
		//�E����(1��艺�A2����)
		m_adjust.x=fmin(maxX-mapSizeX,m_adjust.x+scrollpx);
	} else{
		//������(1����A2����)
		m_adjust.y=fmin(maxY-mapSizeY,m_adjust.y+scrollpx);
	}
}

void EditActionSettings::DrawEditButtonPushed()const{
	m_pEditAction.get()->DrawPushedButton();
}

void EditActionSettings::PutObject(Vector2D point){
	//�I�u�W�F�N�g�����݂̃}�E�X�̈ʒu�ɍ��킹�Ă���ݒu
	m_pBattleObject.get()->Warp(point+m_adjust);
	m_objects.push_back(m_pBattleObject);
	//m_pBattleObject�����̂܂܂ɂ���Ɠ����|�C���^�̃I�u�W�F�N�g���Ⴄ�ꏊ�ɒu�����Ƃ��Ă��܂��̂ŁA�|�C���^�͐V��������
	m_pBattleObject=m_pBattleObject->VCopy();
}

void EditActionSettings::RemoveObject(Vector2D point){
	//��菜���I�u�W�F�N�g��T��
	std::vector<std::shared_ptr<BattleObject>>::iterator it=GetMousePointedObject(point+m_adjust);
	if(it!=m_objects.end()){
		m_objects.erase(it);
	}
}
