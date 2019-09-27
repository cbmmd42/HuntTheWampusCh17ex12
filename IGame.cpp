#include "IGame.h"

IGame::IGame(IPlayer& p)
{
	player = &p;
}

std::string IGame::move(){
		std::string prompt = player->move();
		return prompt;
}