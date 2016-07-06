#include "JetWeapon.h"


JetWeapon::JetWeapon()
{
	//座標
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

	_icon = LoadGraph("data\\graphics\\icon_funsui.png"); //アイコン絵読み込み

	//追加、音読み込み
	Hanabi = LoadSoundMem("data\\sound\\SE\\Hanabi3.wav");

	sf_j = false;
}

//理想：PipeOfFire (花火発射の筒)から初期座標を設定したいなぁ
/*
JetWeapon::JetWeapon(double x, double y, double sizeX, double sizeY, std::string graph)
{

	if (count >= 2)
		return;

	const int jetGraphicX = 50; //画像の大きさ変更によっては変える必要あり
	const int jetGraphicY = 50;

	frame = 0;

	_x = x;
	_y = y;
	_sizeX = sizeX;
	_sizeY = sizeY;

	//画像読み込み用パスの準備
	//パスは画像の名前に応じて後々変更する。
	std::string str = "./data/Graphic/Weapon/Jet/jet.png";
	const char* tmp;

	tmp = str.c_str(); //c_str() ... String型からchar型に戻す時の関数

	int imageNum[256];

	_graphSizeX = jetGraphicX; 
	_graphSizeY = jetGraphicY;

	//コマ数の保持
	_gNum = (_graphSizeX / _sizeX) * (_graphSizeY / _sizeY);

	//画像読み込み
	LoadDivGraph(tmp, _gNum, (_graphSizeX / _sizeX), (_graphSizeY / _sizeY),
		static_cast<int>(sizeX), static_cast<int>(sizeY), _graph);

}*/
/*
JetWeapon::JetWeapon(double x, double y){
	_x = x;
	_y = y;
}*/

JetWeapon::~JetWeapon() //要らなくなったらポイする
{
	for (int i = 0; i < 9; i++)
		DeleteGraph(_graph[i]);

	DeleteGraph(_icon);
	//追加
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

		//追加、音鳴らす
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
		//追加、音止める
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