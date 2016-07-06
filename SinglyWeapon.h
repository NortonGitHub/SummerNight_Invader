#pragma once
#include "WeaponBase.h"
//�P���ԉ�

//enum NowPosition{
//	STOP,
//	STOP_1,
//	SHOT,
//	EFFECT,
//	END
//}position;

class SinglyWeapon : public WeaponBase
{
private:
	int frame;
	int i, j;
	double gra;

	double _x;
	double _y;
	double _sizeX;//�T�C�Y
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[10];	//�e
	int _hgraph[20]; //�ԉ�
	int _gNum;
	int _icon;//�A�C�R����

	double _time;

	void in_update();
	void in_draw();

	void Gravitation();

	bool sf_s;	//���������Ă��邩�ۂ�(SinglyWeapin version.)

	enum NowPosition{
		STOP,
		STOP_1,
		SHOT,
		EFFECT,
		END
	}position;

	//�ǉ����A���y�̏�������
	int HanabiA;
	int HanabiB;

public:

	SinglyWeapon();
//	SinglyWeapon(double x, double y, double sizeX, double sizeY, std::string graph); 
	
//	SinglyWeapon(double x,double y,bool &weapon);
	~SinglyWeapon();

	void preparation(int x,bool flag,int weapon_num);

	void update();

	void draw();

	void checkForPlayer(bool &weapon);	//�ԉΔ��ˌ� �e����������(��������������悤�ɂȂ���)���ǂ������`�F�b�N����B

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };

};

