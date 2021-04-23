#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <vector>
#include <string>
#include <iostream>


using std::string;
using std::vector;

//TODO: 1.4 4. Modify the overloaded stream functions to work with TicTacToe 3 or 4
// It might be done

class TicTacToe {
  friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
  friend std::istream& operator>>(std::istream& in, TicTacToe& game);

  public:
    TicTacToe();
    TicTacToe(int size): pegs(size * size, " "){};
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const{return player;}
    string get_winner() {
      return winner;
    }

   
  protected:
    vector<string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

  private:
    string player;
    string winner;
    void clear_board();
    bool check_board_full();
    void set_next_player();
    void set_winner();

};

#endif