#include "LREnemy1.h"

LREnemy1::LREnemy1()
{
	
}

LREnemy1::LREnemy1(int hiswave)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	frame = 0;
	f = 0;
	count = 0;
	flag = true;

	_bullet = (mt() % 2 ? true : false);

	if (_bullet == false)
		_HP = (mt() % 2 ? 40 : 50);
	else
		_HP = 40;

	_x = mt() % 420;
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


LREnemy1::~LREnemy1()
{
	for (h = 0; h < 4; h++)
		DeleteGraph(handle[h]);
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void LREnemy1::update(){
	frame++;
	if (_x > 420/*570*/)
	{
		flag = false;
	}
	else if (_x < /*3*/0)
	{
		flag = true;
	}
	++f;
	if (f >= 100 && count <= 50)
	{
		if (count % 2 == 0){
			//_x += 4;10;
			count++;
		//	shotFlag = true;
		}
		else{
			//_x -= 4;10;
			count++;
		}
		if (count >= 50){
			f = 0;
			count = 0;
			_y += 30;
		}
	}

	else if (f % 2 == 0){
		if (flag){
			_x += 4;
		}
		else{
			_x -= 4;
		}
	}
	if (f % 7 == 0){
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}

	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= ExplosionHandle){
		explosion = 2;
	}

	//if (_bullet == true)
	//	eBM.update((int)_x,(int)_y);
}

void LREnemy1::draw(){

	if (h == 4)
		h = 0;
	if (explosion == 1)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	else if (!flashFlag || f % 3 == 0)
		DrawRotaGraph((int)_x, (int)_y, 1.0, 0.0, handle[h], TRUE);
	//if (_bullet == true)
	//	eBM.draw();
}

int LREnemy1::returnWavenum(){
	return _wave;
}

bool LREnemy1::returnBulletFlag(){
	if (_bullet == true && f >= 100 && count <= 50)
		return true;
	return false;
}

double LREnemy1::returnX(){
	return _x;
}

double LREnemy1::returnY(){
	return _y;
}

/*bool LREnemy1::shotFlag()
{
	return shotFlag;
}*/


int LREnemy1::getEnemyHP(){
	return _HP;
}

void LREnemy1::setEnemyHP(int _Hp){
	_HP = _Hp;
}

void LREnemy1::setFlashFlag(bool _flag){
	flashFlag = _flag;
}

bool LREnemy1::getHasFlashed(){
	return flashFlag;
}

void LREnemy1::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int LREnemy1::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}