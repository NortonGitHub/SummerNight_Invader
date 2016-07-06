#pragma once 
//シーン管理用

class Scene_Base
{
public:
	virtual ~Scene_Base(){};

	virtual Scene_Base* update() = 0;

	virtual void draw() = 0;


};