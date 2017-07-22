#include"DxLib.h"
#include"input.h"
#include"ScrollBar.h"
#include"EditActionSettings.h"

ScrollBar::ScrollButton::ScrollButton(Vector2D p1,Vector2D p2,Vector2D p3,Vector2D p4,Vector2D v)
	:m_point{p1,p2,p3,p4},m_move(v){}

//�`��
void ScrollBar::ScrollButton::ButtonDraw(int font,int fillFlag)const{
	//�g����A�h��Ԃ��l�p�`�̕`��Ȃ̂�
	//1.�O�p�`�Q�̕`��
	//2.�S�����̕`��
	//�ōs��
	unsigned int color=GetColor(192,192,192);
	unsigned int edge=GetBackgroundColor();
	if(fillFlag==TRUE){
		//�O�p�`�Q��
		DrawTriangle((int)m_point[0].x,(int)m_point[0].y,(int)m_point[1].x,(int)m_point[1].y,(int)m_point[2].x,(int)m_point[2].y,color,TRUE);
		DrawTriangle((int)m_point[2].x,(int)m_point[2].y,(int)m_point[3].x,(int)m_point[3].y,(int)m_point[0].x,(int)m_point[0].y,color,TRUE);
	}
	//�g
	for(size_t i=0;i<vNum;i++){
		DrawLine((int)m_point[i%vNum].x,(int)m_point[i%vNum].y,(int)m_point[(i+1)%vNum].x,(int)m_point[(i+1)%vNum].y,edge,1);
	}
}

//����
bool ScrollBar::ScrollButton::JudgeInButton(Vector2D point)const{
	//Crossing Number Algorithm��p����
	//point���炠������̔������ɂ��āA��������_�̌�����Ȃ�����Ɣ��肷��
	//���Ȍ������Ă���}�`�͓����ɓ_�������Ă��O���Ɣ��肳��邪�A����Ȑ}�`�̓X�N���[���o�[�ɗp���Ȃ��̂Ŗ��Ȃ�
	//�ӏ㔻��͞B��
	//�v�Z�̂��߁A�������̕����x�N�g����(1,0)�Ƃ���
	int crossNum=0;//�����_��
	for(size_t i=0;i<vNum;i++){
		Vector2D v=m_point[(i+1)%vNum]-m_point[i%vNum];//�����̕����x�N�g���̒����{
		if(v.y==0){
			//������x�����s�̎�
			//�ӏ㔻��ɂ����Ȃ�Ȃ��̂ŉ������Ȃ��ėǂ�
/*
			//point��y���W��2�_�Ɠ������Ax���W��2�_�̊Ԃɂ���Ό�����Ă���Ɣ���ł���
			float vx1=point.x-m_point[i%vNum].x,vx2=point.x-m_point[(i+1)%vNum].x;
			if(((vx1>0 && vx2<=0) || (vx1<0 && vx2>=0)) && m_point[i%vNum].y==point.y){
				crossNum++;
			}
//*/
		}else{
			//������x�����s�łȂ���
			float crossx=m_point[i%vNum].x+(point.y-m_point[i%vNum].y)/v.y*v.x;
			//point��y���W��2�_�̊Ԃɂ���A��_��point���x�����ɑ傫���ʒu�ɂ���Ό�����Ă���Ɣ���ł���
			float vy1=point.y-m_point[i%vNum].y,vy2=point.y-m_point[(i+1)%vNum].y;
			if(((vy1>=0 && vy2<0) || (vy1<0 && vy2>=0)) && crossx>point.x){
				//y������������������̕ӂ͎n�_���܂ݏI�_���܂܂Ȃ�(vy1>=0 && vy2<0)
				//y������������������̕ӂ͎n�_���܂܂��I�_���܂�(vy1<0 && vy2>=0)
				crossNum++;
			}
		}
	}
	//�����_���̋���̔���
	return (crossNum%2==1);//��Ȃ�true��Ԃ�
}

//�{�^����������
bool ScrollBar::ScrollButton::JudgeButtonPushed()const{
	return (mouse_get(MOUSE_INPUT_LEFT)==1 || mouse_get(MOUSE_INPUT_LEFT)>30);
}

//�����ꂽ���̏���
void ScrollBar::ScrollButton::PushedProcess(EditActionSettings &settings)const{
	float rate;//�����������E1�t���[���ڂ̉��{��
	if(mouse_get(MOUSE_INPUT_LEFT)==1){
		rate=1.0;
	}else{
		rate=20.0;
	}
	settings.PushScrollBar(m_move*rate);
}
