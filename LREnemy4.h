#pragma once
#include <random>
#include <stdlib.h>
#include "EnemyBase.h"
class LREnemy4 : public EnemyBase
{
private:
	double _x;
	double _y;
	int f;
	bool _bullet;
	int _HP;

	int handle[4];
	int h;			//�摜����ϐ�

	int _wave;
	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
public:
	LREnemy4();
	LREnemy4(int hiswave);
	~LREnemy4();
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

