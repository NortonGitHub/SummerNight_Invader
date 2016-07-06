#include "EnemiesBullet.h"
#include "DxLib.h"

EnemiesBullet::EnemiesBullet()
{
}

EnemiesBullet::EnemiesBullet(double x, double y)
{

	bulletGraph = LoadGraph("data\\graphics\\bullet1.png");
	_x = x;
	_y = y;
	sf = true;
	t = 0;
	
}

EnemiesBullet::~EnemiesBullet()
{
	DeleteGraph(bulletGraph);
}

//�e�̓����B�e�̔��ˏ����͓G�̃N���X�̒�
void EnemiesBullet::Update(/*int x, int y*/){
	_y += 4.0;
}

void EnemiesBullet::Draw(){
	DrawGraph((int)_x, (int)_y, bulletGraph, true);
}

//_y��Y�̒l�������Ă���?
int EnemiesBullet::getY(){
	return (int)_y;
}

int EnemiesBullet::getX(){
	return (int)_x;
}
