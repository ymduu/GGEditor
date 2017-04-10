#ifndef DEF_TERRAIN_H
#define DEF_TERRAIN_H

//�n�`�E��Q���ɂ��Ă̏��̐錾
#include"BattleObject.h"

class Terrain :public BattleObject {
	//�^�E�񋓑�

	//�萔

	//�ϐ�
protected:
	unsigned int m_color;//�n�`�̓h��Ԃ��̐F(���̂����e�N�X�`�����ɕς��Ǝv����)
	bool m_breakable;//�j��ł��邩�ǂ���

	//�֐�
public:
	Terrain(const std::shared_ptr<MyShape> hitJudgeShape, double x, double y, int gHandle, int kind,unsigned int color,bool breakable);
	~Terrain();
	void VDraw();
	void VHitProcess(const BattleObject *potherobj);

};


#endif // !DEF_TERRAIN_H
