#include "KeyManager.h"

//コンストラクタ
KeyManager::KeyManager(){
    int keyData[] = { 
        KEY_INPUT_LEFT, KEY_INPUT_RIGHT, KEY_INPUT_UP, KEY_INPUT_DOWN, 
        KEY_INPUT_X, KEY_INPUT_C, KEY_INPUT_SPACE, KEY_INPUT_Z,
        KEY_INPUT_B };


    int padData[] = { 
        PAD_INPUT_LEFT, PAD_INPUT_RIGHT, PAD_INPUT_UP, PAD_INPUT_DOWN, 
        PAD_INPUT_1, PAD_INPUT_2, PAD_INPUT_3, PAD_INPUT_4,
        PAD_INPUT_10 };


    //キーコード
    keyInputLeft  = keyData[0];
    keyInputRight = keyData[1];
    keyInputUp    = keyData[2];
    keyInputDown  = keyData[3];

    keyInputStab = keyData[4];
    keyInputCut  = keyData[5];
    keyInputJump = keyData[6];
    keyInputRoll = keyData[7];

    keyInputMenu = keyData[8];

    //パッド
    padInputLeft  = padData[0];
    padInputRight = padData[1];
    padInputUp    = padData[2];
    padInputDown  = padData[3];

    padInputStab = padData[4];
    padInputCut  = padData[5];
    padInputJump = padData[6];
    padInputRoll = padData[7];

    padInputMenu = padData[7];

    //初期化
    memset(keyFrame, 0, sizeof(keyFrame));

}

//デストラクタ
KeyManager::~KeyManager(){
}



//キーの入力フレーム数
int KeyManager::GetInputKeyFrame(int keyInputCode){
    return keyFrame[keyInputCode];
}

//キーの更新
void KeyManager::UpdateKeyState(){
    //現在の入力状態を取得
    GetHitKeyStateAll(keyStateBuf);

    keyStateBuf[keyInputLeft] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputLeft) != 0) ? 1 : 0;
    keyStateBuf[keyInputRight]|= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputRight)!= 0) ? 1 : 0;
    keyStateBuf[keyInputUp]   |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputUp)   != 0) ? 1 : 0;
    keyStateBuf[keyInputDown] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputDown) != 0) ? 1 : 0;
    keyStateBuf[keyInputStab] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputStab) != 0) ? 1 : 0;
    keyStateBuf[keyInputCut]  |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputCut)  != 0) ? 1 : 0;
    keyStateBuf[keyInputJump] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputJump) != 0) ? 1 : 0;
    keyStateBuf[keyInputRoll] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputRoll) != 0) ? 1 : 0;
    keyStateBuf[keyInputMenu] |= ((GetJoypadInputState(DX_INPUT_PAD1) & padInputMenu) != 0) ? 1 : 0;


    //キーが押されていたらそのキーのフレームをインクリメント
    //押されていなかったら0を代入
    for (int i = 0; i<256; ++i)

        keyFrame[i] = keyStateBuf[i] ? ++keyFrame[i] : 0;

}

void KeyManager::reset(){
    for (int i = 0; i<256; ++i)

        keyFrame[i] = 0;
}

