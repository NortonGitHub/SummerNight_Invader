#include <math.h>
#include <random>
#include "DxLib.h"
#include "EnemyBase.h"
#include <iostream>
#pragma once
#define PI 3.1415926f
class IrreEnemy4 : public EnemyBase
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
	int HandleN[4];
	bool change;
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
	void update();
	void draw();

	IrreEnemy4(){};
	IrreEnemy4(int hiswave, int cnt);
	~IrreEnemy4();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();				//X���W��Ԃ�
	double returnY();				//Y���W��Ԃ�
	int getEnemyHP();				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	int getExplosionFlag();		//�����t���O�𓾂�
};
