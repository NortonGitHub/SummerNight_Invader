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
	int h;			//画像制御変数

	int _wave;

	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
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
	int getEnemyHP();				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る
};

