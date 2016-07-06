#pragma once
#include "WeaponBase.h"

class QuickWeapon : public WeaponBase
{
private:
	int frame;
	int i, j;

	double _x;
	double _y;
	double _sizeX;//�T�C�Y
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[10];		//�e
	int _hgraph[11];	//�ԉ�
	int _gNum;
	int _iconQ;			//�ԉ΃A�C�R���p�G

	int placeTime;		//�ݒu��������
	int elapsedTime;	//�ݒu���Ă���̌o�ߎ���

	double time;

	enum NowPosition{

		STOP,
		STOP_1,
		SHOT,
		EFFECT,
		END

	}position;

	int count;
	int Cr;	//�ԉ΂̐F�w��ϐ�

	bool sf_q;	//���������Ă��邩�ۂ�(QuickWeapin version.)

	void in_update();
	void in_draw();

	int HanabiA, HanabiB;//�ǉ��A���f�[�^�i�[

public:
	QuickWeapon();
	//QuickWeapon(double x, double y, double sizeX, double sizeY, std::string graph);

	//QuickWeapon(double x, double y);
	~QuickWeapon();

	void update();

	void draw();

	void preparation(int x, bool flag,int weapon_num);

	void checkForPlayer(bool &weapon);

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };
};

