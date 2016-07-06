#pragma once
#include "DXLib.h"
//#include "WeaponBase.h"

class PipeOfWeapon // public WeaponBase
{
private:
	int _x;
	int _y;

	int frame;

	bool sf;

	int handle;	//グラフィックハンドル

public:
	PipeOfWeapon();
	PipeOfWeapon(int x,bool flag);
	~PipeOfWeapon();

	void update();

	void draw();


	void preparation(int x,bool flag,int weapon_num);

	void checkForPlayer(bool weapon);

};

