//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>

void TicTacToeManager::update_winner_count(string winner) {
  if (winner == "X") {
    x_win++;
  } else if (winner == "O") {
    o_win++;
  } else {
    ties++;
  }
}

void TicTacToeManager::save_game(TicTacToe b) {
  games.push_back(b); 
  update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t){
  o = o_win;
  w = x_win;
  t = ties;
}

std::ostream & operator << (std::ostream &out, const TicTacToeManager &manager) {
  for ( auto item = manager.games.begin(); item != manager.games.end(); ++item) {
    out<< *item << "\n";
  }
  return out;
}
