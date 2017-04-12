#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H
#include <math.h>

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
	const Vector2D operator-(const Vector2D &otherobj) {
		return Vector2D(x - otherobj.x, y - otherobj.y);
	}
	//�萔�{
	const Vector2D operator*(float aMag) {
		return Vector2D(x *aMag, y*aMag);
	}
	const Vector2D operator/(float aMag) {
		return Vector2D(x /aMag, y/aMag);
	}
	float dot(const Vector2D &otherobj) {
		return x*otherobj.x + y*otherobj.y;
	}
	//this cross otherobj��Ԃ��܂��B
	float cross(const Vector2D &otherobj) {
		return x*otherobj.y - otherobj.x*y;
	}
	float size() {
		return sqrtf(x*x + y*y);
	}
	Vector2D norm() {
		float siz = size();
		return Vector2D(x / siz, y / siz);
	}
};

#endif // !DEF_TOOLSLIB_H
#pragma once
