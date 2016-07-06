#pragma once
#include "Object_Base.h"
#include "DxLib.h"
#include <string>

class EnemyBase : public Object_Base
{
private:
#define FrameForFlash 60
#define ExplosionHandle 10
	
public:


	virtual ~EnemyBase(){};

	virtual void update() = 0;

	virtual int returnWavenum() = 0;

	virtual bool returnBulletFlag() = 0;

	virtual double returnX() = 0;				//X座標を返す
	virtual double returnY() = 0;				//Y座標を返す
	virtual int getEnemyHP() = 0;				//敵個体のHPを返す
	virtual void setEnemyHP(int _Hp) = 0;		//敵個体のHPを得る
	virtual void setFlashFlag(bool _flash) = 0;	//点滅フラグを得る
	virtual bool getHasFlashed() = 0;			//点滅し終えたフラグを返す
	virtual void setExplosionFlag(int _exp) = 0;	//爆発フラグを返す
	virtual int getExplosionFlag() = 0;		//爆発フラグを得る

	virtual void draw() = 0;

//	virtual bool shotFlag() = 0;


};

