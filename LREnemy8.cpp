#include "LREnemy8.h"


LREnemy8::LREnemy8()
{
}

LREnemy8::LREnemy8(int hiswave,int cnt){
	_bullet = ((cnt % 2) == 0 ? true : false);//(mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = 50;//(mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = -25 * (cnt + 1);//(mt() % 400);
	_y = -25 * (cnt + 1);
	_wave = hiswave;
	xs = _x;
	ys = _y;
	//_time = time;
	moveX1 = 8.0;
	moveY1 = 1.5;
	f = 0;
	h = 0;
	i = 0;
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

LREnemy8::~LREnemy8()
{
	for (int i = 0; i < 4; i++){
		DeleteGraph(HandleN[i]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy8::update(){
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
	if ((f >100 && _x < 19) || _x > 431)
	{
		change = true;
	}

	else
	{
		change = false;
	}

	if (_y > 350 + i || (_y < 25 && f>100))
	{
		change2 = true;
	}

	else
	{
		change2 = false;
	}

	if (change)
	{
		moveX1 = -moveX1;
	}

	if (change2)
	{
		moveY1 = -moveY1;
		i += 15;
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void LREnemy8::draw(){
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, HandleN[h], TRUE);
}

int LREnemy8::returnWavenum()
{
	return _wave;
}

bool LREnemy8::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double LREnemy8::returnX(){
	return _x;
}

double LREnemy8::returnY(){
	return _y;
}

int LREnemy8::getEnemyHP(){
	return _HP;
}

void LREnemy8::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy8::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy8::getHasFlashed(){
	return flashFlag;
}

void LREnemy8::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int LREnemy8::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}