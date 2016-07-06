#pragma once
#include <stdlib.h>
#include "EnemyBase.h"
class LREnemy5 : public EnemyBase
{
private:
	double _x;
	double _y;

	int flag;
	int f;

	bool _bullet;
	int _HP;

	double bai;

	int handle;

	int _wave;

	int frame;
	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用
public:
	LREnemy5();
	LREnemy5(int hiswave);
	~LREnemy5();

	void update();
	void draw();
	int returnWavenum();
	bool returnBulletFlag(){ return false; };
	double returnX(){ return 0; };
	double returnY(){ return 0; };
	int getEnemyHP(){ return 0; };				//敵個体のHPを返す
	void setEnemyHP(int _HP);		//敵個体のHPを得る
	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed(){ return false; };			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp){};	//爆発フラグを返す
	int getExplosionFlag(){ return 0; };		//爆発フラグを得る
};

