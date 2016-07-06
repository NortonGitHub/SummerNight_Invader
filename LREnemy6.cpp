#include "LREnemy6.h"


LREnemy6::LREnemy6()
{
}

LREnemy6::LREnemy6(int hiswave)
{

	std::random_device rd;
	std::mt19937 mt(rd());
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = mt() % 400;
	_y = 50;

	_wave = hiswave;
	xs = _x;
	ys = _y;
//	_time = time;
	t = 0.0;
	f = 0;
	h = 0;
	moveX1 = 2.0;

	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);

	if (_bullet == true)
		LoadDivGraph("data\\graphics\\Enemy_Atack.png", 4, 1, 4, 64, 64, HandleN); // �摜�̃��[�h
	else if (_HP == 50)
		LoadDivGraph("data\\graphics\\Enemy_Shield.png", 4, 1, 4, 64, 64, HandleN);
	else
		LoadDivGraph("data\\graphics\\Enemy_Normal.png", 4, 1, 4, 64, 64, HandleN);
	flashFlag = false;
	explosion = 0;
	E_Num = 0;
	exist = true;
}

LREnemy6::~LREnemy6()
{
	for (h = 0; h < 4; h++){
		DeleteGraph(HandleN[h]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy6::update(){
	if (_x<0 && _x>450 && _y < 0 && _y < 600)
	{
		exist = true;
	}
	else
	{
		false;
	}

	if (_x < 19)
	{
		_x += 2;
	}

	if (_x >= 19){
		_y = _y + sin(t) * 7;
		_x += moveX1;
		t += 0.1;
		f++;
		if (f % 7 == 0){
			if (explosion == 1)
				E_Num++;
			else
				h++;
		}

		if (t > 6.28)
		{
			t = 0.0;
		}
		if ((f > 100 && _x< 19) || _x > 431)
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
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle)
		explosion = 2;
}

void LREnemy6::draw()
{
	if (exist){
		if (h == 4)
			h = 0;
		if (explosion == 1)
			DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
		else if (!flashFlag || f % 3 == 0)
			DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);

	}
}

int LREnemy6::returnWavenum()
{
	return _wave;
}

bool LREnemy6::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double LREnemy6::returnX(){
	return _x;
}

double LREnemy6::returnY(){
	return _y;
}

int LREnemy6::getEnemyHP(){
	return _HP;
}

void LREnemy6::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy6::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy6::getHasFlashed(){
	return flashFlag;
}

void LREnemy6::setExplosionFlag(int _exp){//�����t���O��Ԃ�
	explosion = _exp;
}

int LREnemy6::getExplosionFlag(){		//�����t���O�𓾂�
	return explosion;
}