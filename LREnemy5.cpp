#include "LREnemy5.h"


LREnemy5::LREnemy5()
{

}

LREnemy5::LREnemy5(int hiswave){
	frame = 0;
	f = 0;
	flag = true;
	bai = 1.0;
	_bullet = (rand() % 2 ? true : false);
	_HP = (rand() % 2) + 1;
	_x = rand() % 450;
	_y = -30;

	handle = LoadGraph("data\\graphics\\LREnemy5.png");
	_wave = hiswave;
}

LREnemy5::~LREnemy5()
{
}

void LREnemy5::update(){
	frame++;
	if (_x > 570)
	{
		flag = false;
		_y += 20;
	}
	else if (_x < 30)
	{
		flag = true;
		_y += 20;
	}
	if (f % 2 == 0){
		if (flag){
			_x += 1;
		}
		else{
			_x -= 1;
		}
	}
	if (f <= 200){
		bai += 0.005;
	}
	else if (f <= 400){
		bai -= 0.005;
	}
	if (f == 400){
		f = 0;
	}
	f++;
}

void LREnemy5::draw(){
	DrawGraph((int)_x,(int)_y, handle, true);
}

int LREnemy5::returnWavenum()
{
	return _wave;
}

void LREnemy5::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy5::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

