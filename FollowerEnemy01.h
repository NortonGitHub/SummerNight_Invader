#pragma once
#include "DxLib.h"
#include "BossBase.h"
#include <cmath>


class FollowerEnemy01 : public BossBase
{
private:

	//const int explosionHandle = 10;
	//const int frameForFlash = 60;

#define explosionHandle 10
#define frameForFlash 60

	int Handle[4];

	double t;	//三角関数制御
	int f;	//フレームレート制御
	int h;	//画像制御

	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[explosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用

	int hisNumber;	//敵の一個体に割り振られた暫定的な番号
	int HP;	//ヒットポイント

	double x;
	double y;

	double _cos;
	double _sin;

	double bossX;
	double bossY;

	static int count;	//敵個体数のカウント(静的メンバ変数)

	static const int valuesForCos[5];
	static const int valuesForSin[5];
	static const int valuesForVertical[5];


public:

	FollowerEnemy01();
	~FollowerEnemy01();

	  void update();
	  double getX(){ return x + _cos; };
	  double getY(){ return y + _sin; };

	  void setHP(int _hp){};
	  int getHP(){ return 0; };

	  void setFlashFlag(bool _flash){
		  flashFlag = _flash;
		  fForFlash = f;
	  };	//点滅フラグを得る
	  bool getHasFlashed(){ return false; };			//点滅し終えたフラグを返す
	  void setExplosionFlag(int _exp){ explosion = _exp; };	//爆発フラグを返す
	  int getExplosionFlag(){ return explosion; };		//爆発フラグを得る

	  void setBossCoord(double _x,double _y);	//ボス座標を

	  void draw()  ;


};



//const int FollowerEnemy01::explosionHandle = 10;
//const int FollowerEnemy01::frameForFlash = 60;

