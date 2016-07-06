#pragma once

//各ステージの敵などの情報を管理
#include "EnemyBase.h"
#include "WeaponBase.h"
#include "BossBase.h"

#include "DxLib.h"
#include <vector>

#include "LoadStagedata.h"
#include "LoadDatafile.h"

#include "Player.h"

#include "LREnemy1.h"
#include "LREnemy2.h"
#include "LREnemy3.h"
#include "LREnemy4.h"
#include "LREnemy5.h"
#include "LREnemy6.h"
#include "LREnemy7.h"
#include "LREnemy8.h"
#include "IrreEnemy1.h"
#include "IrreEnemy2.h"
#include "IrreEnemy3.h"
#include "IrreEnemy4.h"
#include "IrreEnemy5.h"
#include "SimpleEnemy1.h"

#include "Boss01.h"
#include "BossBullet.h"

class ConfigureStage /*: protected BossBase */
{
private:
	DataLoader* loader = new LoadDatafile();
	std::vector<EnemyBase*> enemys;
	
	int waveT;			//コンストラクタ内で使用
	int weaponTypeNum;	//0...Singly,1...Quick,2...Jet
	int waveNum;		//現在のウェーブはいくつか
	std::vector<int> waveTotal;// [5];		//該当ウェーブの敵総登場数
	int defeatedCount;	//1ウェーブにおける敵撃破数

	int explosionSound;	//爆発時のサウンド

	int frame;
	int untilSceneChange;	//ボス撃破からシーンチェンジまでのフレーム数
	bool sceneChangeFlag;	//ボス撃破からシーンチェンジまでのフレーム計測を開始するフラグ
	int ToBossSceneFrame;	//雑魚ステージ終了からボスステージへ移行するまでのフレーム数
	bool ToBossSceneFlag;	//ボスステージへ移行するためのフラグ
	bool ToBossSceneFlag2;	//雑魚ステージ終了からボスステージへ移行するまでのフレーム計測を開始するフラグ


	double _eX;
	double _eY;
	int _eHP;

	double _bX;
	double _bY;
	int _bHP;

	bool deadLineFlag;	//デッドラインを越えたというフラグ

	//SinglyWeapon singly;
	//QuickWeapon quick;
	//JetWeapon jet;
	Collision c;

//	EnemiesBulletManager eBM;

	//弾のvector
	std::vector<EnemiesBullet*> e_Bullet;
	std::vector<BossBase*> bosses;
	std::vector<BossBullet*> b_Bullet;
	std::vector<BossBase*> followers;
	
public:
	ConfigureStage();
	ConfigureStage(int stagenum_cs);
	~ConfigureStage();

	void update(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked, int *stagenum_cs);
	void updateForEnemys(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked);	//通常敵のupdate
	void updateForBosses(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked, int *stagenum_cs);	//ボスステージのupdate
	void updateForFollowers(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked);	//ボスステージに出てくる雑魚敵のupdate

	void draw();
	void drawForEnemys();
	void drawForBosses();
	void drawForFollowers();

	int getWaveNumNow();

	bool getDeadLine();
};

