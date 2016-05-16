#ifndef Game_H
#define Game_H

class Game
{
public:
	Game();
	~Game();
	int run();
private:
	const int WIDTH  = 1024;
	const int HEIGHT =  768;
};

#endif // Game_H
