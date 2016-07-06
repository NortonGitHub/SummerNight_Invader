#include <math.h>
#include <random>
#include "DxLib.h"
#include "EnemyBase.h"
#include <iostream>
#pragma once
#define PI 3.1415926f
class SimpleEnemy1 :public EnemyBase
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
	double moveX1;
	bool exist;

	int _wave;
	bool _bullet;
	int _HP;
	int _cnt;
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
public:
	void update();
	void draw();

	SimpleEnemy1(){};
	SimpleEnemy1(int hiswave,int cnt);
	~SimpleEnemy1();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();
	double returnY();
	int getEnemyHP();				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る
};

