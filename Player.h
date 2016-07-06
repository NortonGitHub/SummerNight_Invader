#pragma once
#include <vector>
#include "Object_Base.h"
#include "WeaponBase.h"
#include "Collision.h"

#include "SinglyWeapon.h"
#include "QuickWeapon.h"
#include "JetWeapon.h"
#include "PipeOfWeapon.h"
#include "RokusyakuWeapon.h"

#define KeyM Keybord::instance()	//現在使用していない


class Player : public Object_Base
{
private:

	int handle[7];//グラフィックハンドル
	int handleForDeath[2];//死亡グラ

	int DamegeSound;	//攻撃を受けた時の音声

	enum weaponType{
		Singly,
		Quick,
		Jet
	}weapon;
	int weapon_n;
	int _gCount;
	int _gNum;
	int _gNumDeath;

	void placing(int i,enum weaponType type);
	void checking(enum weaponType type);

	void changing_weapon(int i);

	double _x;
	double _y;
	int _sizeX;
	int _sizeY;
	double _moveX;
	double _moveY;
	double _weight;
	enum directionOfTheBody{
		Right,
		Left
	}direction;

	double T_changing;	//this variable will have time used for changing weapon.
	double T_weapons;	//this variable will have time used for using weapon.

	int frame;

	struct WEAPON{
		int count;//(このclassの場合)砲台の設置可能上限数を示す
		bool sf_p;	//弾を撃ちだしているか否か
		WeaponBase* weapon_B;	
	//	WeaponBase* now_weapon_B;
	}_weapon[2];

	struct PIPE{
		PipeOfWeapon* pipe;
	}_pipe[2];

	bool flag_changed;	

	Collision c;

	int _live;	//残機
	int wasAttackedFrame;	//:攻撃を受けて狼狽えているフレームのカウント
	bool wasAttackedFlag;	//攻撃を受けたというフラグ。このクラス内でのみ使用。(引数の"_wasAttacked"とは無関係!)
	bool playerDiedFlag;	//時機が死亡したか否か。trueで「死亡した」。主に画像表示等にて。


	//SinglyWeapon singlyWeapon;
	//QuickWeapon quickWeapom;
	//JetWeapon jetWeapon;


	//std::vector<WeaponBase*> weapons; 

public:
	Player();
	~Player();
	void draw();

	void update(double *shotX, double *shotY, int *weaponNum, int *status, bool *_wasAttacked);

	int R_weapon();
	bool getPlayerLive();

	void move();

	double getX() const;
	double getY() const;
	double sizeX() const;
	double sizeY() const;
	double moveX() const;
	double moveY() const;

};

//Player player;