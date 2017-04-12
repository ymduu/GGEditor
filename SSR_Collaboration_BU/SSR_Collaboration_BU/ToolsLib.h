#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H
#include <math.h>

//一般的に用いることができる便利関数・構造体をここに書く

//位置についての構造体
class Vector2D{
public:
	//変数
	float x, y;
	//関数
	Vector2D(float i_x, float i_y) : x(i_x), y(i_y) {}
	const Vector2D operator+(const Vector2D &otherobj)const {
		return Vector2D(x+otherobj.x,y+otherobj.y);
	}
	const Vector2D operator-(const Vector2D &otherobj)const {
		return Vector2D(x - otherobj.x, y - otherobj.y);
	}
	//定数倍
	const Vector2D operator*(float aMag)const{
		return Vector2D(x *aMag, y*aMag);
	}
	const Vector2D operator/(float aMag)const {
		return Vector2D(x /aMag, y/aMag);
	}
	float dot(const Vector2D &otherobj)const {
		return x*otherobj.x + y*otherobj.y;
	}
	//this cross otherobjを返します。
	float cross(const Vector2D &otherobj)const {
		return x*otherobj.y - otherobj.x*y;
	}
	float size()const {
		return sqrtf(x*x + y*y);
	}
	Vector2D norm()const {
		float siz = size();
		return Vector2D(x / siz, y / siz);
	}
};

//マウスの位置をVector2D型で返す関数
Vector2D GetMousePointVector2D();


#endif // !DEF_TOOLSLIB_H
#pragma once
