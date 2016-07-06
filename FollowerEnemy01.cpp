#include "FollowerEnemy01.h"

int FollowerEnemy01::count = 0;	//Ã“Iƒƒ“ƒo•Ï”‚ÌŽÀ‘Ô

const int FollowerEnemy01::valuesForCos[5] = { 0, 1, 3, 2, 5 };
const int FollowerEnemy01::valuesForSin[5] = { 0, 1, 2, 4, 1 };
const int FollowerEnemy01::valuesForVertical[5] = { 120, 120, 120, 150, 100 };




FollowerEnemy01::FollowerEnemy01()            
{
	if (count >= 5) count = 0;
	x = 320;
	y = 240;
	t = 0;
	f = 0;
	h = 0;
	_cos = 1;
	_sin = 0;
	hisNumber = count;
	count++;
	HP = 40;
	flashFlag = false;
	explosion = 0;
	E_Num = 0;
	LoadDivGraph("data\\graphics\\Follower_Normal.png", 4, 1, 4, 64, 64, Handle); 
	LoadDivGraph("data\\graphics\\EnemyBomb1.png", 10, 1, 10, 64, 64, ExpHandle);
}


FollowerEnemy01::~FollowerEnemy01()
{
	for (int i = 0; i < 4; i++){
		DeleteGraph(Handle[i]);
	}
	for (h = 0; h < 10; h++){
		DeleteGraph(ExpHandle[h]);
	}
}

void FollowerEnemy01::update(){
	if (t >= 6.28){
		t = 0;
	}
	else{
		t += 0.06;
	}

	if (f % 7 == 0)
	{
		if (explosion == 1)
			E_Num++;
		else
			h++;
	}

	if (flashFlag && f - fForFlash >= frameForFlash)
		flashFlag = false;
	if (explosion == 1 && E_Num >= explosionHandle){
		explosion = 2;
	}

	++f;
}

void FollowerEnemy01::draw(){
	if (h == 4)
	{
		h = 0;
	}

	if (explosion == 1)
		DrawRotaGraph((int)(x + _cos), (int)(y + _sin), 1.0, 0.0, ExpHandle[E_Num], TRUE,FALSE);
	else if (!flashFlag || f % 3 == 0){
		_cos = cos(t + valuesForCos[hisNumber]) * 200;
		_sin = sin(t + valuesForSin[hisNumber]) * valuesForVertical[hisNumber];
		DrawRotaGraph((int)(x + _cos), (int)(y + _sin), 1.0, 0, Handle[h], TRUE, FALSE); //•`‰æ
	}
}

void FollowerEnemy01::setBossCoord(double _x, double _y){
	x = _x;
	y = _y;
}
