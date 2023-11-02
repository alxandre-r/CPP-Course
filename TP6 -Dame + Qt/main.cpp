#include "game/Game.hpp"
#include "game/Morpion.hpp"
#include "game/Puissance4.hpp"
#include "game/Othello.hpp"
#include "game/Dames.hpp"
#include "utils/Utils.hpp"

int main()
{
	int mode = 0; //morpion = 1, puissance 4 = 2
	int mode2 = 0; //solo vs ia = 1, multi = 2
	main_menu(mode, mode2);
	std::unique_ptr<Game> game;

	switch(mode)
	{
		case 1:
			game = std::make_unique<Morpion>();
			break;
			
		case 2:
			game = std::make_unique<Puissance4>();
			break;
			
		case 3:
			game = std::make_unique<Othello>();
			break;
		
		case 4:
			game = std::make_unique<Dames>();
			break;
			
		default:
			std::cerr << "Unknown error.\n";
			break;
	}

	game->run(mode2);

	return 0;
}