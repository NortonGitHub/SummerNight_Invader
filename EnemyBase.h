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

	virtual double returnX() = 0;				//X���W��Ԃ�
	virtual double returnY() = 0;				//Y���W��Ԃ�
	virtual int getEnemyHP() = 0;				//�G�̂�HP��Ԃ�
	virtual void setEnemyHP(int _Hp) = 0;		//�G�̂�HP�𓾂�
	virtual void setFlashFlag(bool _flash) = 0;	//�_�Ńt���O�𓾂�
	virtual bool getHasFlashed() = 0;			//�_�ł��I�����t���O��Ԃ�
	virtual void setExplosionFlag(int _exp) = 0;	//�����t���O��Ԃ�
	virtual int getExplosionFlag() = 0;		//�����t���O�𓾂�

	virtual void draw() = 0;

//	virtual bool shotFlag() = 0;


};

