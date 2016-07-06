#pragma once 
#include "DxLib.h"
#include "Object_Base.h"
#include <string>

class WeaponBase : public Object_Base
{
private:


public:
	virtual ~WeaponBase(){};

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual void preparation(int x,bool flag,int weapon_num) = 0;

	virtual void checkForPlayer(bool &weapon) = 0;

	virtual int getWeaponStatus() = 0;
	virtual void setWeaponStatus(int _status) = 0;

	virtual double getX() = 0;//Kansyakuでは不必要
	virtual double getY() = 0;//KAnsyakuでは不必要

};