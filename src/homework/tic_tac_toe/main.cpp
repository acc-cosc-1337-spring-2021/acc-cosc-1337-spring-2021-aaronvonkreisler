#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include<memory>
using std::unique_ptr; using std::make_unique;

#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main() 
{
	string go_again;
	int o_win = 0;
	int x_win = 0;
	int tie = 0;
	TicTacToeData data;
	TicTacToeManager manager(data);

		cout<<"----------------------------------------------------\n\n";
		cout<<"Welcome to tic tac toe.\n";
		cout<<"----------------------------------------------------\n\n";



	// start of new game
	do { 
		unique_ptr<TicTacToe> game;
		string game_size;

		do {
			cout<< "Would you like to play 3x3 or 4x4? (enter 3 or 4)\n";
			cin>>game_size;

			if(game_size == "3") {
				game = make_unique<TicTacToe3>();

			} else if (game_size == "4") {
				game = make_unique<TicTacToe4>();
			}
		} while(!(game_size == "3" || game_size == "4"));

		string player;

		do{
			cout<<"Who will play first? ( capital X or capital O ): \n";
			cin>>player;
		} while (!(player == "X" || player == "O"));

			game -> start_game(player);
			cout << *game;

			do {
				cout << "Player "<< game->get_player() <<" select a spot\n";
				cin >> *game;
				cout<< *game;
			}while(!(game->game_over()));

			string winner = game ->get_winner();
			string message = winner == "C" ? "It\'s a tie!!\n\n" : "Player " + winner + " wins!!! \n";
			cout<<message;
			manager.save_game(game);
			manager.get_winner_total(o_win, x_win, tie);

			cout<< "All wins: \n";
			cout<< "Player X: "<<x_win<<"\n";
			cout<< "Player O: "<<o_win<<"\n";
			cout<< "Ties: "<<tie<<"\n";
			cout<<"************************************** \n \n";
			cout<<"Would you like to play again? (Y or N)\n";
			cin>>go_again;


	}while(go_again == "Y" || go_again == "y");
	// All games are over - display history
	cout<<"------------------------------\n";
	cout<< "Game History\n\n";
	cout<<manager;

	return 0;
}