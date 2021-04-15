//h
#include <vector>
#include <string>
#include <iostream>


using std::string;
using std::vector;

class TicTacToe {
  public:
    
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const{return player;}
    string get_winner() {
      return winner;
    }
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);
   

  private:
    vector<string> pegs {9, " "};
    string player;
    string winner;
    void clear_board();
    bool check_board_full();
    void set_next_player();
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();


};