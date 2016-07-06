#include "ConfigureStage.h"


ConfigureStage::ConfigureStage()
{

	waveNum = 1;	//テストように値が変わっている恐れあり。注意！
	frame = 0;
	defeatedCount = 0;

	sceneChangeFlag = false;
	ToBossSceneFlag = false;
	ToBossSceneFlag2 = false;
	deadLineFlag = false;

    //ステージデータをロード
    DataList data_list_enemy(100);
    loader->load_pos_into_data(data_list_enemy, 1);

    enemys.reserve(255);

	bosses.reserve(1);
	bosses.push_back(new Boss01());

	followers.reserve(255);
	for (int i = 0; i < 5; i++){
		followers.push_back(new FollowerEnemy01());
	}

	explosionSound = LoadSoundMem("data\\sound\\SE\\BossD1.1.wav");	//爆発音の読み込み

    //読み込んだデータを使用
    for (Data& data : data_list_enemy){

		if (data.total <= 0)
			break;

        waveT = data.total; 
		waveTotal.push_back(data.total);
		//waveTotal[data.wave - 1] = data.total;
		
        if (data.zensyu > 1){
            waveT /= data.zensyu;
        }


		int cnt;

        for (int i = 0; i < 3; i++){	//1ウェーブ内の敵の種類(最大三種)
			cnt = 0;
			for (int j = 0; j < waveT; j++){ //(1種類の敵総登場数)
                switch (data.num[i]){
                case 1:
                    enemys.push_back(new LREnemy1(data.wave));
                    break;
               /* case 2:
                    enemys.push_back(new LREnemy2(data.wave));
                    break;*/
                case 3:
                    enemys.push_back(new LREnemy3(data.wave));
                    break;
                case 4:
                    enemys.push_back(new LREnemy4(data.wave));
                    break;
               /* case 5:
                    enemys.push_back(new LREnemy5(data.wave));
                    break;*/
				case 6:
					enemys.push_back(new LREnemy6(data.wave));
					break;
				case 7:
					enemys.push_back(new IrreEnemy1(data.wave));
					break;
				case 8:
					enemys.push_back(new LREnemy7(data.wave));
					break;
				case 9:
					enemys.push_back(new IrreEnemy2(data.wave,cnt));
					break;
				case 10:
					enemys.push_back(new LREnemy8(data.wave,cnt));
					break;
				case 11:
					enemys.push_back(new IrreEnemy3(data.wave, cnt));
					break;
				case 12:
					enemys.push_back(new IrreEnemy4(data.wave, cnt));
					break;
				case 13:
					enemys.push_back(new IrreEnemy5(data.wave, cnt));
					break;
				case 14:
					enemys.push_back(new SimpleEnemy1(data.wave, cnt));
					break;
				}
				cnt++;
            }
        }
    }
	waveTotal.push_back(0);	//敵総登場数が0になったとき、そのウェーブが最終ウェーブ(=ボスステージ)に到達したということを示す。
    delete loader;
	loader = nullptr;
}

ConfigureStage::ConfigureStage(int stagenum_cs)
{

	waveNum = 1;
	frame = 0;
	defeatedCount = 0;

	sceneChangeFlag = false;
	ToBossSceneFlag = false;
	ToBossSceneFlag2 = false;
	deadLineFlag = false;

	//ステージデータをロード
	DataList data_list_enemy(100);
	loader->load_pos_into_data(data_list_enemy,stagenum_cs);

	enemys.reserve(255);

	bosses.reserve(1);
	bosses.push_back(new Boss01());

	followers.reserve(6);
	for (int i = 0; i < 5; i++){
		followers.push_back(new FollowerEnemy01());
	}

	//読み込んだデータを使用
	for (const Data& data : data_list_enemy){

		waveT = data.total;
		//waveTotal[data.wave - 1] = data.total;
		waveTotal.push_back(data.total);

		if (data.zensyu > 1){
			waveT /= data.zensyu;
		}
		
		int cnt;

		for (int i = 0; i < 3; i++){
			cnt = 0;
			for (int j = 0; j < waveT; j++){
				switch (data.num[i]){
				case 1:
					enemys.push_back(new LREnemy1(data.wave));
					break;
				/*case 2:
					enemys.push_back(new LREnemy2(data.wave));
					break;*/
				case 3:
					enemys.push_back(new LREnemy3(data.wave));
					break;
				case 4:
					enemys.push_back(new LREnemy4(data.wave));
					break;
				/*case 5:
					enemys.push_back(new LREnemy5(data.wave));
					break;*/
				case 6:
					enemys.push_back(new LREnemy6(data.wave));
					break;
				case 7:
					enemys.push_back(new IrreEnemy1(data.wave));
					break;
				case 8:
					enemys.push_back(new LREnemy7(data.wave));
					break;
				case 9:
					enemys.push_back(new IrreEnemy2(data.wave,cnt));
					break;
				case 10:
					enemys.push_back(new LREnemy8(data.wave,cnt));
					break;
				case 11:
					enemys.push_back(new IrreEnemy3(data.wave, cnt));
					break;
				case 12:
					enemys.push_back(new IrreEnemy4(data.wave, cnt));
					break;
				case 13:
					enemys.push_back(new IrreEnemy5(data.wave, cnt));
					break;
				case 14:
					enemys.push_back(new SimpleEnemy1(data.wave, cnt));
					break;
				}
				cnt++;
			}
		}
	}
	waveTotal.push_back(0);	//敵総登場数が0になったとき、そのウェーブが最終ウェーブ(=ボスステージ)に到達したということを示す。
	delete loader;
	loader = nullptr;

}

ConfigureStage::~ConfigureStage()
{
	DeleteSoundMem(explosionSound);
	for (int i = 0; i < enemys.size(); i++){
		enemys.erase(enemys.begin() + i);
	}
	for (int i = 0; i < followers.size(); i++){
		followers.erase(followers.begin() + i);
	}
}

void ConfigureStage::update(double _pX, double _pY, double _sX, double _sY, int _weaponNum,
	int *_weaponSt, bool *_wasAttacked, int *stagenum_cs){
	//敵のアップデート
	++frame;
	if (waveTotal[waveNum-1] != 0){
		updateForEnemys(_pX, _pY, _sX, _sY, _weaponNum, _weaponSt, _wasAttacked);
	}
	else if(bosses[0] != nullptr && ToBossSceneFlag == true){
		updateForBosses(_pX, _pY, _sX, _sY, _weaponNum, _weaponSt, _wasAttacked,stagenum_cs);
		updateForFollowers(_pX, _pY, _sX, _sY, _weaponNum, _weaponSt, _wasAttacked);
	}
	else if (frame - untilSceneChange >= 180){	//180フレーム後にシーンチェンジ
		int tmp = *stagenum_cs + 1;
		*stagenum_cs = tmp;
	}
	
	if (frame >= 60000)	//試しに入れてみた
		frame = 0;

}

void ConfigureStage::updateForEnemys(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked){
	for (size_t i = 0; i < enemys.size(); i++){
		if (enemys[i] != nullptr){
			if (waveNum == enemys[i]->returnWavenum())
			{
				enemys[i]->update();
				if (enemys[i]->returnBulletFlag() == true){
					//eBM.update((int)enemys[i]->returnX(),(int)enemys[i]->returnY());
					//弾を撃つ条件
					if (frame % 60 == 0 ){	//敵が弾を撃つタイミングをずらす試みをしてみたい
						e_Bullet.push_back(new EnemiesBullet(enemys[i]->returnX() - 10, enemys[i]->returnY() + 30));
					}
				}
				_eX = enemys[i]->returnX();
				_eY = enemys[i]->returnY();
				_eHP = enemys[i]->getEnemyHP();
				if (c.DeadEnemy((int)_sX, (int)_sY, _eX, _eY, &_eHP, _weaponNum, *_weaponSt)/* && !enemys[i]->getHasFlashed()*/){	//敵と自機弾の判定
					enemys[i]->setEnemyHP(_eHP);	//敵HPを返す
					if (_weaponNum != 2)
						*_weaponSt = 3;
					if (_eHP <= 0){
						enemys[i]->setExplosionFlag(1);	//敵の爆発を開始
					}
					else{
						enemys[i]->setFlashFlag(true);	//画像点滅フラグをtrueに
					}
				}
				if (enemys[i]->getExplosionFlag() == 2){	//敵を完全に消し去る処理(爆発し終えた).
					enemys.erase(enemys.begin() + i);
					//delete(enemys[i]);
					//enemys[i] = nullptr;
					++defeatedCount;
				}

				//デッドライン判定ここに加える予定
				if (_eY > 550){
					deadLineFlag = true;
				}

				if (c.PlayerDamageFromEnemy(_pX, _pY, _eX, _eY)){ //敵と接触したときの判定
					*_wasAttacked = true;
				}
			}
		}
	}
	//Bullet~呼び出し
	for (size_t j = 0; j < e_Bullet.size(); ++j){
		if (e_Bullet[j] != nullptr){ //弾が消えていないことを確認
			e_Bullet[j]->Update(); //弾のUpdate関数を呼び出す
			if (e_Bullet[j]->getY() > 550){
				e_Bullet.erase(e_Bullet.begin() + j);
			//	delete(e_Bullet[j]); //弾を消す
			//	e_Bullet[j] = nullptr; //消えた事を示す
			}
			else{
				double _eBulletX = (double)(e_Bullet[j]->getX());
				double _eBulletY = (double)(e_Bullet[j]->getY());
				if (c.PlayerDamageFromBullet(_pX, _pY, _eBulletX, _eBulletY)){ //敵弾と接触したときの判定
					*_wasAttacked = true;
					e_Bullet.erase(e_Bullet.begin() + j);
				}
			}
		}
	}

	if (defeatedCount >= waveTotal[waveNum - 1]){
		if (waveTotal[waveNum] == 0){	//移行先のウェーブがボスである時
			if (frame < 200)
				ToBossSceneFrame = 1;
			else
				ToBossSceneFrame = frame;
			ToBossSceneFlag2 = true;
		}
		else{
			waveNum++;
		}
		defeatedCount = 0;
	}

	if (frame - ToBossSceneFrame >= 200 && ToBossSceneFlag2 == true){
		waveNum++;
		ToBossSceneFlag = true;
		ToBossSceneFlag2 = false;
	}
	
}

void ConfigureStage::updateForBosses(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked, int *stagenum_cs){
	bosses[0]->update();

	_bX = bosses[0]->getX();
	_bY = bosses[0]->getY();
	_bHP = bosses[0]->getHP();


	/*if (c.DeadEnemy((int)_sX,(int)_sY,_bX,_bY,&_bHP,_weaponNum,*_weaponSt)){
		if (_weaponNum != 2)
			*_weaponSt = 3;

	}
	bosses[0]->setBossHP(_bHP);*/

	if (c.DeadBosses((int)_sX, (int)_sY, _bX, _bY, &_bHP, _weaponNum, *_weaponSt)){
		bosses[0]->setHP(_bHP);
		if (_weaponNum != 2){
			*_weaponSt = 3;
		}

		//ボスの体力が0以下になった時
		if (_bHP <= 0 && bosses[0]->getExplosionFlag() == 0){
			PlaySoundMem(explosionSound, DX_PLAYTYPE_BACK);
			bosses[0]->setExplosionFlag(1);	//敵の爆発を開始
			for (int i = 0; i < followers.size(); i++){
				followers[i] = nullptr;
			}
			for (int i = 0; i < b_Bullet.size(); i++){
				b_Bullet[i] = nullptr;
			}
		}
		else{
			bosses[0]->setFlashFlag(true);	//画像点滅フラグをtrueに
		}
	}

	//敵を完全に消し去る処理(爆発し終えた).
	if (bosses[0]->getExplosionFlag() == 2){
		if (!sceneChangeFlag){
			if (frame < 180)
				untilSceneChange = 0;
			else
				untilSceneChange = frame;
			sceneChangeFlag = true;
			bosses[0] = nullptr;
		}
	}

	if (_bY > 550){
		deadLineFlag = true;
	}


	//b_Bullet~呼び出し
	if (bosses[0] != nullptr){

		if (frame % 120 == 0 && bosses[0]->getExplosionFlag() == 0){	//120フレームごとにボスが弾を発射する
			for (int i = 0; i < 3; i++){
				b_Bullet.push_back(new BossBullet(_bX, _bY,i));
			}
		}

		for (size_t j = 0; j < b_Bullet.size(); ++j){
			if (b_Bullet[j] != nullptr || bosses[0]->getExplosionFlag() == 0){ //弾が消えていないことを確認 ＆ 爆発フラグが立っていないことを確認する
				b_Bullet[j]->update(); //弾のUpdate関数を呼び出す
				if (b_Bullet[j]->getY() > 550){
					b_Bullet.erase(b_Bullet.begin() + j);
				}
				else{
					double _bBulletX = (double)(b_Bullet[j]->getX());
					double _bBulletY = (double)(b_Bullet[j]->getY());
					if (c.PlayerDamageFromBullet(_pX, _pY, _bBulletX, _bBulletY)){ //敵弾と接触したときの判定
						*_wasAttacked = true;
						b_Bullet.erase(b_Bullet.begin() + j);
					}
				}
			}
		}
	}
}

void ConfigureStage::updateForFollowers(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked){
	for (size_t i = 0; i < followers.size(); i++){
		if (followers[i] != nullptr){
			followers[i]->setBossCoord(_bX, _bY);
			followers[i]->update();

			double _fX = followers[i]->getX();
			double _fY = followers[i]->getY();
			int _fHP = followers[i]->getHP();

			if (c.DeadEnemy((int)_sX, (int)_sY, _fX, _fY, &_fHP, _weaponNum, *_weaponSt)/* && !enemys[i]->getHasFlashed()*/){	//敵と自機弾の判定
				followers[i]->setHP(_fHP);	//敵HPを返す
				if (_weaponNum != 2)
					*_weaponSt = 3;
				if (_fHP <= 0){
					followers[i]->setExplosionFlag(1);	//敵の爆発を開始
				}
				else{
					followers[i]->setFlashFlag(true);	//画像点滅フラグをtrueに
				}
			}
			if (followers[i]->getExplosionFlag() == 2){	//敵を完全に消し去る処理(爆発し終えた).
				followers.erase(followers.begin() + i);
			}
		}
	}
}

void ConfigureStage::draw(){
	if (waveTotal[waveNum-1] != 0){
		drawForEnemys();
	}
	else if (bosses[0] != nullptr){
		drawForBosses();
		drawForFollowers();
	}
	
}

void ConfigureStage::drawForEnemys(){
	for (size_t i = 0; i < e_Bullet.size(); ++i){
		if (e_Bullet[i] != nullptr){ //弾が消えてないことを確認
			e_Bullet[i]->Draw();
		}
	}

	for (size_t i = 0; i < enemys.size(); i++){
		if (enemys[i] != nullptr){
			if (waveNum == enemys[i]->returnWavenum())	{
				/*if (enemys[i]->returnBulletFlag() == true){
					eBM.draw();
					}*/
				enemys[i]->draw();
				//DrawFormatString(enemys[i]->returnX(), enemys[i]->returnY(), GetColor(255, 0, 0), "%d", enemys[i]->getExplosionFlag());
			}
		}
	}

	//敵弾のX座標呼び出し
	for (size_t j = 0; j < e_Bullet.size(); ++j){
	//	DrawFormatString(380, j * 15, GetColor(0xFF, 0xFF, 0xFF), "Y : %d", e_Bullet[j]->getY());
	}

	//DrawFormatString(300, 0, GetColor(255, 255, 0), "defeated:%d", defeatedCount);
	//switch (forCs){
	//case 0:			//Singly
	//	singly.draw();
	//	break;
	//case 1:			//Quick
	//	quick.draw();
	//	break;
	//case 2:			//Jet
	//	jet.draw();
	//	break;
	//}
}

void ConfigureStage::drawForBosses(){
	bosses[0]->draw();
	
//	DrawFormatString(0, 100, GetColor(0xFF, 0xFF, 0xFA), "BOSS HP : %d \n FRAME : %d", _bHP, frame);	//FOR TEST
	for (size_t i = 0; i < b_Bullet.size(); ++i){
		if (b_Bullet[i] != nullptr){ //弾が消えてないことを確認
			b_Bullet[i]->draw();
		}
	}
}

void ConfigureStage::drawForFollowers(){
	for (size_t i = 0; i < followers.size(); i++){
		if (followers[i] != nullptr)
			followers[i]->draw();
	}
}

int ConfigureStage::getWaveNumNow(){
	return waveNum;
}

bool ConfigureStage::getDeadLine(){
	return deadLineFlag;
}

/*void ConfigureStage::deliverSubstance(int type){
	weaponTypeNum = type;
}*/

