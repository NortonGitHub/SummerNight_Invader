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
	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
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
	int getEnemyHP(){ return 0; };				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed(){ return false; };			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp){};	//�����t���O��Ԃ�
	int getExplosionFlag(){ return 0; };		//�����t���O�𓾂�
};

