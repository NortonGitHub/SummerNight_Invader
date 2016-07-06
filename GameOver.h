#pragma once
#include "DxLib.h"
#include "Scene_Base.h"

class GameOver : public Scene_Base
{
private:
	int frame;
	int gameovergraph;

	bool sceneChangeFlag;

	int GameOver_BGM;

public:
	GameOver();
	~GameOver();

	Scene_Base* update();

	void draw();
};

