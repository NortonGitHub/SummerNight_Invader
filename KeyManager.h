#pragma once

#include "DxLib.h"

// �ȗ�
#define KeyM KeyManager::instance()	// KeyM->�ŃA�N�Z�X�\

class KeyManager{
public:
    static KeyManager* instance();		// �C���X�^���X�擾

    int GetInputKeyFrame(int KEY_INPUT_CODE);
    void UpdateKeyState();
    void reset();
    void save();


    //�L�[�R�[�h
    int keyInputLeft;	//��
    int keyInputRight;	//�E
    int keyInputUp;		//��
    int keyInputDown;	//��

    int keyInputStab;	//�˂�
    int keyInputCut;	//�؂�
    int keyInputJump;	//�W�����v
    int keyInputRoll;   //���[�����O

    int keyInputMenu;	//���j���[&�|�[�Y

    int keyInputRetry;


    //�p�b�h�R�[�h
    int padInputLeft;	//��
    int padInputRight;	//�E
    int padInputUp;		//��
    int padInputDown;	//��

    int padInputStab;	//�˂�
    int padInputCut;	//�؂�
    int padInputJump;	//�W�����v
    int padInputRoll;   //���[�����O

    int padInputMenu;	//���j���[&�|�[�Y


    int keyFrame[256];		// �L�[���̓t���[���ێ��p
    char keyStateBuf[256];	// �L�[���̓`�F�b�N�p�o�b�t�@

private:
    KeyManager();
    KeyManager(const KeyManager&);
    KeyManager& operator=(const KeyManager&);
    ~KeyManager();

};

// �C���X�^���X�擾
inline KeyManager* KeyManager::instance(){
    static KeyManager ins;
    return &ins;
}
