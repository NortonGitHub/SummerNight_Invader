#pragma once
#include "DXLib.h"
//#include "GameMain.h"
class Pause{
public:
	Pause();
	~Pause();
	void PauseDraw();
	void selectUpdate();
	int Select();
private:
	int _pauseHandle;
	int _selectHandle;
	int _keyCheck = 0; //0,1,2�Ŕ��f �㉺�J�[�\���Ő����ϓ�����

	int selectBGM;
	
};