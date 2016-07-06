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

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(true);// ウィンドウにするかフルスクリーンにするかを設定する関数
	if (DxLib_Init() == -1) {// ＤＸライブラリ初期化処理
		return -1;// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);    // 「裏画面」に描画する

	// ここに初期値の設定や画像の読み込みをする
	x = 320;
	y = 240;
	graph = LoadGraph("Naitro_2.png");
	
	while (ProcessMessage() == 0) {    // ゲームループ
		ClearDrawScreen();    // 画面に描いたものを消す

		// エスケープキーが呼ばれたらループを抜け、閉じる
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// ここで毎フレーム実行する処理（画像描画など）をする
		Update();
		Draw();


		ScreenFlip();    // 「裏画面」に描いたものを反映させる
	}

	// ここで使った画像等を破棄する
	DeleteGraph(graph);


	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// ソフトの終了 
}