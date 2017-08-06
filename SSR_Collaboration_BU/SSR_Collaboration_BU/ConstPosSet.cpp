#include"DxLib.h"
#include"ConstPosSet.h"
#include"EditActionSettings.h"
#include"EditAction.h"
#include"BattleObject.h"

//-------------ConstPosSet::ConstPosSetButton-------------
ConstPosSet::ConstPosSetButton::ConstPosSetButton(Vector2D point,Vector2D vec,int gridSetSize)
	:PosSettingButton(point,vec,std::to_string(gridSetSize)+"px"),m_gridSetSize(gridSetSize){}

void ConstPosSet::ConstPosSetButton::PushedProcess(EditActionSettings &settings)const{
	settings.m_pPosSetting=std::shared_ptr<PosSetting>(new ConstPosSet(m_point,m_vec,GetColor(255,255,0),m_gridSetSize));
}

//-------------ConstPosSet-------------
Vector2D ConstPosSet::CalculateClosestVertex(Vector2D point,Vector2D vec)const{
	int pointx=(int)point.x,pointy=(int)point.y;
	if(vec.x<0 && vec.y<0){
		//point������ɂ���ꍇ
		return Vector2D((float)(pointx-pointx%m_gridSize),(float)(pointy-pointy%m_gridSize));
	}else if(vec.x>=0 && vec.y<0){
		//point���E��ɂ���ꍇ
		return Vector2D((float)(pointx-pointx%m_gridSize+m_gridSize-1),(float)(pointy-pointy%m_gridSize));
	}else if(vec.x<0 && vec.y>=0){
		//point�������ɂ���ꍇ
		return Vector2D((float)(pointx-pointx%m_gridSize),(float)(pointy-pointy%m_gridSize+m_gridSize-1));
	}else{
		//point���E���ɂ���ꍇ
		return Vector2D((float)(pointx-pointx%m_gridSize+m_gridSize-1),(float)(pointy-pointy%m_gridSize+m_gridSize-1));
	}
}

ConstPosSet::ConstPosSet(Vector2D buttonPos,Vector2D buttonSize,unsigned int buttonLightColor,int gridSize)
	:PosSetting(buttonPos,buttonSize,buttonLightColor),m_gridSize(max(gridSize,1)){}

void ConstPosSet::DrawGuide(int leftUpPosX,int leftUpPosY,int mapSizeX,int mapSizeY,Vector2D adjust)const{
	if(m_gridSize>=4){
		//�O���b�h�̐����`�̋󓴂̑傫������2�{��(=2px)�ȏ�ɂȂ�̂�m_gridSize>=4�̎�
		//�\������Ă���}�b�v�̍���̍��W���Q�[����̍��W�ɒu�������A�X��int������
		int adjustx=(int)adjust.x,adjusty=(int)adjust.y;
		//�����c���̕`��
		for(int dx=adjustx%m_gridSize;dx<mapSizeX;dx+=m_gridSize){
			DrawLine(leftUpPosX+dx,leftUpPosY,leftUpPosX+dx,leftUpPosY+mapSizeY,GetColor(255,255,255));
		}
		//�E���c���̕`��
		for(int dx=m_gridSize-adjustx%m_gridSize-1;dx<mapSizeX;dx+=m_gridSize){
			DrawLine(leftUpPosX+dx,leftUpPosY,leftUpPosX+dx,leftUpPosY+mapSizeY,GetColor(255,255,255));
		}
		//�㑤�����̕`��
		for(int dy=adjusty%m_gridSize;dy<mapSizeY;dy+=m_gridSize){
			DrawLine(leftUpPosX,leftUpPosY+dy,leftUpPosX+mapSizeX,leftUpPosY+dy,GetColor(255,255,255));
		}
		//���������̕`��
		for(int dy=m_gridSize-adjusty%m_gridSize-1;dy<mapSizeY;dy+=m_gridSize){
			DrawLine(leftUpPosX,leftUpPosY+dy,leftUpPosX+mapSizeX,leftUpPosY+dy,GetColor(255,255,255));
		}
	}
}

Vector2D ConstPosSet::CalculatePos(Vector2D point,const EditActionSettings &settings)const{
	int pointx=(int)point.x,pointy=(int)point.y;
	switch(settings.m_pEditAction->VGetPosSetKind(settings)){
	case(EditAction::NONEDIT):
		//���������ʒu���������Ȃ��ꍇ(��.BattleObject��Remove�ΏۑI����)
		return point;
	case(EditAction::BASENONEXIST):
		//��_�����݂��Ȃ��ꍇ(��.BattleObject�̐ݒu�ʒu���莞)
		//point����m_gridSize�Ŋ��������̗]������������W��Ԃ�
		//settings.m_pBattleObject->getPos()-settings.m_pBattleObject->getResizeVec():�}�`�����݂��Ă�������������B
		return CalculateClosestVertex(point,settings.m_pBattleObject->getPos()-settings.m_pBattleObject->getResizeVec());
	case(EditAction::BASEEXIST):
		//��_�����݂���ꍇ(��.BattleObject��Resize��)
		//point����_���ǂ��瑤�ɂ��邩�Œ������@���قȂ�B�������̃O���b�h���_�̍��W��Ԃ��B
		//point-settings.m_pBattleObject->getPos();//��_����point�Ɍ������x�N�g��
		return CalculateClosestVertex(point,point-settings.m_pBattleObject->getPos());
	default:
		//��O����
		return point;
	}
}
