#include "EnemiesBulletManager.h"


EnemiesBulletManager::EnemiesBulletManager()
{
	frame = 0;
	_x = 0;
	_y = 600;
//	b.push_back(new EnemiesBullet(_x + 16, _y + 64));
}


EnemiesBulletManager::~EnemiesBulletManager()
{
}

void EnemiesBulletManager::update(int x,int y){
	//frame++;


	////�e��������
	//if (frame % 60 == 0){
	//	_x = x;
	//	_y = y;
	//	b.push_back(new EnemiesBullet(_x + 8, _y/* + 64*/));
	//}

	////Bullet~�Ăяo��
	//for (size_t i = 0; i < b.size(); ++i){
	//	if (b[i] != nullptr){ //�e�������Ă��Ȃ����Ƃ��m�F
	//		b[i]->Update(_x + 8, _y /*+  64*/); //�e��Update�֐����Ăяo��

	//		if (b[i]->getY() > 550){
	//			delete(b[i]); //�e������
	//			b[i] = nullptr; //��������������
	//		}
	//	}
	//}

}

void EnemiesBulletManager::draw(){
	//for (size_t i = 0; i < b.size(); ++i){
	//	if (b[i] != nullptr){ //�e�������ĂȂ����Ƃ��m�F
	//		b[i]->Draw();
	//	}
	//}
}
