#pragma once
#include <vector>
#include <random>
#include "BossBase.h"
#include "FollowerEnemy01.h"
#include "DxLib.h"

class Boss01 : public BossBase
{
private:
#define FrameForFlash 60
#define ExplosionHandle 10
	double x;
	double y;
	int f; //フレーム数計算用
	int s;
	int count;
	int check;
	int rota; //ボス画像回転用
	bool LR_Flag;//左右判定用
	int dx, dy;//1フレームでの移動量
	int width, height;//画面の横幅と縦幅
	int handle[9];//ボス画像
	int ohandle[5];//オプション画像
	int thandle;//弾画像
	int hp;

	void setFlashFlag(bool _flash);	//点滅フラグを得る
	bool getHasFlashed();			//点滅し終えたフラグを返す
	void setExplosionFlag(int _exp);	//爆発フラグを返す
	int getExplosionFlag();		//爆発フラグを得る

	bool flashFlag;	//画像点滅フラグ
	int fForFlash;

	int explosion;	//"爆発した"というフラグ
	int ExpHandle[ExplosionHandle];	//爆発グラ用ハンドル
	int E_Num;		//爆発グラ制御用

	double _followerX[5];	//ボス周辺の敵のX座標格納用
	double _followerY[5];	//ボス周辺の敵のY座標格納用

	struct{
		double x;
		double y;
	}explosionCoord[10];
	static int explosionNumber;	//爆発する順番。初期値は0、最終値は10．

public:


	Boss01();
	~Boss01();

	void update();
	void draw();

	void bossItself();
	void updateForExplosion();

	void drawExplosion();
	
	double getX();
	double getY();
	void setHP(int _hp);
	int getHP();

	void setBossCoord(double _x, double _y){};
};
