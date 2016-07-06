#include "SinglyWeapon.h"


SinglyWeapon::SinglyWeapon()
{
	//	count = 0;

	_x = 500;
	_y = 600;

	SetTransColor(0, 255, 0);

	i = 0;
	j = 0;

	position = END;	//�����l�����ꂩ��

	frame = 0;

	gra = 0.0;

	sf_s = false;

	LoadDivGraph("data\\graphics\\Singly_1.png", 20, 1, 20, 100, 100, _hgraph);
	LoadDivGraph("data\\graphics\\Player_Bullet2.png", 3, 1, 3, 25, 50, _graph);

	_icon = LoadGraph("data\\graphics\\icon_tanpatsu.png"); //�A�C�R���G�ǂݍ���

	//�ǉ��A���y�f�[�^�ǂݍ���
	HanabiA = LoadSoundMem("data\\sound\\SE\\�q���[1_6��.wav");
	HanabiB = LoadSoundMem("data\\sound\\SE\\�o�[��1_5��_2.wav");


}


//���z�FPipeOfFire (�ԉΔ��˂̓�)���珉�����W��ݒ肵�����Ȃ�
/*
SinglyWeapon::SinglyWeapon(double x, double y, double sizeX, double sizeY, std::string graph)
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
SinglyWeapon::SinglyWeapon(double x, double y,bool &weapon){
	_x = x;
	_y = y;
	weapon = true;
	sf_s = weapon;
}*/

SinglyWeapon::~SinglyWeapon()
{
	for (int i = 0; i < 14; i++)
		DeleteGraph(_hgraph[i]);
	for (int i = 0; i < 9; i++)
		DeleteGraph(_graph[i]);
	//�ǉ��A���̃f�[�^������
	DeleteSoundMem(HanabiA);
	DeleteSoundMem(HanabiB);
	DeleteGraph(_icon);
}

void SinglyWeapon::update(){
	if (sf_s == true)//�ł��グ�Ă���Ƃ��ɂ̂ݒʂ�
		in_update();
}

void SinglyWeapon::in_update(){
/*	++i;
	if (i == 2) i = 0;

	_y -= 5;*/

	if (position == STOP){
		//DrawGraph(x, _y, GrHandle, TRUE);

		_time = GetNowCount();

		position = STOP_1;

	}

	if (position == STOP_1){
		if (GetNowCount() - _time > 1500){
			position = SHOT;
		}
	}

	if (position == SHOT){

		//�ǉ���
		if (CheckSoundMem(HanabiA) == 0){//�������ĂȂ��ꍇ
			PlaySoundMem(HanabiA, DX_PLAYTYPE_BACK);//����炷
			
		}
		++i;
		if (i == 2) i = 0;

		_y -= 28;
		gra += 0.835;
		_y += gra;

		if (_y <= 100){
			//if ((r + er) * (r + er) <= std::pow((x - ex) + (_y - ey), 2){
			//�G�ɒ����_���[�W��^����
			position = EFFECT;
		}
	}

	if (position == EFFECT){
		//DeleteGraph(_graph[2]);

		//�ǉ���
		StopSoundMem(HanabiA);//�q���[�̉����~�߂�
		if (CheckSoundMem(HanabiB) == 0){
			PlaySoundMem(HanabiB, DX_PLAYTYPE_BACK);//�o�[���炷
		}
		++j;
		//if (j == 14)j = 0;
		//���������G���ׂĂɔ����_���[�W1�A�A�j���[�V��������������p���ŏo��
		if (j == 14)position = END;
	}

	if (position == END){
		DeleteGraph(_hgraph[14]);
		//�����ŕύX�����l������������
		sf_s = false;
		i = 0;
		gra = 0.0;
		j = 0;
		_x = 800;
		_y = 600;
	}
}

void SinglyWeapon::draw(){
	//DrawFormatString(0,80,GetColor(0xFF,0x00,0xFD),"sf_s = %d",sf_s);

	DrawGraph(400, 550, _icon, true);

	if (sf_s == true)//�ł��グ�Ă���Ƃ��ɂ̂ݒʂ�
		in_draw();
}

void SinglyWeapon::in_draw(){

	if (position == SHOT)
		DrawGraph(((int)_x - 12/* - 10*/), ((int)_y - 40/*- 50*/), _graph[i], TRUE);

	else if (position == EFFECT)
		DrawGraph(((int)_x - 50), ((int)_y - 50 /* - 10*/), _hgraph[j], TRUE);

}

void SinglyWeapon::preparation(int x,bool flag,int weapon_num){
	if (weapon_num == 0){
		position = STOP;
		_x = x;
		_y = 550;
		sf_s = flag;
	}
}

void SinglyWeapon::Gravitation(){	//2014/09/23���ݎg�p����


	gra += 0.035;
	_y += gra;

}

void SinglyWeapon::checkForPlayer(bool &weapon){
	if (sf_s == false)
		weapon = sf_s;
}

void SinglyWeapon::setWeaponStatus(int _status){
	if (_status == 3)
		position = EFFECT;
}

int SinglyWeapon::getWeaponStatus(){
	return position;
}