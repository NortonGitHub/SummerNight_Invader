#pragma once
#include "EnemiesBullet.h"
#include <vector>

class EnemiesBulletManager
{
private:
	int frame;
	int _x;
	int _y;
	std::vector<EnemiesBullet*> b;
public:
	EnemiesBulletManager();
	~EnemiesBulletManager();

	void update(int x,int y);
	void draw();

};

