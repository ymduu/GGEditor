#ifndef DEF_CIRCLEFACTORY_H
#define DEF_CIRCLEFACTORY_H

#include"ShapeFactory.h"

//�~�����N���X
class CircleFactory:public ShapeFactory{
	//�^�E�񋓑�
public:
	struct CircleFactoryButton:public ShapeFactoryButton{
		CircleFactoryButton(Vector2D point,Vector2D vec);
		void ButtonDraw(int font,int fillFlag)const;//�{�^���̕`��
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���ɍs������
	};
	//�萔

	//�ϐ�
protected:

	//�֐�
protected:

public:
	CircleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor);
	~CircleFactory();

	std::shared_ptr<MyShape> CreateMyShape()const;
};


#endif // !DEF_CIRCLEFACTORY_H
#pragma once
