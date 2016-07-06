#include "LREnemy7.h"
LREnemy7::LREnemy7()
{

}

LREnemy7::LREnemy7(int hiswave)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = (mt() % 400) + 19;
	_y = -30;

	_wave = hiswave;
	xs = _x;
	ys = _y;
	f = 0;
	t = PI;
	i = 0;
	moveX1 = 2.0;
	h = 0;

	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);

	if (_bullet == true)
		LoadDivGraph("data\\graphics\\Enemy_Atack.png", 4, 1, 4, 64, 64, HandleN); // 画像のロード
	else if (_HP == 50)
		LoadDivGraph("data\\graphics\\Enemy_Shield.png", 4, 1, 4, 64, 64, HandleN);
	else
		LoadDivGraph("data\\graphics\\Enemy_Normal.png", 4, 1, 4, 64, 64, HandleN);
	h = 0;
	flashFlag = false;
	explosion = 0;
	E_Num = 0;
}


LREnemy7::~LREnemy7()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy7::update(){
	_x += moveX1;// - moveX2);
	_y += 0.2;
	f++;
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}
	if ((/*_y > 50 &&*/ _x < 19) || _x > 431)
	{
		change = true;
	}

	else
	{
		change = false;
	}

	if (change)
	{
		moveX1 = -moveX1;
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void LREnemy7::draw(){
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);

}

int LREnemy7::returnWavenum()
{
	return _wave;
}

bool LREnemy7::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double LREnemy7::returnX(){
	return _x;
}

double LREnemy7::returnY(){
	return _y;
}

int LREnemy7::getEnemyHP(){
	return _HP;
}

void LREnemy7::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy7::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy7::getHasFlashed(){
	return flashFlag;
}

void LREnemy7::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int LREnemy7::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}