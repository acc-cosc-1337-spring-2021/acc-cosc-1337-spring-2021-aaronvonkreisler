//cpp
#include "tic_tac_toe_data.h"

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games) {
  std::ofstream out_file;

  out_file.open(file_name);

  if(out_file.is_open()) {
    for (auto& game: games){
      
      for (auto& pos: game->get_pegs()) {
        out_file<<pos;
      }
      out_file<<game ->get_winner();
      out_file<<"\n";
    }
    out_file.close();
  }


}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games() {
  vector<unique_ptr<TicTacToe>> boards;
  std::ifstream in_file;
  
  in_file.open(file_name);

  string line;

  if (in_file.is_open()) {
    while(std::getline(in_file, line)) {
      vector<string> pegs;

      for(std::size_t i = 0; i < (line.size() -1); ++i) {
        string ch(1, line[i]);
        pegs.push_back(ch);
      }
      string winner{line[line.size() -1]};

      unique_ptr<TicTacToe> game;

      if (pegs.size() == 9) {
        game = std::make_unique<TicTacToe3>(pegs, winner);
      } else if (pegs.size() == 16) {
        game = std::make_unique<TicTacToe4>(pegs, winner);
      }

      boards.push_back(std::move(game));
    }
    
    in_file.close();
  }

  return boards;
}