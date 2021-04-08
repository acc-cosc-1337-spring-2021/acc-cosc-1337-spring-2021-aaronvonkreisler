#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected") {
	Game game;
	game.start_game("X");

	//x
	game.mark_board(1);
	//o
	game.mark_board(2);
	//x
	game.mark_board(3);
	//o
	game.mark_board(4);
	//x
	game.mark_board(5);
	//o
	game.mark_board(7);
	//x
	game.mark_board(6);
	//o
	game.mark_board(9);
	//x
	game.mark_board(8);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test first player set to X") {
	Game game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	Game game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}



TEST_CASE("Test win by first column -- positions 1, 4, 7 [0, 3, 6]") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(1);
	 // o
	game.mark_board(7);
 		//x
	game.mark_board(4);
	  // o
	game.mark_board(5);
	 //x
	game.mark_board(7);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win by second column -- positions 2,5,8") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(2);
	 // o
	game.mark_board(7);
 		//x
	game.mark_board(5);
	  // o
	game.mark_board(9);
	 //x
	game.mark_board(8);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win by third column -- positions 3,6,9") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(3);
	 // o
	game.mark_board(1);
 		//x
	game.mark_board(6);
	  // o
	game.mark_board(2);
	 //x
	game.mark_board(9);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win by first row -- positions 1, 2, 3") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(1);
	 // o
	game.mark_board(9);
 		//x
	game.mark_board(2);
	  // o
	game.mark_board(8);
	 //x
	game.mark_board(3);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win by second row -- positions 4, 5, 6") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(4);
	 // o
	game.mark_board(9);
 		//x
	game.mark_board(5);
	  // o
	game.mark_board(8);
	 //x
	game.mark_board(6);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win by third row -- positions 7,8,9") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(7);
	 // o
	game.mark_board(2);
 		//x
	game.mark_board(8);
	  // o
	game.mark_board(4);
	 //x
	game.mark_board(9);
	
	REQUIRE(game.game_over() == true);
 }

TEST_CASE("Test win diagonally from top left (positions 1, 5, 9) ") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(1);
	 // o
	game.mark_board(2);
 		//x
	game.mark_board(5);
	  // o
	game.mark_board(4);
	 //x
	game.mark_board(9);
	
	REQUIRE(game.game_over() == true);
 }

 
TEST_CASE("Test win diagonally from bottom left (positions 7,5,3) ") {
	Game game;
	game.start_game("X");
	 //x
	game.mark_board(7);
	 // o
	game.mark_board(2);
 		//x
	game.mark_board(5);
	  // o
	game.mark_board(4);
	 //x
	game.mark_board(3);
	
	REQUIRE(game.game_over() == true);
 }