#include "IrreEnemy4.h"


IrreEnemy4::IrreEnemy4(int hiswave,int cnt)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = 218;
	_y = -25-(cnt*20);
	xs = _x;
	ys = _y;
	_time = 50-(cnt*10);
	_wave = hiswave;
	t = PI;
	f = 0;
	h = 0;
	moveX1 = 1;
	moveY1 = 1;

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


IrreEnemy4::~IrreEnemy4()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void IrreEnemy4::update(){
	if (_y<0)
	{
		_y += 2;
	}

	if (_y >= 0){

		t += 0.1;
		_y += 0.15;

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
			_x = 218;
		}
		_x = _x + cos(t) * 18;
		_y = _y + sin(t) * 5;
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void IrreEnemy4::draw(){
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);
}


int IrreEnemy4::returnWavenum()
{
	return _wave;
}

bool IrreEnemy4::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double IrreEnemy4::returnX(){
	return _x;
}

double IrreEnemy4::returnY(){
	return _y;
}


int IrreEnemy4::getEnemyHP(){
	return _HP;
}

void IrreEnemy4::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void IrreEnemy4::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool IrreEnemy4::getHasFlashed(){
	return flashFlag;
}

void IrreEnemy4::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int IrreEnemy4::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}
