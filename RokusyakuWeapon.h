#pragma once
#include "WeaponBase.h"

class RokusyakuWeapon : public WeaponBase
{
private:
	int GHandle[4];
	int i;
	int _x;
	int _y;
	double gra;

	bool sf_r;

	enum NowPosition{
		STOP,
		STOP_1,
		SHOT,
		EFFECT,
		END
	}position;

	//’Ç‰Á•ªA‰¹Šy‚Ìî•ñ‚ğ“ü‚ê‚é
	int HanabiA;
	int HanabiB;

public:
	RokusyakuWeapon();
	~RokusyakuWeapon();

	void update();
	void draw();

	void preparation(int x, bool flag, int weapon_num);

	void checkForPlayer(bool &weapon);

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };
};

