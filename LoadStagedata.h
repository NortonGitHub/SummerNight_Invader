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

//以下Marcopi.いずれ中身は変更されるであろう

// 中身は変わるかもしれない...
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


/// @brief データに値を入れるインターフェース
struct DataLoader {
	virtual void load_pos_into_data(DataList& datas,int stagenum) = 0;
};
