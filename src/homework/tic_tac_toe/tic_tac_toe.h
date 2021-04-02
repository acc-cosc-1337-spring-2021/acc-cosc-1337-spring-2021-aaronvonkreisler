//h
#include <vector>
#include <string>

using std::string;
using std::vector;

class Game {
  public:
    
    bool game_over() {
      return this -> check_board_full();
    }
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const{return player;}
    void display_board()const;

  private:
    vector<string> pegs {9, " "};
    string player;
    void clear_board();
    bool check_board_full();
    void set_next_player();

};