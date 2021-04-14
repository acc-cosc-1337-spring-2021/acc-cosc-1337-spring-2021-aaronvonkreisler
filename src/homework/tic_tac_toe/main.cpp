#include "tic_tac_toe.h"
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() 
{
	TicTacToe game;
	string player;
	int position;
	do { 
		cout<<"----------------------------------------------------\n\n";
		cout<<"Welcome to tic tac toe. At any time you want to quit the game, \n";
		cout<< "just type the number 12.\n";
		cout<<"To start - who will play first? ( capital X or capital O ): \n";
		cin>>player;

		while (player != "X" || player != "O" ) {
			cout<<"Please start the game with either a capital X or capital O \n";
			cout<<"Who will play first ? (X or O)\n";
			cin>>player;
			if (player == "X" || player == "O") {
				break;
			}
		}

			game.start_game(player);
			game.display_board();

			bool keep_playing = true;

			while(keep_playing) {
				cout<<"Player "<<game.get_player()<<" select a spot\n";
				cin>>position;
				game.mark_board(position);
				if (game.game_over()) {
					string winner = game.get_winner();
					string message = winner == "C" ? "It\'s a tie!!\n\n" : "Player " + winner + " wins!!! \n";
					cout<<"************************************** \n";
					cout<<"************************************** \n \n";
					cout<< message;
					cout<<"Would you like to play again? (Y or N)\n";

					string answer;
					cin>>answer;
					if(answer == "N" || answer == "n") {
						keep_playing = false;
						position = 12;
					} else {
						keep_playing = false;
					}

				} else {
						game.display_board();
				}
			}
}while(position != 12);


	return 0;
}