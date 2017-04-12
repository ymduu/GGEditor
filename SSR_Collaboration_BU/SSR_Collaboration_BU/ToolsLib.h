#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//一般的に用いることができる便利関数・構造体をここに書く

//位置についての構造体
class Vector2D{
public:
	//変数
	float x, y;
	//関数
	Vector2D(float i_x, float i_y) : x(i_x), y(i_y) {}
	const Vector2D operator+(const Vector2D &otherobj) {
		return Vector2D(x+otherobj.x,y+otherobj.y);
	}

};



#endif // !DEF_TOOLSLIB_H
#pragma once
