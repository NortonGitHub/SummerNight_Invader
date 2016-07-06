#pragma once
#include "DxLib.h"

class FpsController
{
public:
	~FpsController();

	static FpsController& getIns();

	bool setFps(int frames, int updateFrames = 60); //����FPS,�X�V�t���[�����̐ݒ�
	void setColor(int red, int green, int blue);
	void initCount();
	void update();
	void wait();
	void drawFps();

private:
	FpsController();
	
	int x, y;
	int color;

	long long startTime; 
	long long beforeTime;
	long long totalTime;
	int countFrames;
	int updateFrames;

	int standardFps;
	double averageFps;

};

inline FpsController& FpsController::getIns(){
	static FpsController ins;
	return ins;
}
