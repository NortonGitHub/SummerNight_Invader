// @brief TODO : Dat����ǂ�
#pragma warning ( disable : 4996 )
#include "LoadStagedata.h"
#include "DxLib.h"

/*StageManager.h�̃C���N���[�h�ɂ���ăG���[��f����������Ȃ�*/

class LoadDatafile : public DataLoader {

	virtual void load_pos_into_data(DataList& datas,int stagenum) {

		char filename[25];//�t�@�C�����ۑ��p������
		sprintf(filename, "data\\stage_data\\s%d.dat", stagenum);//filename�Ƀt�@�C�����������

		int data = FileRead_open(filename);

		if (data != NULL)
		{

			int i = 0;


			//�f�[�^�ǂݍ���
			while (FileRead_eof(data) == 0){

				FileRead_scanf(data, "%d %d %d %d %d %d",
					&datas[i].wave, &datas[i].num[0], &datas[i].num[1], &datas[i].num[2], &datas[i].total,&datas[i].zensyu);

				i++;
			}

			FileRead_close(data);
		}

		else{
			MessageBox(NULL, TEXT("�X�e�[�W�f�[�^�̓ǂݍ��݂Ɏ��s���܂���"), TEXT("ERROR!!"), MB_OK);
			
		}
	}
};