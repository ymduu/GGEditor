#ifndef DEF_EDITMOVE_H

#include"EditAction.h"

//オブジェクトを取り除く操作を記述したクラス
class EditRemove:public EditAction{
	//型・列挙体

	//定数

	//変数
protected:

	//関数
protected:

public:
	EditRemove(int buttonX,int buttonY,int buttonDX,int buttonDY,unsigned int pushedColor);
	~EditRemove(){}

	void VProcessAction(Vector2D point,EditActionSettings &settings);
};

#endif // !DEF_EDITMOVE_H
