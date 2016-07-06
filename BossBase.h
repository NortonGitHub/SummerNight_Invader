#pragma once
#include "Object_Base.h"
#include "DxLib.h"

class BossBase : public Object_Base
{

public:

	virtual ~BossBase(){};

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual double getX() = 0;
	virtual double getY() = 0;

	virtual void setHP(int _hp) = 0;
	virtual int getHP() = 0;

	virtual void setFlashFlag(bool _flash) = 0;	//�_�Ńt���O�𓾂�
	virtual bool getHasFlashed() = 0;			//�_�ł��I�����t���O��Ԃ�
	virtual void setExplosionFlag(int _exp) = 0;	//�����t���O��Ԃ�
	virtual int getExplosionFlag() = 0;		//�����t���O�𓾂�

	virtual void setBossCoord(double _x, double _y) = 0;
};