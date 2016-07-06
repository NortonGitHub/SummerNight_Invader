#pragma once
#include "Scene_Base.h"
#include "Player.h"
#include "EnemyBase.h"
#include "WeaponBase.h"
#include "Title.h"

#include "ConfigureStage.h"

class StageManager : public Scene_Base
{
private:

#define GAME_CLEAR_LIMIT 2

    ConfigureStage configure;

	int backX;
	int backY;
	int _x;
	int _y;

	int frame;

	int _forCs_u;
	int _forCs_d;

	int backImage;

	Player player;

	double _playerX;
	double _playerY;
	double _shotX;
	double _shotY;
	int _weaponNum;
	int _weaponSt;
	int _sceneChange;
	bool _wasAttacked;
	int _stagenum_cs;

public:
	StageManager();
	~StageManager();

	Scene_Base* update();

	void draw();

	int getSceneChange();

	int getstage();
	int getWaveNumNow();

};

/*
//現在何ステージ目なのかを管理するためのクラス
class StageNum
{
private:
	int _stage;

public:
	StageNum();

	~StageNum();

	void management(int &stage);
	void addition();

};
*/
