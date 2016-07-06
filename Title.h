#pragma once
#include "Scene_Base.h"

class Title : public Scene_Base
{
private:

	int frame;

	int titleImage[6];	//�^�C�g���̉摜�\��

	int _selectHandle; //���
	int _keyCheck;

	int titleBGM;
	int selectBGM;

	int testImage;	//�t���[�̉摜�n���h��

	double _T_changing; //���Ԃ�����

public:
	Title();
	~Title();

	Scene_Base* update();

	void draw();

	void playerControl();
	
};

