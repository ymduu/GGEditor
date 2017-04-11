#include<iostream>
#include"DxLib.h"
#include"input.h"

//���͊֘A
static InputControler *inputControler;

int input_update(){
	return inputControler->Update();
}

//�L�[�{�[�h�֘A
int keyboard_get(int KeyCode){//KeyCode�̓L�[�{�[�h�̖��O
	return inputControler->Get(KeyCode);
}

//�}�E�X�֘A
int mouse_get(int MouseCode){
	return inputControler->MouseGet(MouseCode);
}

//���͏���S�ď���(�ǂ̃{�^�������͂���ĂȂ����Ƃɂ���)
void input_erase(){
	inputControler->InitInput();
}

//�{�^���������ꂽ���Ƃɂ���
void keyboard_COMinput(int KeyCode){
	inputControler->COMinput(KeyCode);
}

//���͊֘A
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
	for(int i=0;i<MouseButtonNum;i++){
		m_mouseFlame[i]=0;
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
	//�L�[�{�[�h�̍X�V
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);//tmpKey����tmpKey�̐擪�̃A�h���X������
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
	//�}�E�X�̍X�V
	int mouseinput=GetMouseInput();
	for(int i=0;i<MouseButtonNum;i++){
		if((mouseinput>>i) & 0x01){
			m_mouseFlame[i]++;
		}else{
			m_mouseFlame[i]=0;
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

int InputControler::MouseGet(int MouseCode){
	//MouseCode�̉�����x�ڂ�bit��1�Ȃ��m_mouseFlame[x-1]�ɓ��̓t���[�������i�[����Ă���
	//�܂�n��E�V�t�g�����Ƃ���1���������Ȃ��m_mouseFlame[n]��Ԃ��Ă�����Ηǂ�
	//�����ł́A�ŉ���bit��1�̂��̂�1bit�����V�t�g���Ă����A����Ƃ�AND���Z�ɂ���ĉ�bit�ڂ�1�����邩�����o����
	int bit=0x01;
	for(int i=0;i<MouseButtonNum;i++){
		if(MouseCode & (bit<<i)){
			return m_mouseFlame[i];
		}
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


