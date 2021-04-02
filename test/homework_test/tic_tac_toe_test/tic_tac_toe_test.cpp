#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Test game over if 9 slots are selected.") {
// 1)Create an instance of TicTacToe game
// 2)Call the start game function with X first player
// 3)Call mark board 9 times using numbers 1 to 9 (this test case will eventually be the test for CAT tie case). Positions: 
// 1,2,3,4,5,7,6,9,8
	Game game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);
	game.mark_board(6);
	game.mark_board(9);
	game.mark_board(8);

 }