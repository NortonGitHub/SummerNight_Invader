#pragma once
#include <random>
#include <math.h>
#include <iostream>
#include "EnemyBase.h"
class LREnemy6 : public EnemyBase
{
private:
	int shotNum;
	double _x;
	double _y;
	double xs;
	double ys;
	int _time;
	int h;
	double t;
	int f;
	int i;
	int HandleN[4]; // 画像格納用ハンドル
	bool change;
	double moveX1;
	bool exist;
	bool _bullet;
	int _HP;
	int _wave;
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
public:
	LREnemy6();
	LREnemy6(/*int firstposX, int firstposY, int time*/int hiswave);
	~LREnemy6();
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

