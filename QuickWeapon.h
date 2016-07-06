#pragma once
#include "WeaponBase.h"

class QuickWeapon : public WeaponBase
{
private:
	int frame;
	int i, j;

	double _x;
	double _y;
	double _sizeX;//サイズ
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[10];		//弾
	int _hgraph[11];	//花火
	int _gNum;
	int _iconQ;			//花火アイコン用絵

	int placeTime;		//設置した時間
	int elapsedTime;	//設置してからの経過時間

	double time;

	enum NowPosition{

		STOP,
		STOP_1,
		SHOT,
		EFFECT,
		END

	}position;

	int count;
	int Cr;	//花火の色指定変数

	bool sf_q;	//撃ちだしているか否か(QuickWeapin version.)

	void in_update();
	void in_draw();

	int HanabiA, HanabiB;//追加、音データ格納

public:
	QuickWeapon();
	//QuickWeapon(double x, double y, double sizeX, double sizeY, std::string graph);

	//QuickWeapon(double x, double y);
	~QuickWeapon();

	void update();

	void draw();

	void preparation(int x, bool flag,int weapon_num);

	void checkForPlayer(bool &weapon);

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };
};

