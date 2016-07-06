#include "SimpleEnemy1.h"


SimpleEnemy1::SimpleEnemy1(int hiswave,int cnt)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x =  35 + (cnt * 95);
	_y = -25;
	xs = _x;
	ys = _y;
	_time = 50;
	_wave = hiswave;
	f = 0;
	h = 0;
	flashFlag = false;

	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);

	if (_bullet == true)
		LoadDivGraph("data\\graphics\\Enemy_Atack.png", 4, 1, 4, 64, 64, HandleN); // 画像のロード
	else if (_HP == 50)
		LoadDivGraph("data\\graphics\\Enemy_Shield.png", 4, 1, 4, 64, 64, HandleN);
	else
		LoadDivGraph("data\\graphics\\Enemy_Normal.png", 4, 1, 4, 64, 64, HandleN);
	flashFlag = false;
	explosion = 0;
	E_Num = 0;

}


SimpleEnemy1::~SimpleEnemy1()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void SimpleEnemy1::update()
{
	f++;
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}
	_y += 0.5;
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void SimpleEnemy1::draw()
{
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);

};


int SimpleEnemy1::returnWavenum()
{
	return _wave;
}

bool SimpleEnemy1::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double SimpleEnemy1::returnX(){
	return _x;
}

double SimpleEnemy1::returnY(){
	return _y;
}

int SimpleEnemy1::getEnemyHP(){
	return _HP;
}

void SimpleEnemy1::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void SimpleEnemy1::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool SimpleEnemy1::getHasFlashed(){
	return flashFlag;
}

void SimpleEnemy1::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int SimpleEnemy1::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}