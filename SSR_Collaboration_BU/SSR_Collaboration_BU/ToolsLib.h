#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//一般的に用いることができる便利関数・構造体をここに書く

//位置についての構造体
template <typename T> class Position2D{
public:
	//変数
	T x, y;
	//関数
	Position2D<T>(T i_x, T i_y) : x(i_x), y(i_y) {}
	const Position2D<T> operator+(const T &otherobj) {
		return Position2D<T>(x+otherobj.x,y+otherobj.y);
	}

};



#endif // !DEF_TOOLSLIB_H
#pragma once
