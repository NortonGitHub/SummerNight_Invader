#include "PipeOfWeapon.h"


PipeOfWeapon::PipeOfWeapon()
{
	sf = false;
	frame = 0;
	_x = 0;
	handle = LoadGraph("data\\graphics\\tutu1.png");
}

PipeOfWeapon::PipeOfWeapon(int x, bool flag)
{
}//���̎��_�ł�sf��true�ƂȂ��Ă���

PipeOfWeapon::~PipeOfWeapon()
{
	DeleteGraph(handle);
}

void PipeOfWeapon::update()
{
	//frame++;
	/*�`�F�b�N�p*/
}

void PipeOfWeapon::draw()
{
	if (sf == true){
		DrawGraph(_x, _y, handle, true);
	}
}

//�ꉞ�ۗ�
void PipeOfWeapon::preparation(int x, bool flag,int weapon_num)
{
	_x = x - 3;
	_y = 530;
	sf = flag;
}

void PipeOfWeapon::checkForPlayer(bool weapon){
	if (weapon == false)
		sf = weapon;
};