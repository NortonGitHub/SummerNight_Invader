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
	int h;			//画像制御変数
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
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
	int getEnemyHP();				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る
};

