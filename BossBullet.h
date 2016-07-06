#pragma once
#include "DxLib.h"
#include <vector>

class BossBullet
{
private:
	double x;
	double y;
	int type;

	int Handle;

	const double dx = 2.0;	//1フレームにおけるx軸方向への移動量
	const double dy = 4.0;	//1フレームにおけるy軸方向への移動量

public:
	BossBullet(double _x, double _y,int _type);
	~BossBullet();

	void update();
	void draw();

	double getX();
	double getY();

};

