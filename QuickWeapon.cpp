#include "QuickWeapon.h"


QuickWeapon::QuickWeapon()
{
	_x = 500;
	_y = 600;

	frame = 0;

	count = 0;

	position = END;

	i = 0;
	j = 0;

	sf_q = false;

	LoadDivGraph("data\\graphics\\Quick_Yellow.png", 10, 1, 10, 50, 50, _hgraph);
	LoadDivGraph("data\\graphics\\Player_Bullet2.png",3,1,3,25,50,_graph);

	_iconQ = LoadGraph("data\\graphics\\icon_renpatsu.png");

	//�ǉ��A���f�[�^�ǂݍ���
	HanabiA = LoadSoundMem("data\\sound\\SE\\�q���[1_6��.wav");
	HanabiB = LoadSoundMem("data\\sound\\SE\\�o�[��1_5��_2.wav");

}

//���z�FPipeOfFire (�ԉΔ��˂̓�)���珉�����W��ݒ肵�����Ȃ�
/*
QuickWeapon::QuickWeapon(double x, double y, double sizeX, double sizeY, std::string graph)
{

	//if (count >= 2)
	//	return;

	const int SinglyGraphicX = 50; //�摜�̑傫���ύX�ɂ���Ă͕ς���K�v����
	const int SinglyGraphicY = 50;

	frame = 0;

	_x = x;
	_y = y;
	_sizeX = sizeX;
	_sizeY = sizeY;

	//�摜�ǂݍ��ݗp�p�X�̏���
	//�p�X�͉摜�̖��O�ɉ����Č�X�ύX����B
	std::string str = "./data/Graphic/Weapon/Singly/Singly.png";
	const char* tmp;

	tmp = str.c_str(); //c_str() ... String�^����char�^�ɖ߂����̊֐�

	int imageNum[256];

	_graphSizeX = SinglyGraphicX;
	_graphSizeY = SinglyGraphicY;

	//�R�}���̕ێ�
	_gNum = (_graphSizeX / _sizeX) * (_graphSizeY / _sizeY);

	//�摜�ǂݍ���
	LoadDivGraph(tmp, _gNum, (_graphSizeX / _sizeX), (_graphSizeY / _sizeY),
		static_cast<int>(sizeX), static_cast<int>(sizeY), _graph);

}*/
/*
QuickWeapon::QuickWeapon(double x, double y){
	_x = x;
	_y = y;
}*/

QuickWeapon::~QuickWeapon()
{

	for (int i = 0; i < 10; i++)
		DeleteGraph(_hgraph[i]);
	for (int i = 0; i < 9; i++)
		DeleteGraph(_graph[i]);

	//�ǉ��A
	DeleteSoundMem(HanabiA);
	DeleteSoundMem(HanabiB);

	DeleteGraph(_iconQ);
}

void QuickWeapon::update(){
	if (sf_q == true)
		in_update();
}

void QuickWeapon::in_update(){
	if (position == STOP){

	//	StopSoundMem(HanabiB);

		if (count < 1){
			time = GetNowCount();
			position = STOP_1;
			
		}

		else if (count >= 1){
			time = GetNowCount();
			position = STOP_1;
		}

	}

	else if (position == STOP_1){
		if (count < 1){
			if (GetNowCount() - time > 1500)
				position = SHOT;
		}
		else if (count >= 1){
			if (GetNowCount() - time > 20)
				position = SHOT;
		}
	}

	else if (position == SHOT){

		//�ǉ��A���炷
		if (CheckSoundMem(HanabiA) == 0){//�������ĂȂ��ꍇ
			PlaySoundMem(HanabiA, DX_PLAYTYPE_BACK);//����炷

		}

		++i;
		if (i == 2) i = 0;

		_y -= 30;

		if (_y <= 100){
			position = EFFECT;

		}

	}
	else if (position == EFFECT){

		//�ǉ�
		StopSoundMem(HanabiA);//�q���[�̉����~�߂�
		if (j == 1){
			PlaySoundMem(HanabiB, DX_PLAYTYPE_BACK);//�o�[���炷
		}

		++j;
		if (i == 4)i = 0;

		//_y = 100;

		if (j == 14)
		{
			j = 0;
			_y = 540;
			position = STOP;

			count++;

			if (count == 3)
				position = END;
		}

	}


	if (position == END)
	{
		
		count = 0;

		i = 0;
		j = 0;
		_x = 800;
		_y = 600;
		sf_q = false;
	}
}

void QuickWeapon::draw(){
	//DrawFormatString(0, 80, GetColor(0xFF, 0x00, 0xFD), "sf_q = %d", sf_q);

	DrawGraph(400, 550, _iconQ, true);

	if (sf_q == true)
		in_draw();
}

void QuickWeapon::in_draw(){
	if (position == SHOT){
		// �O���t�B�b�N�̕`��(�wDrawGraph�x�g�p)
		DrawGraph((int)(_x - 12/*-10*/),(int) _y - 40, _graph[i], TRUE);
	}
	else if (position == EFFECT){

		//DeleteGraph(_graph[2]);
		if (j < 10){
			DrawGraph((int)(_x - 25), (int)(_y - 50), _hgraph[j], TRUE);
		}
	}

	else if (position == END){
	}
}

void QuickWeapon::preparation(int x,  bool flag,int weapon_num){
	if (weapon_num == 1){
		position = STOP;
		_x = x;
		_y = 540;
		sf_q = flag;
	}
}

void QuickWeapon::checkForPlayer(bool &weapon){
	if (sf_q == false){
		weapon = sf_q;
	}
}

void QuickWeapon::setWeaponStatus(int _status){
	if (_status == 3)
		position = EFFECT;
}

int QuickWeapon::getWeaponStatus(){
	return position;
}