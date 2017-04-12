#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//��ʓI�ɗp���邱�Ƃ��ł���֗��֐��E�\���̂������ɏ���

//�ʒu�ɂ��Ă̍\����
class Vector2D{
public:
	//�ϐ�
	float x, y;
	//�֐�
	Vector2D(float i_x, float i_y) : x(i_x), y(i_y) {}
	const Vector2D operator+(const Vector2D &otherobj) {
		return Vector2D(x+otherobj.x,y+otherobj.y);
	}

};



#endif // !DEF_TOOLSLIB_H
#pragma once
