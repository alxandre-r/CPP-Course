#include "Dames.hpp"
#include <cstdlib>

Dames::Dames() { grid = new Grid(10, 10); }

void Dames::run(int &mode) {
  init_playground();
  int symbol;
  switch (mode) {
  default:
    std::cerr << "Invalid mode" << std::endl;
    break;
  case 1:
    std::cout << "Playing against computer" << std::endl;
    choose_symbol(symbol);
    play(symbol, true);
    break;
  case 2:
    std::cout << "Playing against another human" << std::endl;
    choose_symbol(symbol);
    play(symbol, false);
    break;
  }
}

void Dames::display_grid() { grid->display(); }

void Dames::check_win(bool &checker, int &winner) {}

void Dames::init_playground() {
  int x = 0;
  int y = 1;
  for (int i = 0; i < 20; i++) {
    grid->set_element(x, y, 1);
    grid->set_element(9 - x, 9 - y, 2);
    y += 2;
    if (y >= 10) {
      x++;
      y = x % 2 == 0 ? 1 : 0;
    }
  }
}

void Dames::play(int symbol, bool withAI) {
  bool player_win = false;
  int winner;
  int current_player = symbol;

  while (!player_win) {
    std::cout << "Au tour de " << (current_player == 1 ? "X" : "O")
              << std::endl;
    if (withAI && current_player != symbol) {
      ai_move(current_player);
    } else {
      human_move(current_player);
    }
    current_player = current_player == 1 ? 2 : 1;

    check_win(player_win, winner);
  }
  display_grid();
  end_screen(symbol, winner);
}

void Dames::ai_move(int symbol) { std::cout << "AI turn" << std::endl; }

void Dames::human_move(int symbol) {
  int line;
  int column;
  int line_target;
  int column_target;
  bool valid = false;
  bool first_move = true;
  bool has_jumped = false;
  display_grid();
  while (!valid) {
    choose_piece(symbol, line, column);
    if (can_move(symbol, line, column))
      valid = true;
    else
      std::cout << "Cette pièce ne peut pas bouger, choisissez-en une autre"
                << std::endl;
  }
  do {
    display_grid();
    choose_target(symbol, line, column, first_move, line_target, column_target,
                  has_jumped);
    first_move = false;
    move_piece(symbol, line, column, line_target, column_target);
    line = line_target;
    column = column_target;
  } while (has_jumped && can_jump(symbol, line, column));
}

void Dames::choose_piece(int symbol, int &line, int &column) {
  std::cout << "Choisissez la pièce que vous voulez déplacer" << std::endl;
  bool valid = false;
  while (!valid) {
    choose_cell(symbol, line, column);
    if (grid->get_element(line, column) == symbol)
      valid = true;
    else
      std::cout << "Cette case ne contient pas une de vos pièces" << std::endl;
  }
}

void Dames::choose_cell(int symbol, int &line, int &column) {
  char column_char;
  std::cout << "Entrez une colonne (A à J) et une ligne (1 à 10)" << std::endl;
  std::cin >> column_char >> line;

  verif_IsLetterBetween(column_char, 'A', 'J');
  verif_IsIntegerBetween(line, 1, 10);

  column = column_char - 65;
  line -= 1;
}

bool Dames::can_move(int symbol, int line, int column) {
  int forward_line = line + (symbol == 1 ? 1 : -1);
  if (forward_line >= 0 && forward_line < grid->get_height() &&
      ((column - 1 >= 0 && grid->get_element(forward_line, column - 1) == 0) ||
       (column + 1 < grid->get_width() &&
        grid->get_element(forward_line, column + 1) == 0)))
    return true;

  return can_jump(symbol, line, column);
}

bool Dames::can_jump(int player_symbol, int line, int column) {
  int opponent_symbol = player_symbol == 1 ? 2 : 1;

  if (line - 2 >= 0 &&
      ((column - 2 >= 0 &&
        grid->get_element(line - 1, column - 1) == opponent_symbol &&
        grid->get_element(line - 2, column - 2) == 0) ||
       (column + 2 < grid->get_width() &&
        grid->get_element(line - 1, column + 1) == opponent_symbol &&
        grid->get_element(line - 2, column + 2) == 0)))
    return true;

  if (line + 2 < grid->get_height() &&
      ((column - 2 >= 0 &&
        grid->get_element(line + 1, column - 1) == opponent_symbol &&
        grid->get_element(line + 2, column - 2) == 0) ||
       (column + 2 < grid->get_width() &&
        grid->get_element(line + 1, column + 1) == opponent_symbol &&
        grid->get_element(line + 2, column + 2) == 0)))
    return true;

  return false;
}

void Dames::choose_target(int symbol, int line, int column, bool first_move,
                          int &line_target, int &column_target, bool &is_jump) {
  std::cout << "Où voulez-vous déplacer cette pièce ?" << std::endl;
  bool valid = false;
  while (!valid) {
    choose_cell(symbol, line_target, column_target);
    if (is_valid_move(symbol, line, column, first_move, line_target,
                      column_target, is_jump))
      valid = true;
    else
      std::cout << "Mouvement non valide, veuillez choisir une autre case"
                << std::endl;
  }
}

bool Dames::is_valid_move(int symbol, int line, int column, bool first_move,
                          int line_target, int column_target, bool &is_jump) {
  int opponent_symbol = symbol == 1 ? 2 : 1;
  if (grid->get_element(line_target, column_target) != 0)
    return false;

  int line_offset = line_target - line;
  int column_offset = column_target - column;

  if (first_move && (line_offset == -1 || line_offset == 1) &&
      (column_offset == -1 || column_offset == 1)) {
    is_jump = false;
    return true;
  }

  is_jump = true;
  int line_jumped, column_jumped;

  if (line_offset == 2) {
    line_jumped = line + 1;
  } else if (line_offset == -2) {
    line_jumped = line - 1;
  } else {
    return false;
  }

  if (column_offset == 2) {
    column_target = column + 1;
  } else if (column_offset == -2) {
    column_jumped = column - 1;
  }

  return grid->get_element(line_jumped, column_jumped) == opponent_symbol;
}

void Dames::move_piece(int symbol, int line, int column, int line_target,
                       int column_target) {
  grid->set_element(line, column, 0);
  grid->set_element(line_target, column_target, symbol);

  if (abs(line_target - line) == 2) {
    grid->set_element((line_target + line) / 2, (column_target + column) / 2,
                      0);
  }
}
