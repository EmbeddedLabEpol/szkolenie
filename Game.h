#ifndef Game_H
#define Game_H
#include <vector>
#include <Block.h>
#include "GameWindow.h"
class Game
{
public:
	Game();
	~Game();
	int run();
	void generateBlocksFields(std::vector<Block>&, int, int);
private:
	const int WIDTH  = 1024;
	const int HEIGHT =  768;
	
	void pause(GameWindow& window);
	
	
};

#endif // Game_H
