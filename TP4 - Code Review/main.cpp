#include "game/Game.hpp"
#include "game/Morpion.hpp"
#include "game/Puissance4.hpp"
#include "utils/Utils.hpp"

int main()
{
	int mode = 0; //morpion = 1, puissance 4 = 2
	int mode2 = 0; //solo vs ia = 1, multi = 2
	main_menu(mode, mode2);
	Game* game = nullptr;

	switch(mode)
	{
		default:
			std::cerr << "Unknown error.\n";
			break;

		case 1:
			game = new Morpion();
			break;
			
		case 2:
			game = new Puissance4();
			break;
	}

	game->run(mode2);

	return 0;
}