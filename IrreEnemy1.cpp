#include "IrreEnemy1.h"


IrreEnemy1::IrreEnemy1()
{
}

IrreEnemy1::IrreEnemy1(int hiswave)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = mt() % 450;
	_y = -30;

	_wave = hiswave;
	xs = _x;
	ys = _y;
	//_time = time;
	f = 0;
	t = PI;
	i = 0;
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


IrreEnemy1::~IrreEnemy1()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void IrreEnemy1::update()
{
	f++;
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}
	
	if (t > 6.28)
	{
		t = 0.0;
	}

	if (_y < 60)
	{
		_y += 1;
	}

	if (60 <= _y)
	{
		t += PI / 50;
		_x = _x + cos(t) * -10;
		_y = _y + sin(t) * -10;
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
	
}

void IrreEnemy1::draw()
{
	if (h >= 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);

}

int IrreEnemy1::returnWavenum()
{
	return _wave;
}

bool IrreEnemy1::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double IrreEnemy1::returnX(){
	return _x;
}

double IrreEnemy1::returnY(){
	return _y;
}

int IrreEnemy1::getEnemyHP(){
	return _HP;
}

void IrreEnemy1::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void IrreEnemy1::setFlashFlag(bool _flag){
	flashFlag = _flag;
	fForFlash = f;
}

bool IrreEnemy1::getHasFlashed(){
	return flashFlag;
}

void IrreEnemy1::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}	

int IrreEnemy1::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}
