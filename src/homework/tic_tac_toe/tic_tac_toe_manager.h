#include "tic_tac_toe.h"
#include <iostream>
#include <vector>
using std::vector;

#include <string>
using std::string;

class TicTacToeManager {
  private:
    vector<TicTacToe> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(string winner);

  public:
    void save_game(TicTacToe b);
    void get_winner_total(int& o, int& w, int& t);
    friend std::ostream & operator << (std::ostream &out, const TicTacToeManager &manager);

};