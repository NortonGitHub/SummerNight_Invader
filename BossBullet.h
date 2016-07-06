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

	const double dx = 2.0;	//1�t���[���ɂ�����x�������ւ̈ړ���
	const double dy = 4.0;	//1�t���[���ɂ�����y�������ւ̈ړ���

public:
	BossBullet(double _x, double _y,int _type);
	~BossBullet();

	void update();
	void draw();

	double getX();
	double getY();

};

