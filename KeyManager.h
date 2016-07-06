#pragma once

#include "DxLib.h"

// 省略
#define KeyM KeyManager::instance()	// KeyM->でアクセス可能

class KeyManager{
public:
    static KeyManager* instance();		// インスタンス取得

    int GetInputKeyFrame(int KEY_INPUT_CODE);
    void UpdateKeyState();
    void reset();
    void save();


    //キーコード
    int keyInputLeft;	//左
    int keyInputRight;	//右
    int keyInputUp;		//上
    int keyInputDown;	//下

    int keyInputStab;	//突き
    int keyInputCut;	//切り
    int keyInputJump;	//ジャンプ
    int keyInputRoll;   //ローリング

    int keyInputMenu;	//メニュー&ポーズ

    int keyInputRetry;


    //パッドコード
    int padInputLeft;	//左
    int padInputRight;	//右
    int padInputUp;		//上
    int padInputDown;	//下

    int padInputStab;	//突き
    int padInputCut;	//切り
    int padInputJump;	//ジャンプ
    int padInputRoll;   //ローリング

    int padInputMenu;	//メニュー&ポーズ


    int keyFrame[256];		// キー入力フレーム保持用
    char keyStateBuf[256];	// キー入力チェック用バッファ

private:
    KeyManager();
    KeyManager(const KeyManager&);
    KeyManager& operator=(const KeyManager&);
    ~KeyManager();

};

// インスタンス取得
inline KeyManager* KeyManager::instance(){
    static KeyManager ins;
    return &ins;
}
