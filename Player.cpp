#include "Player.h"

//#include "ConfigureStage.h"

Player::Player()
{


	LoadDivGraph("data\\graphics\\Player.png", 6, 3, 2, 32, 32, handle);
	LoadDivGraph("data\\graphics\\Player_death.png", 2, 2, 1, 32, 32, handleForDeath);
	DamegeSound = LoadSoundMem("data\\sound\\SE\\zikisibou3.wav");

	_x = 0;
	_y = 518;
	direction = Right;

	_live = 3;	//残機

	//あたり判定
	_sizeX = 32;
	_sizeY = 32;

	T_changing = 0.0;
	T_weapons = 0.0;

	weapon = Singly;
	weapon_n = 0;
	
	_gNum = 1;
	_gCount = 0;


	_moveX = 0;
	_moveY = 0;
	_weight = 15;	//キャラの横幅
	
	for (int i = 0; i < 2; i++){
		_weapon[i].count = 2;
		_weapon[i].sf_p = false;
	}

	wasAttackedFrame = 0;

	flag_changed = false;
	playerDiedFlag = false;
	wasAttackedFlag = false;

/*	SinglyWeapon();
	QuickWeapon();
	JetWeapon();
	PipeOfWeapon();
	RokusyakuWeapon();*/

	for (int i = 0; i < 2; i++){
		_pipe[i].pipe = new PipeOfWeapon();
	}
	_weapon[0].weapon_B = new SinglyWeapon();
	_weapon[1].weapon_B = new SinglyWeapon();

}

Player::~Player(){
	for (int i = 0; i < 7; i++){
		DeleteGraph(handle[i]);
	}
}

void Player::draw()
{
	/*TEST MESSAGE*/ 
//	DrawFormatString(0, 60, GetColor(255, 255, 200), "_x = %4.1f sf_p[0][1] = %d %d  dir = %d", _x , _weapon[0].sf_p,_weapon[1].sf_p,direction );
//	DrawFormatString(0, 75, GetColor(255, 255, 200), "_live:%d",_live);
//	DrawFormatString(0, 90, GetColor(255, 255, 200), "wasAttackedFrame:%d", wasAttackedFrame);

	if (wasAttackedFlag){
		if (direction == Right){ DrawGraph((int)_x, (int)_y, handleForDeath[0], true); }
		else { DrawGraph((int)_x, (int)_y, handleForDeath[1], true); }
	}
	else{
		DrawGraph((int)_x, (int)_y, handle[_gNum], true);
	}

	for (int i = 0; i < 1; i++){
		_weapon[i].weapon_B->draw();
		_pipe[i].pipe->draw();
	}

	for (int p = 0; p < _live - 1; p++){
		DrawGraph(p * 32, 560, handle[1], true);
	}

}

void Player::update(double *shotX, double *shotY, int *weaponNum, int *status , bool *_wasAttacked){


	//キーのチェック
	frame++;

	if (!wasAttackedFlag){	//ダメージ判定中は動けないようにしておく。

		if (CheckHitKey(KEY_INPUT_LEFT) == 1 && _x > 0){
			direction = Left;
			_x -= 4;
			_gCount++;
			if (_gCount >= 10){
				if (_gNum == 3)
					_gNum = 4;
				else
					_gNum = 3;
				_gCount = 0;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && _x < 421){
			direction = Right;
			_x += 4;
			_gCount++;
			if (_gCount >= 10){
				if (_gNum == 0)
					_gNum = 1;
				else
					_gNum = 0;
				_gCount = 0;
			}
		}

		int i = 0;	//一応一発まで設置可能にしておく。

		changing_weapon(i);
		*weaponNum = weapon_n;

		if (CheckHitKey(KEY_INPUT_Z) == 1 && _weapon[i].sf_p == false && GetNowCount() - T_weapons > 300){//設置！
			if (_gNum <= 2)
				_gNum = 2;
			else
				_gNum = 5;

			placing(i, weapon);
			T_weapons = GetNowCount();
		}

		if (CheckHitKey(KEY_INPUT_UP) == 1 && GetNowCount() - T_changing > 500){
			if (weapon_n == 2){
				weapon_n = 0;
			}
			else{
				weapon_n++;
			}
			flag_changed = true;
			T_changing = GetNowCount();
		}


		_weapon[i].weapon_B->setWeaponStatus(*status);

		if (_weapon[i].sf_p == true){
			_weapon[i].weapon_B->update();
			*shotX = _weapon[i].weapon_B->getX();
			*shotY = _weapon[i].weapon_B->getY();
			_weapon[i].weapon_B->checkForPlayer(_weapon[i].sf_p);	//お試し程度で実装
			_pipe[i].pipe->checkForPlayer(_weapon[i].sf_p);
		}
		*status = _weapon[i].weapon_B->getWeaponStatus();
	}


	if (*_wasAttacked){
		if (!CheckSoundMem(DamegeSound)){
			PlaySoundMem(DamegeSound, DX_PLAYTYPE_BACK);
		}
		*_wasAttacked = false;
		wasAttackedFlag = true;
	}

	if (wasAttackedFlag){
		if (wasAttackedFrame >= 50){
			wasAttackedFrame = 0;
			wasAttackedFlag = false;
			_live--;
			_x = 0;
			_y = 518;
		}
		else{
			++wasAttackedFrame;
		}
	}
}


void Player::placing(int i,enum weaponType type){

	//switch (type){
	//case Singly:
	//	SinglyWeapon(_x, _y, sf);	//ここのタイミングでSingly関連の値を初期化したい
	//	break;
	//case Quick:
	//	QuickWeapon(_x, _y);
	//	break;
	//case Jet:
	//	JetWeapon(_x, _y);
	//	break;
	//}
	//PipeOfWeapon(_x, _y);

	_weapon[i].sf_p = true;

	double _x2 = _x;

	if (direction == Right)
		_x2 += 32;

	_weapon[i].weapon_B->preparation((int)_x2, _weapon[i].sf_p,type);//weaponの判別が必要
	_pipe[i].pipe->preparation((int)_x2, _weapon[i].sf_p, type);

	//switch (type){//ここでsf = trueとなる
	//case Singly:
	//	singlyWeapon.preparation((int)_x,  sf_p);	//ここもコンストラクタにする必要性有か(classが連立してしまっているため)
	//	break;
	//case Quick:
	//	quickWeapom.preparation((int)_x, , sf_p);
	//	break;
	//case Jet:
	//	jetWeapon.preparation((int) _x,sf_p);
	//	break;
	//}
	//PipeOfWeapon(/*R_x(),R_f()*/(int)_x,sf_p);
	

}

void Player::changing_weapon(int i)
{
	if (_weapon[i].sf_p == false && /*(int)weapon != weapon_n &&*/ flag_changed == true){

		delete _weapon[i].weapon_B;

		switch (weapon_n){
		case 0:
			weapon = Singly;
			_weapon[i].weapon_B = new SinglyWeapon();
			break;
		case 1:
			weapon = Quick;
			_weapon[i].weapon_B = new QuickWeapon();
			break;
		case 2:
			weapon = Jet;
			_weapon[i].weapon_B = new JetWeapon();
			break;
		}

		flag_changed = false;
	}


}

void Player::checking(enum weaponType type){

	//switch (type){
	//case Singly:
	//	singlyWeapon.checkForPlayer(sf_p);
	//	break;
	//case Quick:
	//	quickWeapom.checkForPlayer(sf_p);
	//	break;
	//case Jet:
	//	jetWeapon.checkForPlayer(sf_p);
	//	break;
	//}

}

int Player::R_weapon(){
	return weapon;
}

double Player::getX()const{
	return _x;
}
double Player::getY() const{
	return _y;
}

bool Player::getPlayerLive(){
	if (_live <= 0)
		playerDiedFlag = true;
	return playerDiedFlag;
}