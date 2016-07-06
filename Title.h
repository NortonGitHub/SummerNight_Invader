#pragma once
#include "Scene_Base.h"

class Title : public Scene_Base
{
private:

	int frame;

	int titleImage[6];	//タイトルの画像予定

	int _selectHandle; //矢印
	int _keyCheck;

	int titleBGM;
	int selectBGM;

	int testImage;	//フリーの画像ハンドル

	double _T_changing; //時間を入れる

public:
	Title();
	~Title();

	Scene_Base* update();

	void draw();

	void playerControl();
	
};

