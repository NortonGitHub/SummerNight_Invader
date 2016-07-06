#include "JetWeapon.h"


JetWeapon::JetWeapon()
{
	//���W
	_x = 600;
	_y = 500;

	count = 0;

	i = 0;
	j = 0;
	k = 0;

	frame = 0;
	position = END;
	placedTime = 0;
	elapsedTime = 0;

	//_gNum = 9;

//	_graph[0] = LoadGraph("data\\graphics\\Funsyutsu.png");
	LoadDivGraph("data\\graphics\\Jet_2.png", 9, 9, 1, 26, 200, _graph);

	_icon = LoadGraph("data\\graphics\\icon_funsui.png"); //�A�C�R���G�ǂݍ���

	//�ǉ��A���ǂݍ���
	Hanabi = LoadSoundMem("data\\sound\\SE\\Hanabi3.wav");

	sf_j = false;
}

//���z�FPipeOfFire (�ԉΔ��˂̓�)���珉�����W��ݒ肵�����Ȃ�
/*
JetWeapon::JetWeapon(double x, double y, double sizeX, double sizeY, std::string graph)
{

	if (count >= 2)
		return;

	const int jetGraphicX = 50; //�摜�̑傫���ύX�ɂ���Ă͕ς���K�v����
	const int jetGraphicY = 50;

	frame = 0;

	_x = x;
	_y = y;
	_sizeX = sizeX;
	_sizeY = sizeY;

	//�摜�ǂݍ��ݗp�p�X�̏���
	//�p�X�͉摜�̖��O�ɉ����Č�X�ύX����B
	std::string str = "./data/Graphic/Weapon/Jet/jet.png";
	const char* tmp;

	tmp = str.c_str(); //c_str() ... String�^����char�^�ɖ߂����̊֐�

	int imageNum[256];

	_graphSizeX = jetGraphicX; 
	_graphSizeY = jetGraphicY;

	//�R�}���̕ێ�
	_gNum = (_graphSizeX / _sizeX) * (_graphSizeY / _sizeY);

	//�摜�ǂݍ���
	LoadDivGraph(tmp, _gNum, (_graphSizeX / _sizeX), (_graphSizeY / _sizeY),
		static_cast<int>(sizeX), static_cast<int>(sizeY), _graph);

}*/
/*
JetWeapon::JetWeapon(double x, double y){
	_x = x;
	_y = y;
}*/

JetWeapon::~JetWeapon() //�v��Ȃ��Ȃ�����|�C����
{
	for (int i = 0; i < 9; i++)
		DeleteGraph(_graph[i]);

	DeleteGraph(_icon);
	//�ǉ�
	DeleteSoundMem(Hanabi);
}

void JetWeapon::update(){
	if (sf_j == true)
		in_update();
}

void JetWeapon::in_update(){
	if (position == STOP){
		placedTime = GetNowCount();
		position = STOP_1;
	}

	else if (position == STOP_1){
		if (GetNowCount() - placedTime > 1000){
			position = SHOT;
		}
	}

	else if (position == SHOT){

		//�ǉ��A���炷
		if (CheckSoundMem(Hanabi) == 0){
			PlaySoundMem(Hanabi, DX_PLAYTYPE_BACK);
		}

		++i;
		++k;

		if (i == 2){
			i = 0;
			++j;
		}

		if (j == 30){
			elapsedTime = GetNowCount();

		}
		if (GetNowCount() - elapsedTime > 1500 && j >= 30){
			position = END;
		}
	}

	if (position == END)
	{
		sf_j = false;
		count = 0;
		k = 0;
		i = 0;
		j = 0;
		_x = 800;
		_y = 600;
		//�ǉ��A���~�߂�
		StopSoundMem(Hanabi);

	}
}

void JetWeapon::draw(){
	//DrawFormatString(0, 80, GetColor(0xFF, 0x00, 0xFD), "sf_j = %d", sf_j);
	DrawGraph(400, 550, _icon, true);

	if (sf_j == true)
		in_draw();
}

void JetWeapon::in_draw(){
	if (position == STOP){

	}
	else if (position == SHOT){
		DrawGraph(((int)_x - 12), ((int)_y - 200), _graph[k % 9], TRUE);
	}
	else if (position == END){

	}
}

void JetWeapon::preparation(int x,  bool flag,int weapon_num){
	if (weapon_num == 2){
		position = STOP;
		_x = x;
		_y = 540;
		sf_j = flag;
	}
}

void JetWeapon::checkForPlayer(bool &weapon){
	if (sf_j == false){
		weapon = sf_j;
	}
}


void JetWeapon::setWeaponStatus(int _status){
	//if (_status == 3)
	//	position = EFFECT;
}

int JetWeapon::getWeaponStatus(){
	return position;
}