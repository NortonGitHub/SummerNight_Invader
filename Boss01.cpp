#include "Boss01.h"


int Boss01::explosionNumber;
Boss01::Boss01()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> random_X(0, 280);	//X軸座標の爆発位置の範囲を指定
	std::uniform_real_distribution<> random_Y(0, 80);	//Y軸座標の爆発位置の範囲を指定

	for (int i = 0; i < 10; i++){
		explosionCoord[i].x = random_X(mt);
		explosionCoord[i].y = random_Y(mt);
	}
	explosionNumber = 0;

	rota = 0;
	x = 320;
	y = 240;
	dx = 2;
	dy = 4;
	f = 0;
	count = 0;
	LR_Flag = true;
	hp = 3000;

	flashFlag = false;
	explosion = 0;
	E_Num = 0;

	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);
	LoadDivGraph("data\\graphics\\UFOboss1.png", 9, 1, 9, 300, 90, handle); //ボス画像ロード
	thandle = LoadGraph("data\\graphics\\bullet2.png");

}


Boss01::~Boss01()
{
	for (int i = 0; i < 9; i++){
		DeleteGraph(handle[i]);
	}
	for (int h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}

/*	for (int i = 0; i<3; i++){
		if (tamay[i]>700){
			DeleteGraph(thandle);
		}
	}*/
	for (int i = 0; i < 4; i++){
		DeleteGraph(ohandle[i]);
	}
	//DeleteSoundMem(explosionSound);
}

void Boss01::update(){
	if (explosion == 0){
		bossItself();
	}
	else{
		updateForExplosion();
	}
	++f;
}

void Boss01::bossItself(){

	if (x > 300)
	{
		LR_Flag = false;
		x -= 10;
		y += 4;
	}
	else if (x < 150)
	{
		LR_Flag = true;
		y += 4;
		x += 10;
	}

	if (f % 25 == 0){
		if (LR_Flag){
			x += 10;
		}
		else{
			x -= 10;
		}
		rota++;
	}

	if (f >= 1000)
	{
		f = 0;
	}
	if (flashFlag && f - fForFlash >= FrameForFlash)
		flashFlag = false;
	/*if (explosion == 1 && E_Num == ExplosionHandle){
		explosion = 2;
	}*/
}

void Boss01::updateForExplosion(){
	/*if (CheckSoundMem(explosionSound) == 0){
		PlaySoundMem(explosionSound, DX_PLAYTYPE_BACK);
	}*/
	if (explosionNumber == 10){	//爆発がすべて完了する 
		//StopSoundMem(explosionSound);
		explosion = 2;
	}
	if (f % 2 == 0){
		++E_Num;
		if (E_Num == ExplosionHandle){
			E_Num = 0;
			explosionNumber++;
		}
	}

}

void Boss01::draw(){
	if (rota > 8){
		rota = 0;
	}
	DrawGraph((int)x - 150, (int)y - 45, handle[rota], TRUE);
	if (explosion == 1)	//爆発表示
	{
		int _x = (x - 150) + (int)(explosionCoord[explosionNumber].x);
		int _y = (y - 45) + (int)(explosionCoord[explosionNumber].y);
		DrawRotaGraph(_x, _y, 1.0, 0.0, ExpHandle[E_Num], TRUE);
	}
}

double Boss01::getX(){
	return x;
}

double Boss01::getY(){
	return y;
}

void Boss01::setHP(int _hp){
	hp = _hp;
}

int Boss01::getHP(){
	return hp;
}


void Boss01::setFlashFlag(bool _flag){
	flashFlag = _flag;
	fForFlash = f;
}

bool Boss01::getHasFlashed(){
	return flashFlag;
}

void Boss01::setExplosionFlag(int _exp){//爆発フラグを返す
	explosion = _exp;
}

int Boss01::getExplosionFlag(){		//爆発フラグを得る
	return explosion;
}