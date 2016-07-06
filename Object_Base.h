#pragma once
class Object_Base
{
protected:
	double x;
	double y;
public:
	Object_Base(){};
	virtual ~Object_Base(){};

	virtual void update(){};
	virtual void draw(){};

};


