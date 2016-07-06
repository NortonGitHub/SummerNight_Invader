#pragma once
#include "DxLib.h"
#include "WeaponBase.h"

#include "EnemyBase.h"//この辺は書き変わったようなので後で変更します
//#include "StageManager.h"
//#include "Player.h"
//#include "ConfigureStage.h"
#include "EnemiesBullet.h"
#include "GameOver.h"

#include <vector>

class Collision{
private:
	enum weaponType{
		Singly,
		Quick,
		Jet
	}weapon;//weaponに変数が入っているのか？

	bool Hitflag;//当たってるかどうかのフラグ
	bool Deadflag;//死んだかどうか
	bool Killflag;//あたり判定が出現しているかどうかのフラグ 必要か?

	std::vector<int> HanabiHandle;//花火のアニメーション枚数
	std::vector<int> EnemyHandle;//敵のアニメーション枚数
	std::vector<int> FireHandle;//(打ち上げ途中の)花火。もしかしたらいらないかも
	std::vector<int> BossHandle;//ボス
	std::vector<int> PlayerHandle;
	int BombHandle[21];//六尺のアニメーション。おそらく普通の配列になる

//	int _x;
//	int _y;//自機の中心点
	const int _r;//半径
	int _sizeX;
	int _sizeY;//サイズ
	int _moveX;
	int _moveY;//移動距離flag
//	double _Enemyx;
//	double _Enemyy;
	int _Enemyr;//座標、半径
	int _Enemysizex;
	int _Enemysizey;//画像サイズ
	const int _DeadLine;
	int _Bossr;
	int _Bosssizex;
	int _Bosssizey;
//	int _Shotx;
//	int _Shoty;
	int _Shotr;//弾、筒の中心点と半径
//	double _EnemyShotx;
//	double _EnemyShoty;
	double _EnemyShotr;
	int _Bomb;//六尺が打てる回数

//	int _PlayerHP;
//	int _EnemyHP;
//	int _ShieldHP;
//	int _BossHP;

	bool Animationchange;//花火のアニメーション切り替え判定
	bool Enemyflag;//敵が出現しているかどうか
	//bool DeadLine;//デッドライン越えたかどうか。いらないかも
	bool Playerflag;//何かが当たったかどうかのフラグ
	int frame;//フレーム数
	bool isDead;//画像点滅処理用
	bool isFlash;

	enum Enemycount{
		NORMAL, 
		SHIELD, 
		BOSS 
	}enemy_n;//敵の種類
	int _k;
	int _i;//六尺アニメーション用
	//int _enemy_n;//enumの変数格納

	int _class;//動的確保用、試験実装

	//enum Enemy{
	//	one,
	//	two,
	//	three
	//}enemy;//敵の種類に合わせた1ウェーブごとの敵数格納用
	int gettotal;

public:


	//サウンド
	int DeadSE;//敵死亡時のSE
	int DeadBoss;//ボス死亡時
	void ClackSE();//死亡時にSEを出す
	void ClackBoss();//Boss

	//ボス周り

	//boss...ボス本体座標,pBullet...プレイヤー弾座標
//	bool DeadBoss(double bossX, double bossY, double pBulletX, double pBulletY);
	// Boss01の雑魚のあたり判定
	bool DeadFollowerOf01(double followerX, double followerY, double pBulletX, double pBulletY);

	//敵周り

	/*void*/bool DeadEnemy(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy,int *_EnemyHP,int _weapon,int _weaponSt);//敵画像消去
	bool DeadBosses(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy, int *_EnemyHP, int _weapon, int _weaponSt); //ボス画像消
	//死ぬときは敵点滅させたいなー……？ 〇、ただし仕組みは解読中
	//void KillEnemy();//1ウェーブの敵を全滅させたら次に移行


	//自機回り
	int damageHandle;//ダメージ画像
	bool PlayerDamageFromEnemy(double _playerX,double _playerY,double _enemyX,double _enemyY);//ダメージ受けた時の画像切り替え
	bool PlayerDamageFromBullet(double _playerX, double _playerY, double _eShotX, double _eShotY);
	void NoDamage();//死んだ直後の無敵時間を設ける(？)、処理自体をPlayerDamageの中に入れてもいい

	//花火関連
	int HanabiA;
	int HanabiB;
	int HanabiC;
	void ClackHanabi();//花火が撃ちあがる途中のSE
	void ClackHanabi2();//花火が開いた時

	//六尺用
	void Bomb();//六尺あたり判定

	//デッドライン判定
	void DeadLine();//デッドライン超えるかどうかの判定とその後の処理

	//その他
	Collision();//コンストラクタ
	~Collision();//デストラクタ
	void CheckHit();
	void Update();
};