#pragma once 
//�V�[���Ǘ��p

class Scene_Base
{
public:
	virtual ~Scene_Base(){};

	virtual Scene_Base* update() = 0;

	virtual void draw() = 0;


};