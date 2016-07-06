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
	int h;			//画像制御変数

	int _wave;
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
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
	int getEnemyHP();				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る
};

