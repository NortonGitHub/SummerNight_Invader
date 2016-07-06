#include "BossBullet.h"


BossBullet::BossBullet(double _x,double _y,int _type)
{
	x = _x;
	y = _y;
	type = _type;

	Handle = LoadGraph("data\\graphics\\bullet2.png");

}


BossBullet::~BossBullet()
{
}

void BossBullet::update(){
	//if (f % 120 == 0){
	//	tamax[0] = x;
	//	tamax[1] = x;
	//	tamax[2] = x;
	//	tamay[0] = y;
	//	tamay[1] = y;
	//	tamay[2] = y;

	//	DrawRotaGraph((double)tamax[0], (double)tamay[0], 1, 0, thandle, TRUE, FALSE); //•`‰æ
	//	DrawRotaGraph((double)tamax[1], (double)tamay[1], 1, 0, thandle, TRUE, FALSE);
	//	DrawRotaGraph((double)tamax[2], (double)tamay[2], 1, 0, thandle, TRUE, FALSE);
	//}
	//	if (Tcount = true){
	y -= -5;
	switch (type){
	case 1:
		x -= dx;
		y += dy;
		break;
	case 2:
		x += dx;
		y += dy;
		break;
	}


	/*	if (tamay[0] >= 460){
			Tcount = false;
			}*/
}

void BossBullet::draw(){
	DrawRotaGraph((int)x, (int)y, 1, 0, Handle, TRUE, FALSE);
}

double BossBullet::getX(){
	return x;
}

double BossBullet::getY(){
	return y;
}