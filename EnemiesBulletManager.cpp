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


	////弾を撃つ条件
	//if (frame % 60 == 0){
	//	_x = x;
	//	_y = y;
	//	b.push_back(new EnemiesBullet(_x + 8, _y/* + 64*/));
	//}

	////Bullet~呼び出し
	//for (size_t i = 0; i < b.size(); ++i){
	//	if (b[i] != nullptr){ //弾が消えていないことを確認
	//		b[i]->Update(_x + 8, _y /*+  64*/); //弾のUpdate関数を呼び出す

	//		if (b[i]->getY() > 550){
	//			delete(b[i]); //弾を消す
	//			b[i] = nullptr; //消えた事を示す
	//		}
	//	}
	//}

}

void EnemiesBulletManager::draw(){
	//for (size_t i = 0; i < b.size(); ++i){
	//	if (b[i] != nullptr){ //弾が消えてないことを確認
	//		b[i]->Draw();
	//	}
	//}
}
