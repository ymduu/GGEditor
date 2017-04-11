#ifndef DEF_INPUT_H
#define DEF_INPUT_H

//�ЂƂ܂��܁[�ڂ��̑O�̃Q�[���ŗp�������͊֘A�̃��C�u���������̂܂܎����Ă��Ă���

#include<set>
#include<string>

//�L�[�{�[�h�֘A
int input_update();

int keyboard_get(int KeyCode);

int mouse_get(int MouseCode);

void input_erase();//���͏���S�ď���(�ǂ̃{�^�������͂���ĂȂ����Ƃɂ���)

void keyboard_COMinput(int KeyCode);//�{�^���������ꂽ���Ƃɂ���

//���͊֘A
void InitInputControler();

void DeleteInputControler();

class InputControler{
	//�^
protected:
	struct GamepadKeyboardMap{
		int keyboard;
		int padbutton;
		bool operator<(const GamepadKeyboardMap &otherobj)const;
		bool operator==(const GamepadKeyboardMap &otherobj)const;
		GamepadKeyboardMap(int i_keyboard,int i_padbutton)
			:keyboard(i_keyboard),padbutton(i_padbutton){}
		~GamepadKeyboardMap(){}
	};
	//�萔
	static const std::string InitFileName;
	static const int KeyNum=256;//�L�[�{�[�h�̓��̓L�[��
	static const int MouseButtonNum=8;//�}�E�X�̓��̓{�^����

	//�ϐ�
	int m_keyboardFlame[KeyNum];//�e�L�[�{�[�h�����͂��ꂽ�t���[����
	int m_mouseFlame[MouseButtonNum];//�e�}�E�X�̃{�^�������͂��ꂽ�t���[����
	std::set<GamepadKeyboardMap> m_connectmap;//�Q�[���p�b�h�ƃL�[�{�[�h�̑Ή��\

	//�֐�
protected:

public:
	InputControler();
	~InputControler();
	int Update();
	int Get(int KeyCode);
	int MouseGet(int MouseCode);
	void InitInput();
	void COMinput(int KeyCode);
	void AddConnectMap(int KeyCode,int PadButton);
	void MapSaving();
};

#endif