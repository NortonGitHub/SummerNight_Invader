// @brief TODO : Datから読む
#pragma warning ( disable : 4996 )
#include "LoadStagedata.h"
#include "DxLib.h"

/*StageManager.hのインクルードによってエラーを吐くかもしれない*/

class LoadDatafile : public DataLoader {

	virtual void load_pos_into_data(DataList& datas,int stagenum) {

		char filename[25];//ファイル名保存用文字列
		sprintf(filename, "data\\stage_data\\s%d.dat", stagenum);//filenameにファイル名をいれる

		int data = FileRead_open(filename);

		if (data != NULL)
		{

			int i = 0;


			//データ読み込み
			while (FileRead_eof(data) == 0){

				FileRead_scanf(data, "%d %d %d %d %d %d",
					&datas[i].wave, &datas[i].num[0], &datas[i].num[1], &datas[i].num[2], &datas[i].total,&datas[i].zensyu);

				i++;
			}

			FileRead_close(data);
		}

		else{
			MessageBox(NULL, TEXT("ステージデータの読み込みに失敗しました"), TEXT("ERROR!!"), MB_OK);
			
		}
	}
};