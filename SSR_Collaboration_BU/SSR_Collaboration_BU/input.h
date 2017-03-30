#ifndef DEF_INPUT_H
#define DEF_INPUT_H

//ひとまずまーぼうの前のゲームで用いた入力関連のライブラリをそのまま持ってきている

#include<set>
#include<string>

//キーボード関連
int keyboard_update();

int keyboard_get(int KeyCode);

void keyboard_erase();//入力情報を全て消す(どのボタンも入力されてないことにする)

void keyboard_COMinput(int KeyCode);//ボタンを押されたことにする

//入力関連
void InitInputControler();

void DeleteInputControler();

class InputControler{
	//型
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
	//定数
	static const std::string InitFileName;
	static const int KeyNum=256;

	//変数
	int m_keyboardFlame[KeyNum];//各キーボードが入力されたフレーム数
	std::set<GamepadKeyboardMap> m_connectmap;//ゲームパッドとキーボードの対応表

	//関数
protected:

public:
	InputControler();
	~InputControler();
	int Update();
	int Get(int KeyCode);
	void InitInput();
	void COMinput(int KeyCode);
	void AddConnectMap(int KeyCode,int PadButton);
	void MapSaving();
};

#endif