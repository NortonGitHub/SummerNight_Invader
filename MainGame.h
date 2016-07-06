#pragma once
#include "StageManager.h"
#include "ConfigureStage.h"
#include "Pause.h"

class MainGame : public Scene_Base
{
private:
	StageManager stage;
	int frame;

	int BGM;
	int BossBGM;

    int _stageNum;
	bool _pauseFlag = false;

	int _sceneChange;

	Pause pause;
public:
	MainGame(int stageNum);
    MainGame();
	~MainGame();

	Scene_Base* update();

	void draw();
};

