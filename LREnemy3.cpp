#include "LREnemy3.h"


LREnemy3::LREnemy3()
{

}

LREnemy3::LREnemy3(int hiswave){
	std::random_device rd;
	std::mt19937 mt(rd());
	speed = 0;
	f = 0;
	flag = true;
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = mt() % 450;
	_y = -30;

	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);

	if (_bullet == true)
		LoadDivGraph("data\\graphics\\Enemy_Atack.png", 4, 1, 4, 64, 64, handle); // 画像のロード
	else if (_HP == 50)
		LoadDivGraph("data\\graphics\\Enemy_Shield.png", 4, 1, 4, 64, 64, handle);
	else
		LoadDivGraph("data\\graphics\\Enemy_Normal.png", 4, 1, 4, 64, 64, handle);
	h = 0;
	_wave = hiswave;
	flashFlag = false;
	explosion = 0;
	E_Num = 0;
}

LREnemy3::~LREnemy3()
{
	for (int i = 0; i < 4; i++){
		DeleteGraph(handle[i]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy3::update(){
	if (_x > 622)
	{
		flag = false;
		_y += 10;
		f = 0;
		speed = 4;
	}
	else if (_x < 32)
	{
		flag = true;
		_y += 10;
		f = 0;
		speed = 4;
	}
	if (f % 2 == 0){
		if (flag){
			_x += speed;
		}
		else{
			_x -= speed;
		}
	}
	if (f % 7 == 0){
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}

	speed += 0.1;
	f++;
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void LREnemy3::draw(){
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, handle[h], TRUE);
}

int LREnemy3::returnWavenum()
{
	return _wave;
}

bool LREnemy3::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double LREnemy3::returnX(){
	return _x;
}

double LREnemy3::returnY(){
	return _y;
}

int LREnemy3::getEnemyHP(){
	return _HP;
}

void LREnemy3::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy3::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy3::getHasFlashed(){
	return flashFlag;
}

void LREnemy3::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int LREnemy3::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}