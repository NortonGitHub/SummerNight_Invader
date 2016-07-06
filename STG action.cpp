#include "DxLib.h" 
int x;
int y;
int graph;
void Update() {
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
		x -= 4;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
		x += 4;
	}
	if (CheckHitKey(KEY_INPUT_Z) ==1 ) {
		
	}

void Draw() {
	DrawGraph(x, y, graph, true);
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(true);// �E�B���h�E�ɂ��邩�t���X�N���[���ɂ��邩��ݒ肷��֐�
	if (DxLib_Init() == -1) {// �c�w���C�u��������������
		return -1;// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);    // �u����ʁv�ɕ`�悷��

	// �����ɏ����l�̐ݒ��摜�̓ǂݍ��݂�����
	x = 320;
	y = 240;
	graph = LoadGraph("Naitro_2.png");
	
	while (ProcessMessage() == 0) {    // �Q�[�����[�v
		ClearDrawScreen();    // ��ʂɕ`�������̂�����

		// �G�X�P�[�v�L�[���Ă΂ꂽ�烋�[�v�𔲂��A����
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// �����Ŗ��t���[�����s���鏈���i�摜�`��Ȃǁj������
		Update();
		Draw();


		ScreenFlip();    // �u����ʁv�ɕ`�������̂𔽉f������
	}

	// �����Ŏg�����摜����j������
	DeleteGraph(graph);


	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return 0;// �\�t�g�̏I�� 
}