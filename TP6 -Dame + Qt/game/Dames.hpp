#pragma once

#include "Game.hpp"

class Dames : public Game {
public:
  Dames();

  void run(int &mode);
  void display_grid();
  void check_win(bool &checker, int &winner);

private:
  void init_playground();
  void play(int symbol, bool withAI);
  void ai_move(int symbol);
  void human_move(int symbol);
  void choose_piece(int symbol, int &line, int &column);
  void choose_cell(int symbol, int &line, int &column);
  bool can_move(int player_symbol, int line, int column);
  bool can_jump(int player_symbol, int line, int column);
  void choose_target(int symbol, int line, int column, bool first_move,
                     int &line_target, int &column_target, bool &is_jump);
  void move_piece(int symbol, int line, int column, int line_target,
                  int column_target);
  bool is_valid_move(int symbol, int line, int column, bool first_move,
                     int line_target, int column_target, bool &is_jump);
};
