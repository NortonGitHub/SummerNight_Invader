#include "LREnemy2.h"


LREnemy2::LREnemy2()
{

}

LREnemy2::LREnemy2(int hiswave)
{
	f = 0;
	flag = true;
	_bullet = (rand() % 2 ? true : false);
	if (_bullet == false)
		_HP = (rand() % 2 ? 40 : 50);
	else
		_HP = 40;

	_x = rand() % 450;
	_y = -30;

	//handle = LoadGraph("data\\graphics\\LREnemy2.png");
	if (_bullet == true)
		LoadDivGraph("data\\graphics\\Enemy_Atack.png", 4, 1, 4, 64, 64, handle); // ‰æ‘œ‚Ìƒ[ƒh
	else if (_HP == 50)
		LoadDivGraph("data\\graphics\\Enemy_Shield.png", 4, 1, 4, 64, 64, handle);
	else
		LoadDivGraph("data\\graphics\\Enemy_Normal.png", 4, 1, 4, 64, 64, handle);
	h = 0;

	_wave = hiswave;
}

LREnemy2::~LREnemy2()
{
}

void LREnemy2::update(){
	if (_x > 620)
	{
		flag = false;
		_y += sin(PI / 2 / 120 * Sinc) * 10;
	}
	else if (_x < 30)
	{
		flag = true;
		_y += sin(PI / 2 / 120 * Sinc) * 10;
	}
	if (f % 1 == 0){
		if (f <= 100){
			if (flag){
				_x++;
				if (f % 5 == 0){
					_y += sin(PI / 2 / 120 * Sinc);
				}
			}
			else{
				_x -= 1;
				if (f % 5 == 0){
					_y += sin(PI / 2 / 120 * Sinc);
				}
			}
		}
		else if (f <= 200){
			if (flag){
				_x++;
				if (f % 5 == 0){
					_y -= sin(PI / 2 / 120 * Sinc);
				}
			}
			else{
				_x -= 1;
				if (f % 5 == 0){
					_y -= sin(PI / 2 / 120 * Sinc);
				}
			}
		}
	}
	else if (f % 7 == 0){
		h++;
	}

	if (f == 200){
		f = 0;
	}
	f++;
	if (_bullet == true)
		eBM.update((int)_x, (int)_y);
}

void LREnemy2::draw(){
	if (h == 4)
		h = 0;
	DrawGraph((int)_x,(int)_y,handle[h],true);
}

int LREnemy2::returnWavenum()
{
	return _wave;
}

