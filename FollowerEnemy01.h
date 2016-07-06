#pragma once
#include "DxLib.h"
#include "BossBase.h"
#include <cmath>


class FollowerEnemy01 : public BossBase
{
private:

	//const int explosionHandle = 10;
	//const int frameForFlash = 60;

#define explosionHandle 10
#define frameForFlash 60

	int Handle[4];

	double t;	//�O�p�֐�����
	int f;	//�t���[�����[�g����
	int h;	//�摜����

	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[explosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p

	int hisNumber;	//�G�̈�̂Ɋ���U��ꂽ�b��I�Ȕԍ�
	int HP;	//�q�b�g�|�C���g

	double x;
	double y;

	double _cos;
	double _sin;

	double bossX;
	double bossY;

	static int count;	//�G�̐��̃J�E���g(�ÓI�����o�ϐ�)

	static const int valuesForCos[5];
	static const int valuesForSin[5];
	static const int valuesForVertical[5];


public:

	FollowerEnemy01();
	~FollowerEnemy01();

	  void update();
	  double getX(){ return x + _cos; };
	  double getY(){ return y + _sin; };

	  void setHP(int _hp){};
	  int getHP(){ return 0; };

	  void setFlashFlag(bool _flash){
		  flashFlag = _flash;
		  fForFlash = f;
	  };	//�_�Ńt���O�𓾂�
	  bool getHasFlashed(){ return false; };			//�_�ł��I�����t���O��Ԃ�
	  void setExplosionFlag(int _exp){ explosion = _exp; };	//�����t���O��Ԃ�
	  int getExplosionFlag(){ return explosion; };		//�����t���O�𓾂�

	  void setBossCoord(double _x,double _y);	//�{�X���W��

	  void draw()  ;


};



//const int FollowerEnemy01::explosionHandle = 10;
//const int FollowerEnemy01::frameForFlash = 60;

