#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() 
{
	int position;
	string player = "";
	int o_win = 0;
	int x_win = 0;
	int tie = 0;
	TicTacToe game;
	TicTacToeManager manager;

		cout<<"----------------------------------------------------\n\n";
		cout<<"Welcome to tic tac toe. At any time you want to quit the game, \n";
		cout<< "just type the number 12.\n";
		cout<<"----------------------------------------------------\n\n";

	do { 
		cout<<"Who will play first? ( capital X or capital O ): \n";
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
			cout << game;

			bool keep_playing = true;

			while(keep_playing) {
				cout << "Player "<< game.get_player() <<" select a spot\n";
				cin >> game;

				if (game.game_over()) {
						manager.save_game(game);
						manager.get_winner_total(o_win, x_win, tie);


						string winner = game.get_winner();
						string message = winner == "C" ? "It\'s a tie!!\n\n" : "Player " + winner + " wins!!! \n";
						
						cout<<"************************************** \n\n";
						cout<< message;
						cout<< "All wins: \n";
						cout<< "Player X: "<<x_win<<"\n";
						cout<< "Player O: "<<o_win<<"\n";
						cout<< "Ties: "<<tie<<"\n";
						cout<<"************************************** \n \n";
						cout<<"Would you like to play again? (Y or N)\n";

						string answer;
						cin>>answer;

					if (answer == "N" || answer == "n") {
						cout<<manager;
						keep_playing = false;
						position = 12;
					} else {
						keep_playing = false;
					}

				} else {
						cout<<game;
				}
			}
		}while(position != 12);


	return 0;
}