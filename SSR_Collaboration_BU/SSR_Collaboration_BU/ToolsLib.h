#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//一般的に用いることができる便利関数・構造体をここに書く

//位置についての構造体
//やむどぅのが実装し終わったらこれを更新して良い。自分の作業のための暫定的なものである。
struct Vector2D {
	//変数
	float x, y;

	//関数
	Vector2D(float i_x, float i_y) :x(i_x), y(i_y) {}
};

#endif // !DEF_TOOLSLIB_H
#pragma once
