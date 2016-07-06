#pragma once
#include "DxLib.h"
#include "Scene_Base.h"

class GameClear : public Scene_Base
{
private:
	int frame;

	int clear_image;
	int clear_BGM;
    int _stageNum;

	bool sceneChangeFlag;

public:
    GameClear();
    GameClear(int stageNum);
	~GameClear();

	Scene_Base* update();

	void draw();
};

