#pragma 
#include "EnemyBase.h"
#include "EnemiesBulletManager.h"	//�@�C���N���[�h���[�v�ɂ��"�\�����ʃG���["���ӕ����@10/02�t

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
	int h;			//�摜����ϐ�

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

