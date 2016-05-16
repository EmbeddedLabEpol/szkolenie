#ifndef Game_H
#define Game_H
#include <vector>
#include <Block.h>
class Game
{
public:
	Game();
	~Game();
	int run();
	void generateBlocksFields(std::vector<Block>&);
private:
	const int WIDTH  = 1024;
	const int HEIGHT =  768;
};

#endif // Game_H
