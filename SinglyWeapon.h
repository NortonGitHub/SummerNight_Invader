#pragma once
#include "WeaponBase.h"
//単発花火

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
	double _sizeX;//サイズ
	double _sizeY;

	int _graphSizeX;
	int _graphSizeY;

	int _graph[10];	//弾
	int _hgraph[20]; //花火
	int _gNum;
	int _icon;//アイコン蔵

	double _time;

	void in_update();
	void in_draw();

	void Gravitation();

	bool sf_s;	//撃ちだしているか否か(SinglyWeapin version.)

	enum NowPosition{
		STOP,
		STOP_1,
		SHOT,
		EFFECT,
		END
	}position;

	//追加分、音楽の情報を入れる
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

	void checkForPlayer(bool &weapon);	//花火発射後 弾が爆発した(次が撃ちだせるようになった)かどうかをチェックする。

	void setWeaponStatus(int _status);
	int getWeaponStatus();

	double getX(){ return _x; };
	double getY(){ return _y; };

};

