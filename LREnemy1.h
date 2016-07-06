#pragma once
#include "EnemyBase.h"

#include <stdlib.h>
#include <random>

class LREnemy1 : public EnemyBase
{
private:
	int frame;
	double _x;
	double _y;
	bool flag;
	bool _bullet;
	int _HP;
	int _wave;
	int f;
	int count;

	int handle[4];
	int h;			//�摜����ϐ�
	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
public:
	LREnemy1();
	LREnemy1(int hiswave);
	~LREnemy1();

	void update();

	void draw();

//	bool shotFlag();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();
	double returnY();
	int getEnemyHP();				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	int getExplosionFlag();		//�����t���O�𓾂�
};

