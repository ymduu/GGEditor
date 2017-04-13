#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//�C���N���[�h
#include<string>
#include <math.h>

//��ʓI�ɗp���邱�Ƃ��ł���֗��֐��E�\���̂������ɏ���
//�ʒu�ɂ��Ă̍\����
class Vector2D{
public:
	//�ϐ�
	float x, y;
	//�֐�
	Vector2D(float i_x, float i_y) : x(i_x), y(i_y) {}
	const Vector2D operator+(const Vector2D &otherobj)const {
		return Vector2D(x+otherobj.x,y+otherobj.y);
	}
	const Vector2D operator-(const Vector2D &otherobj)const {
		return Vector2D(x - otherobj.x, y - otherobj.y);
	}
	//�萔�{
	const Vector2D operator*(float aMag)const{
		return Vector2D(x *aMag, y*aMag);
	}
	const Vector2D operator/(float aMag)const {
		return Vector2D(x /aMag, y/aMag);
	}
	float dot(const Vector2D &otherobj)const {
		return x*otherobj.x + y*otherobj.y;
	}
	//this cross otherobj��Ԃ��܂��B
	float cross(const Vector2D &otherobj)const {
		return x*otherobj.y - otherobj.x*y;
	}
	float size()const {
		return sqrtf(x*x + y*y);
	}
	//�T�C�Y�̓���Ԃ�
	float sqSize()const {
		return x*x + y*y;
	}
	Vector2D norm()const {
		float siz = size();
		return Vector2D(x / siz, y / siz);
	}
};

//�}�E�X�̈ʒu��Vector2D�^�ŕԂ��֐�
Vector2D GetMousePointVector2D();



//�`��֘A
//��ʑS�̂�`��͈͂ɂ���
int SetDrawAllArea();

//������`��B\n�ŉ��s������B�܂��E�[�܂ōs��������s����B
//�Ōオ\0�ŏI���Ȃ������񂾂ƃt���[�Y�܂��̓I�[�o�[�t���[���N����
int DrawStringNewLineToHandle(const int strX,const int strY,const int printableX,const int printableY,const int maxDX,const int maxDY,const int Color,const int Font,const int FontSize,const char *str);

int DrawStringNewLineToHandle(const int strX,const int strY,const int printableX,const int printableY,const int maxDX,const int maxDY,const int Color,const int Font,const int FontSize,const std::string &str);

//��̕�����`��̕����ŁA�`��͂����ɕK�v��Y���W�̕��̂݋��߂�
int GetStringHeightNewLineToHandle(const int maxDX,const int font,const char *str);

int GetStringHeightNewLineToHandle(const int maxDX,const int font,const std::string str);

//�g��`��B�ʒu�w��ł͂Ȃ��傫���w��Ŋg�嗦���w��B
int DrawExtendGraphSizeAssign(int x,int y,int dx,int dy,int GrHandle,int TransFlag);

//�����̕`��ʒu���w�肵��������`��
int DrawStringCenterBaseToHandle(const int centerx,const int centery,const char *str,unsigned int color,int fonthandle,bool yposcenterbaseflag,unsigned int EdgeColor=0U,int VerticalFlag=0);

//�ʒu��F�X�Ȏ��ŊǗ�����N���X
class PositionControl{
	//�񋓑�
public:
	enum TYPE{
		TYPE_IN,
		TYPE_OUT,
		TYPE_INOUT
	};
	enum FUNCTION{
		FUNCTION_LINER,
		FUNCTION_EXPO
	};
	//�ϐ�
protected:
	int flame,maxflame;//�t���[�����̊Ǘ�
	int x,startx,endx;//x���W�̊Ǘ�
	int y,starty,endy;//y���W�̊Ǘ�
	TYPE type;//�ʒu�ύX�̌`��
	FUNCTION function;//�ʒu�ύX�֐�
	double degree;//�ω��x����
				  //�֐�
public:
	PositionControl(int i_x=0,int i_y=0,int i_maxflame=0,TYPE i_type=TYPE_IN,FUNCTION i_function=FUNCTION_LINER,double i_degree=0.0)
		:flame(0),maxflame(i_maxflame),x(i_x),startx(i_x),endx(i_x)
		,y(i_y),starty(i_y),endy(i_y),type(i_type),function(i_function),degree(i_degree){}//�ʒu�̏������i�ŏ��̂݁j
	virtual ~PositionControl(){}//�f�X�g���N�^
	virtual void Update();//�ʒu�X�V
	void SetTarget(int i_endx,int i_endy,bool initflame);//�ڕW�ʒu�����߂�
	void EnforceEnd();//�����I�ɓ����ɂ���
	void Retry();//��������Z�b�g���Ă�蒼��
	void Retry(int i_startx,int i_starty);//��������Z�b�g���Ă�蒼���B�X�^�[�g�ʒu���ς���
	int GetX()const{
		return x;
	}
	int GetY()const{
		return y;
	}
	int GetstartX()const{
		return startx;
	}
	int GetstartY()const{
		return starty;
	}
	int GetendX()const{
		return endx;
	}
	int GetendY()const{
		return endy;
	}
	int GetFlame()const{
		return flame;
	}
	virtual int GetMaxFlame()const{
		return maxflame;
	}
	FUNCTION GetFunction()const{
		return function;
	}
	TYPE GetType()const{
		return type;
	}
	double GetDegree()const{
		return degree;
	}
	void SetMaxFlame(int flame,bool targetinitflag);
	virtual bool GetEndFlag()const;//���삪�I�����Ă��邩�𔻒肷��
};

//���x����ɂ���đ������w�肵�Đ^�������i��
class PositionControlSpeeding:public PositionControl{
	//�񋓑�
public:
	//�ϐ�
protected:
	//max_flame�͍X�V�����ɗp�����Ȃ��Ȃ�

	//�֐�
public:
	PositionControlSpeeding(int i_x=0,int i_y=0,int i_maxflame=0,TYPE i_type=TYPE_IN,FUNCTION i_function=FUNCTION_LINER,double i_degree=1.0);
	~PositionControlSpeeding(){}//�f�X�g���N�^
	void Update();//�ʒu�X�V
	int GetMaxFlame()const;
	bool GetEndFlag()const;
};

//�傫�����������ׂĕ\������ʒu���v�Z����N���X
class LiningupScalingMechanism{
	//�^�E�񋓑�
public:
	enum DIRECTION{
		UP,
		LEFT,
		RIGHT,
		UNDER
	};
	//�萔

	//�ϐ�
protected:
	DIRECTION fixedside;//�ǂ̕ӂ����킹�邩
	int startx,starty;//�J�n�ʒu
	PositionControl size;//�g�債�Ă��镨�̒���

						 //�֐�
public:
	LiningupScalingMechanism(int x,int y,DIRECTION side,PositionControl initsize);
	~LiningupScalingMechanism();
	void SetScaling(int startdx,int startdy,int enddx,int enddy);//�傫�������肷��
	void Update();
	void Retry();
	void EnforceEnd();
	int GetX(int n,int expandingn,int reducingn)const;
	int GetY(int n,int expandingn,int reducingn)const;
	int GetNormalSizeX()const;
	int GetNormalSizeY()const;
	int GetExpandingSizeX()const;
	int GetExpandingSizeY()const;
	int GetReducingSizeX()const;
	int GetReducingSizeY()const;
};



#endif // !DEF_TOOLSLIB_H
#pragma once
