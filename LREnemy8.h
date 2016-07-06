#include <math.h>
#include "DxLib.h"
#include "EnemyBase.h"
#include <iostream>
#pragma once
#define PI 3.1415926f
class LREnemy8 : public EnemyBase
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
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
public:
	LREnemy8();
	LREnemy8(int hiswave,int cnt);
	~LREnemy8();
	void update();
	void draw();
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

