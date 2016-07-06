#include "IrreEnemy2.h"
IrreEnemy2::IrreEnemy2()
{
}

IrreEnemy2::IrreEnemy2(int hiswave,int cnt)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = -60 * cnt;//(mt() % 400) + 19;
	_y = -30 * cnt;
	_cnt = cnt;
	_wave = hiswave;
	xs = _x;
	ys = _y;
	//_time = time;
	moveX1 = 2.0;
	moveY1 = 1.0;
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


IrreEnemy2::~IrreEnemy2()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void IrreEnemy2::update(){
	_x += moveX1;
	_y += moveY1;
	f++;
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}
	if (_x >= 500 && _y <= -25)
	{
		change = true;
	}

	else
	{
		change = false;
	}

	if (f >= 145 && _x <= -50 && _y <= -25)
	{
		change2 = true;
	}

	else
	{
		change2 = false;
	}

	if (_y >= 250)
	{
		change3 = true;
	}

	else
	{
		change3 = false;
	}

	if (change)
	{
		moveX1 = 2.0;
		moveX1 = -moveX1;
		moveY1 = -moveY1;
	}

	if (change2)
	{
		moveX1 = 2.0;
		moveY1 = -moveY1;
	}

	if (change3)
	{
		moveY1 = -moveY1;
		moveX1 = 0.0;

	}

	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void IrreEnemy2::draw(){
	if (h >= 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);
}

int IrreEnemy2::returnWavenum()
{
	return _wave;
}

bool IrreEnemy2::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double IrreEnemy2::returnX(){
	return _x;
}

double IrreEnemy2::returnY(){
	return _y;
}

int IrreEnemy2::getEnemyHP(){
	return _HP;
}

void IrreEnemy2::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void IrreEnemy2::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool IrreEnemy2::getHasFlashed(){
	return flashFlag;
}

void IrreEnemy2::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int IrreEnemy2::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}
