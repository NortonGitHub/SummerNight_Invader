#pragma once
#include <iostream>
#include <vector>

//
//class LoadStagedata
//{
//public:
//	LoadStagedata();
//	~LoadStagedata();
//};
//

//�ȉ�Marcopi.�����ꒆ�g�͕ύX�����ł��낤

// ���g�͕ς�邩������Ȃ�...
struct Data {
	//double x;
	//double y;
	//double sizeX;
	//double sizeY;
	//int type;
	int wave;
	int num[3];
	int total;
	int zensyu;
};

typedef std::vector<Data> DataList;


/// @brief �f�[�^�ɒl������C���^�[�t�F�[�X
struct DataLoader {
	virtual void load_pos_into_data(DataList& datas,int stagenum) = 0;
};
