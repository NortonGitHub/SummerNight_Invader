#include "SinglyWeapon.h"


SinglyWeapon::SinglyWeapon()
{
	//	count = 0;

	_x = 500;
	_y = 600;

	SetTransColor(0, 255, 0);

	i = 0;
	j = 0;

	position = END;	//初期値がこれかな

	frame = 0;

	gra = 0.0;

	sf_s = false;

	LoadDivGraph("data\\graphics\\Singly_1.png", 20, 1, 20, 100, 100, _hgraph);
	LoadDivGraph("data\\graphics\\Player_Bullet2.png", 3, 1, 3, 25, 50, _graph);

	_icon = LoadGraph("data\\graphics\\icon_tanpatsu.png"); //アイコン絵読み込み

	//追加、音楽データ読み込み
	HanabiA = LoadSoundMem("data\\sound\\SE\\ヒュー1_6改.wav");
	HanabiB = LoadSoundMem("data\\sound\\SE\\バーン1_5改_2.wav");


}


//理想：PipeOfFire (花火発射の筒)から初期座標を設定したいなぁ
/*
SinglyWeapon::SinglyWeapon(double x, double y, double sizeX, double sizeY, std::string graph)
{

	//if (count >= 2)
	//	return;

	const int SinglyGraphicX = 50; //画像の大きさ変更によっては変える必要あり
	const int SinglyGraphicY = 50;

	frame = 0;

	_x = x;
	_y = y;
	_sizeX = sizeX;
	_sizeY = sizeY;

	//画像読み込み用パスの準備
	//パスは画像の名前に応じて後々変更する。
	std::string str = "./data/Graphic/Weapon/Singly/Singly.png";
	const char* tmp;

	tmp = str.c_str(); //c_str() ... String型からchar型に戻す時の関数

	int imageNum[256];

	_graphSizeX = SinglyGraphicX;
	_graphSizeY = SinglyGraphicY;

	//コマ数の保持
	_gNum = (_graphSizeX / _sizeX) * (_graphSizeY / _sizeY);

	//画像読み込み
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
	//追加、音のデータを消す
	DeleteSoundMem(HanabiA);
	DeleteSoundMem(HanabiB);
	DeleteGraph(_icon);
}

void SinglyWeapon::update(){
	if (sf_s == true)//打ち上げているときにのみ通す
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

		//追加分
		if (CheckSoundMem(HanabiA) == 0){//音が鳴ってない場合
			PlaySoundMem(HanabiA, DX_PLAYTYPE_BACK);//音を鳴らす
			
		}
		++i;
		if (i == 2) i = 0;

		_y -= 28;
		gra += 0.835;
		_y += gra;

		if (_y <= 100){
			//if ((r + er) * (r + er) <= std::pow((x - ex) + (_y - ey), 2){
			//敵に直撃ダメージを与える
			position = EFFECT;
		}
	}

	if (position == EFFECT){
		//DeleteGraph(_graph[2]);

		//追加分
		StopSoundMem(HanabiA);//ヒューの音を止める
		if (CheckSoundMem(HanabiB) == 0){
			PlaySoundMem(HanabiB, DX_PLAYTYPE_BACK);//バーン鳴らす
		}
		++j;
		//if (j == 14)j = 0;
		//当たった敵すべてに爆風ダメージ1、アニメーションが続く限り継続で出す
		if (j == 14)position = END;
	}

	if (position == END){
		DeleteGraph(_hgraph[14]);
		//ここで変更した値を初期化する
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

	if (sf_s == true)//打ち上げているときにのみ通す
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

void SinglyWeapon::Gravitation(){	//2014/09/23現在使用せず


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