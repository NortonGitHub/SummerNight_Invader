#include <math.h>
#include <random>
#include "DxLib.h"
#include "EnemyBase.h"
#include <iostream>
#pragma once
#define PI 3.1415926f
class IrreEnemy3 : public EnemyBase
{
private:
	double _x;
	double _y;
	double xs;
	double ys;
	int _time;
	int h;
	double t;
	int f;
	int i;
	int HandleN[4];
	bool change;
	bool change2;
	double moveX1;
	double moveY1;
	bool exist;

	int _wave;
	bool _bullet;
	int _HP;
	int _cnt;
	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
public:
	IrreEnemy3();
	IrreEnemy3(int hiswave, int cnt);
	~IrreEnemy3();

	void update();
	void draw();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();				//X���W��Ԃ�
	double returnY();				//Y���W��Ԃ�
	int getEnemyHP();				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();   //�_�ł��I�����t���O��Ԃ�	
	 void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	 int getExplosionFlag();		//�����t���O�𓾂�//�_�ł��I�����t���O��Ԃ�
};

