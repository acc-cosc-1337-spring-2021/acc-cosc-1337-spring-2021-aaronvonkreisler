#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

bool TicTacToe3::check_column_win() {
   bool win = false;
  //column positions 0,3,6
  if (pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X") {
    win = true;
    return win;
  }

  if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O") {
    win = true;
    return win;
  }

  // COLUMN POSITIONS 1,4,7
   if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X") {
    win = true;
    return win;
  }
   if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O") {
    win = true;
    return win;
  }

  //COLUMN POSITIONS 2,5,8
 if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X") {
    win = true;
    return win;
  }

  if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O") {
    win = true;
    return win;
  }

  return win;
}

/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/

bool TicTacToe3::check_row_win(){
  bool win = false;

  // ROW POSITIONS 0, 1, 2
  if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") {
    win = true;
    return win;
  }
  
  if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") {
    win = true;
    return win;
  }

  // ROW POSITIONS 3,4,5
  if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") {
    win = true;
    return win;
  }

  if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") {
    win = true;
    return win;
  }

  // ROW POSITIONS 6,7,8 (7,8,9 visually)
  if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X") {
    win = true;
    return win;
  }
  if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O") {
    win = true;
    return win;
  }

  return win;
}




/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/

bool TicTacToe3::check_diagonal_win(){
  bool win = false;
  // POSITIONS 0,4,8 (1,5,9 visually)
  if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X") {
    win = true;
    return win;
  }
  if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O") {
    win = true;
    return win;
  }

  // POSITIONS 2,4,6 (7,5,3 visually)

  if (pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X") {
    win = true;
    return win;
  }

  if (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O") {
    win = true;
    return win;
  }

  return win;
}
