//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

#include <memory>
using std::unique_ptr;

#include <vector>
using std::vector;

#include <string>
#include <fstream>

class TicTacToeData {

  public:
    void save_games(const vector<unique_ptr<TicTacToe>>& games );
    vector<unique_ptr<TicTacToe>> get_games();
  private:
    const std::string file_name{"tic-tac-toe-data.dat"};
};

#endif