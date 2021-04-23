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
  pegs[position - 1] = player;

  set_next_player();
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {

  if(game.pegs.size() == 9) {
    for (int i = 0; i < 9; ++i) {
        out<<"|"<< i + 1;
        out<<"  "<<game.pegs[i];
        out<<"______"<<" |";
        if ((i + 1) % 3 == 0) {
          out<< "\n";
        }
      }
      return out;
  } else if (game.pegs.size() == 16) {
    for (int i = 0; i < 16; ++i) {
        out<<"|"<< i + 1;
        out<<"  "<<game.pegs[i];
        out<<"______"<<" |";
      if ((i + 1) % 4 == 0) {
          out<< "\n";
        }
    }
    return out;
  }
  return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
  int position;
  in >> position;
  game.mark_board(position);
  return in;
}

bool TicTacToe::check_column_win() {
  return false;
}

bool TicTacToe::check_row_win() {
  return false;
}

bool TicTacToe::check_diagonal_win(){
  return false;
}