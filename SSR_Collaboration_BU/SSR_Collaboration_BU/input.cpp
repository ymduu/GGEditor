#include<iostream>
#include"DxLib.h"
#include"input.h"

//キーボード関連
static InputControler *inputControler;

int keyboard_update(){
	return inputControler->Update();
}

int keyboard_get(int KeyCode){//KeyCodeはキーボードの名前
	return inputControler->Get(KeyCode);
}

//入力情報を全て消す(どのボタンも入力されてないことにする)
void keyboard_erase(){
	inputControler->InitInput();
}

//ボタンを押されたことにする
void keyboard_COMinput(int KeyCode){
	inputControler->COMinput(KeyCode);
}

//入力関連
void InitInputControler(){
	inputControler=new InputControler();
}

void DeleteInputControler(){
	if(inputControler!=NULL){
		delete inputControler;
		inputControler=NULL;
	}
}

const std::string InputControler::InitFileName="Database/savedata/InputEdit.csv";

bool InputControler::GamepadKeyboardMap::operator<(const GamepadKeyboardMap &otherobj)const{
	if(keyboard < otherobj.keyboard){
		return true;
	}else if(keyboard > otherobj.keyboard){
		return false;
	}
	return (padbutton < otherobj.padbutton);
}

bool InputControler::GamepadKeyboardMap::operator==(const GamepadKeyboardMap &otherobj)const{
	return (this->keyboard == otherobj.keyboard);
}

InputControler::InputControler(){
	for(int i=0;i<KeyNum;i++){
		m_keyboardFlame[i]=0;
	}
	
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_NUMPADENTER,PAD_INPUT_4));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_BACK,PAD_INPUT_3));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_RSHIFT,PAD_INPUT_1));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_UP,PAD_INPUT_UP));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_DOWN,PAD_INPUT_DOWN));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_LEFT,PAD_INPUT_LEFT));
	m_connectmap.insert(GamepadKeyboardMap(KEY_INPUT_RIGHT,PAD_INPUT_RIGHT));
}

InputControler::~InputControler(){}

int InputControler::Update(){
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);//tmpKeyだとtmpKeyの先頭のアドレスを示す
	int tmpPad=0;
	if(GetJoypadNum()>0){
		tmpPad=GetJoypadInputState(DX_INPUT_PAD1);
	}
	std::set<GamepadKeyboardMap>::iterator it=m_connectmap.begin(),ite=m_connectmap.end();
	bool flag;
	for(int i=0;i<KeyNum;i++){
		flag=((it!=ite) && (it->keyboard)==i);
		if(tmpKey[i]!=0 || (flag && (tmpPad & it->padbutton)!=0)){
			m_keyboardFlame[i]++;
		}else{
			m_keyboardFlame[i]=0;
		}
		if(flag){
			it++;
		}
	}
	return 0;
}

int InputControler::Get(int KeyCode){
	if(KeyCode>=0 && KeyCode<KeyNum){
		return m_keyboardFlame[KeyCode];
	}
	return 0;
}

void InputControler::InitInput(){
	for(int i=0;i<KeyNum;i++){
		m_keyboardFlame[i]=0;
	}
}

void InputControler::COMinput(int KeyCode){
	if(KeyCode>=0 && KeyCode<KeyNum){
		m_keyboardFlame[KeyCode]++;
	}
}

void InputControler::AddConnectMap(int KeyCode,int PadButton){
	m_connectmap.insert(GamepadKeyboardMap(KeyCode,PadButton));
}

void InputControler::MapSaving(){

}


