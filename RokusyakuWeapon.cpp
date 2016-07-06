#include "RokusyakuWeapon.h"


RokusyakuWeapon::RokusyakuWeapon()
{
	_x = 25;
	_y = 30;
	gra = 0.0;
	sf_r = false;
	LoadDivGraph("data\\graphics\\bomb.png", 1, 1, 1, 400, 400, GHandle);
}


RokusyakuWeapon::~RokusyakuWeapon()
{
}

void RokusyakuWeapon::update(){
	
}


void RokusyakuWeapon::draw(){
	++i;
	if (i == 4) i = 0;
	DrawGraph(_x, _y, GHandle[i], TRUE);
}

void RokusyakuWeapon::preparation(int x, bool flag, int weapon_num)
{
	if (weapon_num == 4){
		_x = x;
		sf_r = flag;
	}
}

void RokusyakuWeapon::checkForPlayer(bool &weapon)
{
	if (sf_r == false){
		weapon = sf_r;
	}
}


void RokusyakuWeapon::setWeaponStatus(int _status){
	if (_status == 3)
		position = EFFECT;
}

int RokusyakuWeapon::getWeaponStatus(){
	return position;
}