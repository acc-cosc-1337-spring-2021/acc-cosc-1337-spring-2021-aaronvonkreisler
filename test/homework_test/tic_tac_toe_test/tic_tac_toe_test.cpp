#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
using std::cout; using std::cin;

#include <memory>
using std::unique_ptr; using std::make_unique;


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected")
{

  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

  game->start_game("X");

  game->mark_board(1);
  game->mark_board(2);
  game->mark_board(3);
  game->mark_board(5);
  game->mark_board(4);
  game->mark_board(6);
  game->mark_board(8);
  game->mark_board(7);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "C"); 
}


TEST_CASE("Test first player set to X")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("O");

  REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column -- positions 1,4,7 [0, 3 6]", "TicTacToe 3")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X"); 

  game->mark_board(1);
  game->mark_board(2);
  game->mark_board(4); 
  game->mark_board(3);
  game->mark_board(7);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column -- positions 2,5,8", "TicTacToe 3")
{

  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(2);
  game->mark_board(7);
  game->mark_board(5);
  game->mark_board(9);
  game->mark_board(8);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column -- positions 3,6,9", "TicTacToe 3")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(3);
  game->mark_board(2);
  game->mark_board(6);
  game->mark_board(5);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row -- positions 1,2,3", "TicTacToe 3")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(1);
  game->mark_board(7);
  game->mark_board(2);
  game->mark_board(9);
  game->mark_board(3);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row with manager also -- positions 4,5,6", "TicTacToe 3")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(4);
  game->mark_board(2);
  game->mark_board(5);
  game->mark_board(3);
  game->mark_board(6);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row -- positions 7,8,9", "Tic tac toe 3")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(7);
  game->mark_board(5);
  game->mark_board(8);
  game->mark_board(3);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left (positions 1, 5, 9)", "Tictactoe 3")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(1);
  game->mark_board(2);
  game->mark_board(5);
  game->mark_board(3);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test win diagonally from bottom left (positions 7,5,3)", "Tictactoe 3")
{

  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");

  game->mark_board(7);
  game->mark_board(2);
  game->mark_board(5);
  game->mark_board(9);
  game->mark_board(3);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

//had to change
TEST_CASE("Test TicTacToeManager")
{
  TicTacToeManager manager;
	
  int x; 
  int o;
  int t;

  unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
  game1->start_game("X");
  
  game1->mark_board(4);
  game1->mark_board(2);
  game1->mark_board(5);
  game1->mark_board(3);
  game1->mark_board(6);
  REQUIRE(game1->game_over() == true);
  REQUIRE(game1->get_winner() == "X");

  manager.save_game(game1);

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

  unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
  game2->start_game("O");

  game2->mark_board(7);
  game2->mark_board(2);
  game2->mark_board(8);
  game2->mark_board(3);
  game2->mark_board(9);
  REQUIRE(game2->game_over() == true);
  REQUIRE(game2->get_winner() == "O");

  manager.save_game(game2);

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

  
  unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
  game3->start_game("X");

  game3->mark_board(1);
  game3->mark_board(2);
  game3->mark_board(3);
  game3->mark_board(5);
  game3->mark_board(4);
  game3->mark_board(6);
  game3->mark_board(8);
  game3->mark_board(7);
  game3->mark_board(9);
  REQUIRE(game3->game_over() == true);

  manager.save_game(game3);

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 1);

}

//---------------------------------------4 X 4 Tests --------------------------------------

TEST_CASE("Test game over if 9 slots are selected 4", "Game ends in tie")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();

  game->start_game("X");

  game->mark_board(1);
  game->mark_board(2);
  game->mark_board(3);
  game->mark_board(5);
  game->mark_board(4);
  game->mark_board(6);
  game->mark_board(8);
  game->mark_board(7);
  game->mark_board(9);
  game->mark_board(10);
  game->mark_board(11);
  game->mark_board(12);
  game->mark_board(14);
  game->mark_board(13);
  game->mark_board(16);
  game->mark_board(15);
  REQUIRE(game->game_over() == true);


  REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("O");

  REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(1);
  game->mark_board(2);
  game->mark_board(5);
  game->mark_board(6);
  game->mark_board(9);
  game->mark_board(10);
  game->mark_board(13);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");


}

TEST_CASE("Test win by second column 4")
{

  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X"); 

  game->mark_board(2);
  game->mark_board(3);
  game->mark_board(6);
  game->mark_board(7);
  game->mark_board(10);
  game->mark_board(11);
  game->mark_board(14);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column 4")
{
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(3);
  game->mark_board(4);
  game->mark_board(7);
  game->mark_board(8);
  game->mark_board(11);
  game->mark_board(12);
  game->mark_board(15);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(4);
  game->mark_board(3);
  game->mark_board(8);
  game->mark_board(7);
  game->mark_board(12);
  game->mark_board(11);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(1);
  game->mark_board(7); 
  game->mark_board(2);
  game->mark_board(9);
  game->mark_board(3);
  game->mark_board(8);
  game->mark_board(4);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row 4")
{

  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(5);
  game->mark_board(1); 
  game->mark_board(6);
  game->mark_board(2);
  game->mark_board(7);
  game->mark_board(3);
  game->mark_board(8);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test win by third row 4")
{

  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(9);
  game->mark_board(1); 
  game->mark_board(10);
  game->mark_board(2);
  game->mark_board(11);
  game->mark_board(3);
  game->mark_board(12);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test win by fourth row 4")
{

  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(13);
  game->mark_board(1); 
  game->mark_board(14);
  game->mark_board(2);
  game->mark_board(15);
  game->mark_board(3);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
  
}

TEST_CASE("Test win diagonally from top left 4")
{

  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(1);
  game->mark_board(2); 
  game->mark_board(6);
  game->mark_board(3);
  game->mark_board(11);
  game->mark_board(12);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test win diagonally from bottom left 4")
{
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(13);
  game->mark_board(2); 
  game->mark_board(10);
  game->mark_board(3);
  game->mark_board(7);
  game->mark_board(12);
  game->mark_board(4);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test TicTacToe manager 4")
{
	TicTacToeManager manager;
  int x;
  int o;
  int t;


  unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
  game1->start_game("X");
  
  game1->mark_board(1);
  game1->mark_board(5); 
  game1->mark_board(2);
  game1->mark_board(6);
  game1->mark_board(3);
  game1->mark_board(7);
  game1->mark_board(4);
  REQUIRE(game1->game_over() == true);
  REQUIRE(game1->get_winner() == "X");
  manager.save_game(game1);
	


  unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
  game2->start_game("O");

  game2->mark_board(1); 
  game2->mark_board(5);
  game2->mark_board(2);
  game2->mark_board(6);
  game2->mark_board(3);
  game2->mark_board(7);
  game2->mark_board(4);
  REQUIRE(game2->game_over() == true);
  REQUIRE(game2->get_winner() == "O");
  manager.save_game(game2);



  unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();
  game3->start_game("X");

  game3->mark_board(1);
  game3->mark_board(2);
  game3->mark_board(3);
  game3->mark_board(4);
  game3->mark_board(5);
  game3->mark_board(6);
  game3->mark_board(7);
  game3->mark_board(8);
  
  game3->mark_board(9);
  game3->mark_board(10);
  game3->mark_board(11);
  game3->mark_board(12);
  game3->mark_board(14);
  game3->mark_board(15);
  game3->mark_board(16);
  game3->mark_board(13);

  
  manager.save_game(game3);

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 1);

}

