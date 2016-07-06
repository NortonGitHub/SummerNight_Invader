#pragma once
#include "EnemyBase.h"
#include <random>

#include <stdlib.h>
class LREnemy3 : public EnemyBase
{
private:
	double _x;
	double _y;
	bool _bullet;
	int _HP;

	double speed;

	bool flag;
	int f;

	int handle[4];
	int h;			//�摜����ϐ�

	int _wave;

	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
public:
	LREnemy3();
	LREnemy3(int hiswave);
	~LREnemy3();

	void update();

	void draw();

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

