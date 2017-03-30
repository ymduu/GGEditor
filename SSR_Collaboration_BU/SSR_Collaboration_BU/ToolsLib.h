#ifndef DEF_TOOLSLIB_H
#define DEF_TOOLSLIB_H

//��ʓI�ɗp���邱�Ƃ��ł���֗��֐��E�\���̂������ɏ���

//�ʒu�ɂ��Ă̍\����
template <typename T> class Position2D{
public:
	//�ϐ�
	T x, y;
	//�֐�
	Position2D<T>(T i_x, T i_y) : x(i_x), y(i_y) {}
	const Position2D<T> operator+(const T &otherobj) {
		return Position2D<T>(x+otherobj.x,y+otherobj.y);
	}

};



#endif // !DEF_TOOLSLIB_H
#pragma once
