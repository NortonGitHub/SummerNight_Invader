#include "FpsController.h"
//char型やint型の最大値や最小値が定義されている、マグロもといマクロ。
#include <limits>


FpsController::FpsController()//※代入ではない
	: x(0), y(0)
	, color(GetColor(0, 0, 0))
	, startTime(-1)
	, beforeTime(-1)
	, totalTime(0)
	, countFrames(0)
	, updateFrames(60)
	, standardFps(60)
	, averageFps(0.0)
{
}


FpsController::~FpsController()
{

}

//画面の更新(ここで今は何のシーンかを判断・切り替える)
void FpsController::update()
{
	//初期値として前フレームにおける時間を疑似的に与える　【？】
	if (beforeTime == -1){
		beforeTime = GetNowHiPerformanceCount() - (100000 / standardFps);
	}
	//【GetNowHiPerformanceCount】 GetNowCountの高精度ver. それまでのミリ秒からマイクロ秒単位に。
	//戻り値は【long long】。 longの更にlongってどういう事なの・・・

	//フレームかうんとが規定値を超えていた場合初期化する
	if (countFrames >= updateFrames){
		countFrames = 0;
	}

	//1フレーム目(初期化直後)開始時の時間を記録しておく(上のif文と一緒くたではだめなのか？)
	if (countFrames == 0){
		startTime = GetNowHiPerformanceCount();
	}

	//1フレームの処理時間の計測
	long long nowTime = GetNowHiPerformanceCount();

	//カウンタが1週した場合の例外処理
	//numeric_limitsに関する記述は下記URL参照のこと
	// http://d.hatena.ne.jp/eldesh/20110120/1295497346
	if (nowTime < beforeTime){
		totalTime += (std::numeric_limits<long long>::max)() - beforeTime + nowTime;
	}
	else{
		totalTime += nowTime - beforeTime;
	}

	//今の時間を以前の時間として記憶
	beforeTime = nowTime;

	//フレームのカウントアップ
	++countFrames;

	//フレームカウントが規定値を超えていた場合、平均FPS(フレームレート)を算出する。
	if (countFrames >= updateFrames){
		//【static_cast】 本来ならばエラーの出る処理を「わざとやっている」と知らせるために付けておくもの。
		double aveTime = totalTime / static_cast<double>(countFrames);
		if (aveTime > 0){
			//1Mμsec (= 1sec)
			averageFps = 1000000 / aveTime;
		}
		else{
			averageFps = 0.0;
		}
		totalTime = 0;
	}

}

//待機処理・fpsカウント
void FpsController::wait(){
	//経過秒数を求め、規定FPSで動作しているように処理動作を調整する
	long long nowTime = GetNowHiPerformanceCount();
	long long tookTime;

	//カウンタが
	if (nowTime < beforeTime){
		totalTime += (std::numeric_limits<long long>::max)() - beforeTime + nowTime;
	}
	else{
		totalTime += nowTime - beforeTime;
	}
}

void FpsController::setColor(int red, int green, int blue){
	color = GetColor(red,green,blue);
}
