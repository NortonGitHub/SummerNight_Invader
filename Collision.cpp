#include "Collision.h"

Collision::Collision()
	: _r(16)
	, _DeadLine(550)//const��`��{}�n�܂�O�ɏ���
{
	//�R���X�g���N�^���ϐ��̏������A���
	_Enemyr = 32;
	_Enemysizex = 64;
	_Enemysizey = 64;

	_Bossr = 50;
	_Bosssizex = 280;
	_Bosssizey = 80;

	Enemyflag = true;
	Hitflag = false;
	Deadflag = false;
	Killflag = true;
	Animationchange = false;

	//_EnemyHP = 40;
	//_ShieldHP = 50;
	//_BossHP = 1200;
	//_PlayerHP = 3;

	_k = 0;
	frame = 0;

//	DeadSE = LoadSoundMem("massatu.wav");//SE�ǂݍ���
//	DeadBoss = LoadSoundMem("BossD.wav");
//	HanabiA = LoadSoundMem("hyu1_6.wav");
//	HanabiB = LoadSoundMem("hunnsui.wav");
//	HanabiC = LoadSoundMem("ban1_5.wav");

	_Shotr = 13;

//	LoadDivGraph("rokusyaku.png", 21, 3, 10, 100, 100, BombHandle, true);
//	damageHandle = LoadGraph("playerdamage.png");

	gettotal = 1;//��

}

Collision::~Collision(){
	//�f�X�g���N�^
	Hitflag = false;
	Deadflag = false;
	Killflag = false;
	Animationchange = false;

	//���y�f�[�^����
	DeleteSoundMem(DeadSE);
	DeleteSoundMem(DeadBoss);
	DeleteSoundMem(HanabiA);
	DeleteSoundMem(HanabiB);
	DeleteSoundMem(HanabiC);

	int i;
	//vecter�̏ꍇ��DeleteGraph�͔z��Ȃ̂��Afor���ŏ����ł��Ȃ���
	for (i = 0; i < HanabiHandle.size(); ++i){
		DeleteGraph(HanabiHandle[i]);
	}
	for (i = 0; EnemyHandle.size(); ++i){
		DeleteGraph(EnemyHandle[i]);		
	}
	for (i = 0; FireHandle.size(); ++i){
		DeleteGraph(FireHandle[i]);
	}
	for (i = 0; BossHandle.size(); ++i){
		DeleteGraph(BossHandle[i]);
	}
	for (i = 0; PlayerHandle.size(); ++i){
		DeleteGraph(PlayerHandle[i]);
	}
//	for (i = 0; BombHandle[21]; ++i){
//		DeleteGraph(BombHandle[i]);
//	}
	//delete _class;//�|�C���^���i�[�����ϐ���delete���Ȃ��ƃ��������[�N!
}

void Collision::ClackSE(){
	//if ( (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy) )	{
	//	if (_EnemyHP <= 0 || _ShieldHP <= 0){
	//		PlaySoundMem(DeadSE, DX_PLAYTYPE_BACK);//SE�Đ�
	//	}
	//}
}

void Collision::ClackBoss(){
	//if((_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)){
	//	if (_BossHP <= 0){
	//		PlaySoundMem(DeadBoss, DX_PLAYTYPE_BACK);
	//	}
	//}
}

bool Collision::DeadEnemy(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy, int *_EnemyHP, int _weapon,int _weaponSt){//�t���O����
	bool localFlag = false;
	frame++;
//	++_k;
//	if (_k == 4)_k = 0;
	if (_EnemyHP >= 0){
		switch (_weapon){//weapon��enum�̕ϐ����i�[�ł��Ă���̂�
		case 0://�P��   == false && 
			if ((_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*Animationchange = true;
					if ((_EnemyHP <= 0) && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0)
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					if (isFlash && frame > 20)
					isDead = true;
					}*/
					localFlag = true;
				}
			}
			
			//��������
			if (_weaponSt == 3 && (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)/*�����蔻��͈̔͂ɓG������Ȃ�*/){//���邩������Ȃ��S�Ă̓G�ɑ΂��Ă����蔻����Ƃ邵���Ȃ� by666
				if (Killflag == true){
					*_EnemyHP -= 20;
					/*if ((_EnemyHP <= 0) && !isFlash){
						frame = 0;
						isFlash = true;
					}
					if (!isDead){
						if (!isFlash || frame % 3 == 0)
							DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
						if (isFlash && frame > 20)
							isDead = true;
					}*/
				}
				Animationchange = false; 
				localFlag = true;
			}
			break;
		case 1://�A��
			if (/*Animationchange == false && */(_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*if (_EnemyHP <= 0  && !isFlash){
						frame = 0;
						isFlash = true;
					}
					if (!isDead){
						if (!isFlash || frame % 3 == 0)
							DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
						if (isFlash && frame > 20)
							isDead = true;
					}*/
				}
				localFlag = true;
			}
			//��������
			if (/*Animationchange == true && */(_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 10;
					/*Animationchange = true;
					if (_EnemyHP <= 0  && !isFlash){
						frame = 0;
						isFlash = true;
					}
					if (!isDead){
						if (!isFlash || frame % 3 == 0){
							DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
							//boss�p���K�v���H							DrawGraph(_)
						}
						if (isFlash && frame > 20)
							isDead = true;
					}*/
				}
				Animationchange = false;
				localFlag = true;
			}
			break;
		case 2://����
			if ((_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 13) - _Enemyy)*((_Shoty - 13) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 13) - _Enemyy)*((_Shoty - 13) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 39) - _Enemyy)*((_Shoty - 39) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 65) - _Enemyy)*((_Shoty - 65) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 91) - _Enemyy)*((_Shoty - 91) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 117) - _Enemyy)*((_Shoty - 117) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 143) - _Enemyy)*((_Shoty - 143) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 169) - _Enemyy)*((_Shoty - 169) - _Enemyy)
				|| (_Shotr + _Enemyr) * (_Shotr + _Enemyr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 195) - _Enemyy)*((_Shoty - 195) - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*if (_EnemyHP <= 0 && !isFlash){
						frame = 0;
						isFlash = true;
					}
					if (!isDead){
						if (!isFlash || frame % 3 == 0)
							DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
						if (isFlash && frame > 20)
							isDead = true;
					}*/
					//if (/*Player.cpp����_weapon_[i].sf_p�������ė�����*/  == false/*��莞�Ԍo���ĕ������I��������A�`�悪�I�������*/){
					//	Killflag = false;
					//}
				}
				localFlag = true;
			}
			break;
		}
	}
	return localFlag;
}

bool Collision::DeadBosses(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy, int *_EnemyHP, int _weapon, int _weaponSt){
	bool localFlag = false;
	frame++;
	//	++_k;
	//	if (_k == 4)_k = 0;
	if (_EnemyHP >= 0){
		switch (_weapon){//weapon��enum�̕ϐ����i�[�ł��Ă���̂�
		case 0://�P��   == false && 
			if (((_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 85))*(_Shotx - (_Enemyx - 85)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 55))*(_Shotx - (_Enemyx - 55)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 25))*(_Shotx - (_Enemyx - 25)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 75))*(_Shotx - (_Enemyx + 85)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 45))*(_Shotx - (_Enemyx + 55)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 15))*(_Shotx - (_Enemyx + 25)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25)))){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*Animationchange = true;
					if ((_EnemyHP <= 0) && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0)
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					if (isFlash && frame > 20)
					isDead = true;
					}*/
					localFlag = true;
				}
			}

			//��������
			if (_weaponSt == 3 && (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)/*�����蔻��͈̔͂ɓG������Ȃ�*/){//���邩������Ȃ��S�Ă̓G�ɑ΂��Ă����蔻����Ƃ邵���Ȃ� by666
				if (Killflag == true){
					*_EnemyHP -= 20;
					/*if ((_EnemyHP <= 0) && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0)
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					if (isFlash && frame > 20)
					isDead = true;
					}*/
				}
				Animationchange = false;
				localFlag = true;
			}
			break;
		case 1://�A��
			if (/*Animationchange == false && */((_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 85))*(_Shotx - (_Enemyx - 85)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 55))*(_Shotx - (_Enemyx - 55)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx - 25))*(_Shotx - (_Enemyx - 25)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 75))*(_Shotx - (_Enemyx + 85)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 45))*(_Shotx - (_Enemyx + 55)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25))) ||
				((_Shotr + _Bossr / 2) * (_Shotr + _Bossr / 2) >= (_Shotx - (_Enemyx + 15))*(_Shotx - (_Enemyx + 25)) + (_Shoty - (_Enemyy + 25))*(_Shoty - (_Enemyy + 25)))){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*if (_EnemyHP <= 0  && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0)
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					if (isFlash && frame > 20)
					isDead = true;
					}*/
				}
				localFlag = true;
			}
			//��������
			if (/*Animationchange == true && */(_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + (_Shoty - _Enemyy)*(_Shoty - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 10;
					/*Animationchange = true;
					if (_EnemyHP <= 0  && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0){
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					//boss�p���K�v���H							DrawGraph(_)
					}
					if (isFlash && frame > 20)
					isDead = true;
					}*/
				}
				Animationchange = false;
				localFlag = true;
			}
			break;
		case 2://����
			if ((_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 13) - _Enemyy)*((_Shoty - 13) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 13) - _Enemyy)*((_Shoty - 13) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 39) - _Enemyy)*((_Shoty - 39) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 65) - _Enemyy)*((_Shoty - 65) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 91) - _Enemyy)*((_Shoty - 91) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 117) - _Enemyy)*((_Shoty - 117) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 143) - _Enemyy)*((_Shoty - 143) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 169) - _Enemyy)*((_Shoty - 169) - _Enemyy)
				|| (_Shotr + _Bossr) * (_Shotr + _Bossr) >= (_Shotx - _Enemyx)*(_Shotx - _Enemyx) + ((_Shoty - 195) - _Enemyy)*((_Shoty - 195) - _Enemyy)){
				if (Killflag == true){
					*_EnemyHP -= 30;
					/*if (_EnemyHP <= 0 && !isFlash){
					frame = 0;
					isFlash = true;
					}
					if (!isDead){
					if (!isFlash || frame % 3 == 0)
					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
					if (isFlash && frame > 20)
					isDead = true;
					}*/
					//if (/*Player.cpp����_weapon_[i].sf_p�������ė�����*/  == false/*��莞�Ԍo���ĕ������I��������A�`�悪�I�������*/){
					//	Killflag = false;
					//}
				}
				localFlag = true;
			}
			break;
		}
	}
	return localFlag;

}

//void Collision::KillEnemy(){	//�s�K�v?
////	Collision * _class = new EnemyBase();
//	//if (gettotal <= 0/*1�E�F�[�u�̓G���S�ł�����*/){
//	//	//���̃E�F�[�u�N���X�Acpp�Ăяo��
//	//	StageManager();
//	//}
//}

bool Collision::PlayerDamageFromEnemy(double _playerX, double _playerY, double _enemyX, double _enemyY){//�A�x�x���� �G�{�̂Ƃ̐ڐG
	if ((_r + _Enemyr) * (_r + _Enemyr) >= (_playerX - _enemyX)*(_playerX - _enemyX) + (_playerY - _enemyY)*(_playerY - _enemyY) ){
		//DrawGraph(_x, _y, damageHandle, TRUE);
		PlaySoundFile("zikisibou.wav", DX_PLAYTYPE_BACK);//���@�_���[�WSE���o�b�N�O���E���h�Đ�
		return true;
	}
	return false;
}

bool Collision::PlayerDamageFromBullet(double _playerX, double _playerY, double _eShotX, double _eShotY){
	if ((_r + _EnemyShotr) * (_r + _EnemyShotr) >= (_playerX - _eShotX)*(_playerX - _eShotX) + (_playerY - _eShotY)*(_playerY - _eShotY)){
		return true;
	}
	return false;
}

void Collision::DeadLine(){//�A�x�x����
//	Collision *_class = new GameOver();
	//if (_Enemyy >= 550){//1�̂ł��G�����B������B�u1�̂ł��v�Ƃ��������ɂȂ��Ă���̂��ǂ����s��
	//	//�Q�[���I�[�o�[�N���X�Ăяo��
	//	GameOver();
	//}
	//else{}
}

//void Collision::ClackHanabi(){//�n������
//	if (_weapon_n == 0 || _weapon_n == 1){
//
//	}
//	else if (_weapon_n == 2){
//
//	}
//}
//
//void Collision::ClackHanabi2(){//�n������
//
//}

void Collision::Bomb(){
	//while (CheckHitKey(KEY_INPUT_X) == 1/*X�L�[���������*/){
	//	if (_Bomb > 0){
	//		Killflag = true;
	//		DrawGraph(0, 0, BombHandle[_i], true);
	//		_i++;
	//		if (_i == 21){
	//			_EnemyHP -= 100;
	//			_ShieldHP -= 100;
	//			_BossHP -= 100;
	//			if (_EnemyHP <= 0 || _ShieldHP <= 0 || _BossHP <= 0 && !isFlash){
	//				frame = 0;
	//				isFlash = true;
	//			}
	//			if (!isDead){
	//				if (!isFlash || frame % 3 == 0)
	//					DrawGraph(_Enemyx, _Enemyy, EnemyHandle[_k], true);
	//				if (isFlash && frame > 20)
	//					isDead = true;
	//			}
	//			--_Bomb;
	//		}
	//	}
	//	else if (_Bomb <= 0){
	//		Killflag = false;
	//		//error
	//	}
	//}
}

void Collision::CheckHit(){

}

void Collision::Update(){

}
