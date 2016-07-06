#pragma once
#include "Scene_Base.h"
#include "Pause.h"

class GameMain
{
public:
	GameMain();
	~GameMain();

	//メイン用のスクリーン
	int screen;

	Scene_Base* nowScene;
	Scene_Base* nextScene;

	//void mainLoop();

	void setSize(double width, double height);
	void mainLoop();

	bool checkScene();
	bool isSameScene();
private:
	bool closedFlag();
	//bool _pauseFlag = false;
	//Pause pause;
};

