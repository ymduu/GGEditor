#ifndef DEF_ANGLEDTRIANGLEFACTORY_H
#define DEF_ANGLEDTRIANGLEFACTORY_H

#include"ShapeFactory.h"

//���p�O�p�`�����N���X
class AngledTriangleFactory:public ShapeFactory{
	//�^�E�񋓑�
public:
	struct AngledTriangleFactoryButton:public ShapeFactoryButton{
		AngledTriangleFactoryButton(Vector2D point,Vector2D vec);
		void ButtonDraw(int font,int fillFlag)const;//�{�^���̕`��
		void PushedProcess(EditActionSettings &settings)const;//�{�^���������ꂽ���ɍs������
	};
	//�萔

	//�ϐ�
protected:

	//�֐�
protected:

public:
	AngledTriangleFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor);
	~AngledTriangleFactory();

	std::shared_ptr<MyShape> CreateMyShape()const;
};


#endif // !DEF_ANGLEDTRIANGLEFACTORY_H
#pragma once
