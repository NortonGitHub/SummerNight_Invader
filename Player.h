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

#define KeyM Keybord::instance()	//���ݎg�p���Ă��Ȃ�


class Player : public Object_Base
{
private:

	int handle[7];//�O���t�B�b�N�n���h��
	int handleForDeath[2];//���S�O��

	int DamegeSound;	//�U�����󂯂����̉���

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
		int count;//(����class�̏ꍇ)�C��̐ݒu�\�����������
		bool sf_p;	//�e�����������Ă��邩�ۂ�
		WeaponBase* weapon_B;	
	//	WeaponBase* now_weapon_B;
	}_weapon[2];

	struct PIPE{
		PipeOfWeapon* pipe;
	}_pipe[2];

	bool flag_changed;	

	Collision c;

	int _live;	//�c�@
	int wasAttackedFrame;	//:�U�����󂯂ĘT�����Ă���t���[���̃J�E���g
	bool wasAttackedFlag;	//�U�����󂯂��Ƃ����t���O�B���̃N���X���ł̂ݎg�p�B(������"_wasAttacked"�Ƃ͖��֌W!)
	bool playerDiedFlag;	//���@�����S�������ۂ��Btrue�Łu���S�����v�B��ɉ摜�\�����ɂāB


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