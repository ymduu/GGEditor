#ifndef DEF_RECTANGLEFACTORY_H
#define DEF_RECTANGLEFACTORY_H

#include"ShapeFactory.h"

class RectangleFactory:public ShapeFactory{
	//�^�E�񋓑�
public:
	struct RectangleFactoryButton:public ShapeFactoryButton{
		RectangleFactoryButton(Vector2D point,Vector2D vec);
		void ButtonDraw(int font,int fillFlag)const;//�{�^���̕`��
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���ɍs������
	};
	//�萔

	//�ϐ�
protected:

	//�֐�
protected:

public:
	RectangleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor);
	~RectangleFactory();

	std::shared_ptr<MyShape> CreateMyShape()const;
};

#endif // !DEF_RECTANGLEFACTORY_H
#pragma once
