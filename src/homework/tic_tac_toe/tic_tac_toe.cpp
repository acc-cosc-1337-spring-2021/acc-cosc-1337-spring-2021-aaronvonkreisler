//cpp
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;


void TicTacToe::clear_board() {
  for (std::size_t i=0; i < pegs.size(); ++i) {
    pegs[i] = " ";
  }
}

void TicTacToe::set_winner(){
  if (player == "X") {
    winner = "O";
  } else {
    winner = "X";
  }
}

bool TicTacToe::game_over() {

  bool column_winner = this -> check_column_win();
  bool row_winner = this -> check_row_win();
  bool diaganol_winner = this -> check_diagonal_win();

  bool is_full =  this -> check_board_full();

  if (column_winner || row_winner || diaganol_winner) {
    this -> set_winner();
    return true;
  }

  if(!column_winner && !row_winner && !diaganol_winner && is_full) {
    winner = "C";
    return true;
  }

  return false;
}


bool TicTacToe::check_board_full() {
  bool is_full = true;

  for (std::size_t i = 0; i < pegs.size(); ++i) {
    if (pegs[i] == " ") {
      is_full = false;
      break;
    }
  }

  return is_full;
}

void TicTacToe::start_game(string first_player) {
  player = first_player;
  this -> clear_board();
}


void TicTacToe::set_next_player(){
  if (player == "X")
    player = "O";
  else  
    player = "X";
}


void TicTacToe::mark_board(int position) {
  pegs[position - 1] = this ->player;

  this -> set_next_player();
}

void TicTacToe::display_board() const {
  //print lines 

  for (int j = 0; j < 9; ++j) {
  cout<<"|"<< j + 1;
  cout<<"  "<<pegs[j];
  cout<<"______"<<" |";
  if ((j + 1) % 3 == 0) {
    cout<< "\n";
  }

  }

}

bool TicTacToe::check_column_win() {

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

bool TicTacToe::check_row_win() {
  // ROW POSITIONS 0, 1, 2
  bool win = false;

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

bool TicTacToe::check_diagonal_win(){
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