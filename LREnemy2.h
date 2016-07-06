#pragma 
#include "EnemyBase.h"
#include "EnemiesBulletManager.h"	//　インクルードループによる"予期せぬエラー"注意部分　10/02付

#include <stdlib.h>
#include <iostream>
using namespace std;
#define PI 3.141592654f


class LREnemy2 : public EnemyBase
{
private:
	double _x;
	double _y;
	bool _bullet;
	int _HP;
	bool flag;
	int f;

	int Sinc;

	int handle[4];
	int h;			//画像制御変数

	int _wave;

	EnemiesBulletManager eBM;

public:
	LREnemy2();
	LREnemy2(int hiswave);
	~LREnemy2();
	void update();

	void draw();

	int returnWavenum();
	bool returnBulletFlag(){ return false; };
	double returnX(){ return 0; };
	double returnY(){ return 0; };
};

