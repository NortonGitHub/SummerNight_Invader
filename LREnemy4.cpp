#include "LREnemy4.h"


LREnemy4::LREnemy4()
{

}

LREnemy4::LREnemy4(int hiswave){
	std::random_device rd;
	std::mt19937 mt(rd());
	f = 0;
	_bullet = (mt() % 2 ? true : false);
	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;
	_x = mt() % 450;
	_y = -30;

	//handle = LoadGraph("data\\graphics\\LREnemy1.png");

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

LREnemy4::~LREnemy4()
{
	for (int i = 0; i < 4; i++){
		DeleteGraph(handle[i]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy4::update(){
	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}
	if (f % 10 == 0){
		_x += 15;
	}
	if (_x > 620){
		_x = 0;
		_y += 15;
	}
	f++;
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}
}

void LREnemy4::draw(){
	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, handle[h], TRUE);
}

int LREnemy4::returnWavenum(){
	return _wave;
}

bool LREnemy4::returnBulletFlag(){
	if (_bullet == true)
		return true;
	return false;
}

double LREnemy4::returnX(){
	return _x;
}

double LREnemy4::returnY(){
	return _y;
}

int LREnemy4::getEnemyHP(){
	return _HP;
}

void LREnemy4::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy4::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy4::getHasFlashed(){
	return flashFlag;
}


void LREnemy4::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int LREnemy4::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}