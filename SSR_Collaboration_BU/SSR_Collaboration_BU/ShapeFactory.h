#ifndef DEF_SHAPEFACTORY_H

#include"ButtonHaving.h"

//�����蔻��}�`�����N���X
class ShapeFactory:public ButtonHaving{
	//�^�E�񋓑�
public:
	struct ShapeFactoryButton:public Button{
		//�����蔻��}�`��ݒ肷��{�^���B�����`�̔������`��Ɠ����蔻��̐}�`�̕`��ŕ\���B
		//�ϐ�
		Vector2D m_point;//����̍��W
		Vector2D m_vec;//�Ίp��
		//�֐�
		ShapeFactoryButton(Vector2D point,Vector2D vec,const std::string &str);
		//void ButtonDraw(int font,int fillFlag)const;//�p����Ŏ���
		bool JudgeInButton(Vector2D point)const;//�{�^���̒��ɂ��邩�̔���
		bool JudgeButtonPushed()const;//�{�^�����������삪���ꂽ���𔻒肷��
		//void PushedProcess(EditActionSettings &settings)const;//�p����Ŏ���
	};

	//�萔

	//�ϐ�
protected:
	//�{�^���̃��C�g�A�b�v�̂��߂̏��
	Vector2D m_buttonPos,m_buttonSize;//�{�^���̈ʒu�Ƒ傫��
	unsigned int m_buttonLightColor;//���C�g�A�b�v�̐F

	//�֐�
protected:

public:
	ShapeFactory(Vector2D buttonPos,Vector2D buttonSize,unsigned int lightcolor);
	~ShapeFactory();
	void DrawPushedButtonLight()const;
};


#endif // !DEF_SHAPEFACTORY_H
#pragma once
