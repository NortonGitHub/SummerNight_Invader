#pragma once
#include <random>
#include "DxLib.h"
#include "EnemyBase.h"
#include <math.h>
#include <iostream>
#define PI 3.141592654f

class IrreEnemy1 : public EnemyBase
{
private:
	double _x;
	double _y;
	double xs;
	double ys;
	int _time;
	int h;
	double t;
	int Handle;
	int f;
	int i;
	int HandleN[4]; // 画像格納用ハンドル
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
	IrreEnemy1();
	IrreEnemy1(int hiswave);
	~IrreEnemy1();
	void update();
	void draw();
	int returnWavenum();
	bool returnBulletFlag();
	double returnX();				//X座標を返す
	double returnY();				//Y座標を返す
	int getEnemyHP();				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る
};

