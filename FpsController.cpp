#include "FpsController.h"
//char�^��int�^�̍ő�l��ŏ��l����`����Ă���A�}�O�����Ƃ��}�N���B
#include <limits>


FpsController::FpsController()//������ł͂Ȃ�
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

//��ʂ̍X�V(�����ō��͉��̃V�[�����𔻒f�E�؂�ւ���)
void FpsController::update()
{
	//�����l�Ƃ��đO�t���[���ɂ����鎞�Ԃ��^���I�ɗ^����@�y�H�z
	if (beforeTime == -1){
		beforeTime = GetNowHiPerformanceCount() - (100000 / standardFps);
	}
	//�yGetNowHiPerformanceCount�z GetNowCount�̍����xver. ����܂ł̃~���b����}�C�N���b�P�ʂɁB
	//�߂�l�́ylong long�z�B long�̍X��long���Ăǂ��������Ȃ́E�E�E

	//�t���[��������Ƃ��K��l�𒴂��Ă����ꍇ����������
	if (countFrames >= updateFrames){
		countFrames = 0;
	}

	//1�t���[����(����������)�J�n���̎��Ԃ��L�^���Ă���(���if���ƈꏏ�����ł͂��߂Ȃ̂��H)
	if (countFrames == 0){
		startTime = GetNowHiPerformanceCount();
	}

	//1�t���[���̏������Ԃ̌v��
	long long nowTime = GetNowHiPerformanceCount();

	//�J�E���^��1�T�����ꍇ�̗�O����
	//numeric_limits�Ɋւ���L�q�͉��LURL�Q�Ƃ̂���
	// http://d.hatena.ne.jp/eldesh/20110120/1295497346
	if (nowTime < beforeTime){
		totalTime += (std::numeric_limits<long long>::max)() - beforeTime + nowTime;
	}
	else{
		totalTime += nowTime - beforeTime;
	}

	//���̎��Ԃ��ȑO�̎��ԂƂ��ċL��
	beforeTime = nowTime;

	//�t���[���̃J�E���g�A�b�v
	++countFrames;

	//�t���[���J�E���g���K��l�𒴂��Ă����ꍇ�A����FPS(�t���[�����[�g)���Z�o����B
	if (countFrames >= updateFrames){
		//�ystatic_cast�z �{���Ȃ�΃G���[�̏o�鏈�����u�킴�Ƃ���Ă���v�ƒm�点�邽�߂ɕt���Ă������́B
		double aveTime = totalTime / static_cast<double>(countFrames);
		if (aveTime > 0){
			//1M��sec (= 1sec)
			averageFps = 1000000 / aveTime;
		}
		else{
			averageFps = 0.0;
		}
		totalTime = 0;
	}

}

//�ҋ@�����Efps�J�E���g
void FpsController::wait(){
	//�o�ߕb�������߁A�K��FPS�œ��삵�Ă���悤�ɏ�������𒲐�����
	long long nowTime = GetNowHiPerformanceCount();
	long long tookTime;

	//�J�E���^��
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
