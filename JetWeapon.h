#pragma once
#include "WeaponBase.h"
//�����ԉ�

class JetWeapon : public WeaponBase
{
private:

	int count;

	int i, j, k;

	double _x;
	double _y;
	double _sizeX;//�T�C�Y
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[9];
	int _gNum;
	int _icon;

	double placedTime;		//�ݒu��������
	double elapsedTime;	//�ݒu���Ă���̌o�ߎ���
	int frame;			//����

	int shottime;

	bool sf_j;	//���������Ă��邩�ۂ�(JetWeapin version.)

	enum NowPosition{
		STOP,
		STOP_1,
		SHOT,
		HOGE,//�Ӗ��̂Ȃ����Ԃ�����
		END

	}position;

	void in_update();
	void in_draw();

	int Hanabi;//�ǉ��A���f�[�^�i�[

public:
	JetWeapon();
	//JetWeapon(double x,double y,double sizeX,double sizeY,std::string graph);

	//JetWeapon(double x, double y);
	~JetWeapon();

	void update();

	void draw();

	void preparation(int x,bool flag,int weapon_num);

	void checkForPlayer(bool &weapon);

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };
};

