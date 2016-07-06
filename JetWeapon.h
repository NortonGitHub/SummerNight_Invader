#pragma once
#include "WeaponBase.h"
//噴水花火

class JetWeapon : public WeaponBase
{
private:

	int count;

	int i, j, k;

	double _x;
	double _y;
	double _sizeX;//サイズ
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[9];
	int _gNum;
	int _icon;

	double placedTime;		//設置した時間
	double elapsedTime;	//設置してからの経過時間
	int frame;			//時間

	int shottime;

	bool sf_j;	//撃ちだしているか否か(JetWeapin version.)

	enum NowPosition{
		STOP,
		STOP_1,
		SHOT,
		HOGE,//意味のない欠番を差す
		END

	}position;

	void in_update();
	void in_draw();

	int Hanabi;//追加、音データ格納

public:
	JetWeapon();
	//JetWeapon(double x,double y,double sizeX,double sizeY,std::string graph);

	//JetWeapon(double x, double y);
	~JetWeapon();

	void update();

	void draw();

	void preparation(int x,bool flag,int weapon_num);

	void checkForPlayer(bool &weapon);

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };
};

