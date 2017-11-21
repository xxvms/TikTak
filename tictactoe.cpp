//
// Created by Tristan Brindle on 14/11/2017.
//

#include "tictactoe.hpp"

namespace tictactoe {

std::ostream& operator<<(std::ostream& os, entry e) {
  switch (e) {
    case entry::empty:
      return os << " ";
    case entry::nought:
      return os << "O";
    case entry::cross:
      return os << "X";
  }
}

board::board() { array_.fill(entry::empty); }

entry board::operator()(int row, int col) const {
  if (row < 0 || row > 2) {
    throw std::out_of_range{"Row must be in the range 0-2, got " +
                            std::to_string(row)};
  }
  if (col < 0 || col > 2) {
    throw std::out_of_range{"Column must be in the range 0-2, got " +
                            std::to_string(col)};
  }

  return array_[row * 3 + col];
}

entry& board::operator()(int row, int col) {
  if (row < 0 || row > 2) {
    throw std::out_of_range{"Row must be in the range 0-2, got " +
                            std::to_string(row)};
  }
  if (col < 0 || col > 2) {
    throw std::out_of_range{"Column must be in the range 0-2, got " +
                            std::to_string(col)};
  }

  return array_[row * 3 + col];
}
void board::record_move(int row, int col, Player& player) {
  // if (player)
  // array_[row, col] = player;
  array_.at(row);
}

std::ostream& operator<<(std::ostream& os, const board& b) {
  os << "\n";
  os << " " << b(0, 0) << " | " << b(0, 1) << " | " << b(0, 2) << "\n";
  os << "---+---+---\n";
  os << " " << b(1, 0) << " | " << b(1, 1) << " | " << b(1, 2) << "\n";
  os << "---+---+---\n";
  os << " " << b(2, 0) << " | " << b(2, 1) << " | " << b(2, 2) << "\n\n";
  return os;
}

// TODO: Implement this function correctly
bool check_winner(const board& b, entry e) {
  // rows
  for (size_t i = 0; i < 3; i++){
    for (size_t j = 0; j < 3; j++){

      if (b(0,j) == e){

        return true;
      }
    }
  }

  /*if (b(0, 0) == e && b(0, 1) == e && b(0, 2) == e) {
    return true;
  } else if (b(1, 0) == e && b(1, 1) == e && b(1, 2) == e) {
    return true;
  } else if (b(2, 0) == e && b(2, 1) == e && b(2, 2) == e) {
    return true;
  }*/

  // columns

/*
  for (size_t i = 0; i < 3; i++){
    for (size_t j = 0; j < 3; j++){

      if(b(j,i) == e){
        return true;
      }
    }
  }
*/

  //else
  if (b(0, 0) == e && b(1, 0) == e && b(2, 0) == e) {
    return true;
  } else if (b(0, 1) == e && b(1, 1) == e && b(2, 1) == e) {
    return true;
  } else if (b(0, 2) == e && b(1, 2) == e && b(2, 2) == e) {
    return true;
  }

  // diagonals
/*

  for (size_t i = 0; i < 3; i++){

    if(b(i,i) == e){
      return true;
    }
  }
*/

   else if (b(0, 0) == e && b(1, 1) == e && b(2, 2) == e) {
   return true;

/*
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 3; j > 0; j++) {

      if (b(i, j) == e) {
        return true;
      }
    }
  }
*/

  } else if (b(0, 2) == e && b(1, 1) == e && b(2, 0) == e) {
    return true;
  }

  return false;
}

// TODO: Implement this function correctly
bool check_draw(const board& b, const entry e, const int  move_ctr) {

  if (check_winner(b, e) == false && move_ctr == 9){
    return false;
  }
}

bool is_valid_move(const board& b, const int row, const int col) {
  return b(row, col) == entry::empty;
}

}  // namespace tictactoe

// Player class
void Player::setName(std::string name_m) { name = name_m; }

void Player::setScore() { score++; }
int Player::getScore() { return score; }

tictactoe::entry Player::getType() { return token; }
void Player::setType(tictactoe::entry tokens) { token = tokens; }

