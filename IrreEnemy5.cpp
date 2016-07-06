#include "IrreEnemy5.h"


IrreEnemy5::IrreEnemy5(int hiswave,int cnt)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = 229;
	_y = -25 - (cnt *  15);
	xs = _x;
	ys = _y;
	_time = 50 - (cnt * 10);
	_wave = hiswave;
	t = 0.0;
	f = 0;
	h = 0;

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


void IrreEnemy5::update(){
	f++;
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}

	if (_y < 0)
	{
		_y += 2;
	}

	if (_y >= 0){
		t += 0.05;
		if (t == 6.48){
			t = 0.0;
		}

		_x = _x + cos(t) * 10;
		_y += 0.5;
		if (flashFlag && f - fForFlash >= FrameForFlash)
			flashFlag = false;
		if (explosion == 1 && E_Num >= ExplosionHandle){
			explosion = 2;
		}
	}
}

void IrreEnemy5::draw(){

	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);
}
IrreEnemy5::~IrreEnemy5()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
}


int IrreEnemy5::returnWavenum()
{
	return _wave;
}

bool IrreEnemy5::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double IrreEnemy5::returnX(){
	return _x;
}

double IrreEnemy5::returnY(){
	return _y;
}


int IrreEnemy5::getEnemyHP(){
	return _HP;
}

void IrreEnemy5::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void IrreEnemy5::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool IrreEnemy5::getHasFlashed(){
	return flashFlag;
}

void IrreEnemy5::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int IrreEnemy5::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}