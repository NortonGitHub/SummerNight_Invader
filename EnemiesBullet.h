#pragma once
class EnemiesBullet
{
private:
	double _x;
	double _y;
	int bulletGraph;
	
	int sf;

	int t;
public:
	EnemiesBullet();
	EnemiesBullet(double x, double y);
	~EnemiesBullet();

	void Init(int x2, int y2, int graph2);
	void Update(/*int x, int y*/);
	void Draw();

	int getY(); //private“à‚Ì•Ï”‚ğŒÄ‚Ño‚·ŠÖ”
	int getX();
};

