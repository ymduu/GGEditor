#ifndef DEF_EDITMOVE_H
#define DEF_EDITMOVE_H

#include"EditAction.h"

//設置場所を動かす行為を記述するクラス
class EditMove:public EditAction{
	//型・列挙体

	//定数

	//変数
protected:

	//関数
public:
	EditMove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditMove() {}

	void VProcessAction(Vector2D point,EditActionSettings &settings);//編集行為を実行する
};


#endif // !DEF_EDITMOVE_H
