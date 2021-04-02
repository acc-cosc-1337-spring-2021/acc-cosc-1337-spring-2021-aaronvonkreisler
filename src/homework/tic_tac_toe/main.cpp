#include "tic_tac_toe.h"
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() 
{
	Game game;
	string player;
	int position;
	cout<<"----------------------------------------------------\n";
	cout<<"Welcome to tic tac toe. At any time you want to quit the game, \n";
	cout<< "just type the number 12.\n";
	cout<<"To start - who will play first? ( X or O ): \n";
	cin>>player;

	game.start_game(player);
	game.display_board();

	do{
	cout<<"Player "<<game.get_player()<<" select a spot\n";
	cin>>position;
	game.mark_board(position);
	game.display_board();
	}while(position != 12);


	return 0;
}