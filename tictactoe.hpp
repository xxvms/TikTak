
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <iosfwd>
#include <ostream>

namespace tictactoe {

class Player;

  enum class entry { empty, nought, cross };

/// Prints the entry to the given output stream
/// Prints " " for empty, "O" for nought and "X" for cross
std::ostream &operator<<(std::ostream &os, entry e);

/// A class representing a noughts-and-crosses (aka tic-tac-toe) board
///
/// The board consists of 9 cells arranged in a 3x3 grid. Each cell
/// is either empty or filled with an X or a O, represented by the `entry`
/// enumeration.
///
class board {
 public:
  /// Default constructs an empty `board` with each cell set to entry::empty
  board();

  /// Returns a copy of the entry in the given row and column
  /// Throws std::out_of_range if either argument is not in the range [0, 2]
  entry operator()(int row, int col) const;

  /// Returns a reference to the entry in the given row and column
  /// Throws std::out_of_range if either argument is not in the range [0, 2]
  entry &operator()(int row, int col);

  /// Returns an iterator to the start of the board's cell range
  /// This iterates over the cells in COLUMN-MAJOR order
  auto begin() const { return array_.begin(); }

  /// Returns an iterator to the end of the board's cell range
  auto end() const { return array_.end(); }

  // add move to the grid
  void record_move(int row, int col, Player &player);

 private:
  std::array<entry, 9> array_;
};

/// Prints the board as a 3x3 grid to the given output stream
std::ostream &operator<<(std::ostream &os, const board &b);

/// Returns true if the given player token (nought or cross) has won the game
// (You must implement this function in tictactoe.cpp)
bool check_winner(const board &b, entry e);

/// Returns true if the game has ended in a draw
// (You must implement this function in tictactoe.cpp)
bool check_draw(const board & b, const entry e, const int move_ctr);

bool is_valid_move(const board &b, const int row, const int col);
}  // namespace tictactoe

class Player {
 private:
  std::string name;
  int score;
  tictactoe::entry token;

 public:
  Player() : score(0) {}
  void setName(std::string name_);

  void setType(tictactoe::entry tokens);
  tictactoe::entry getType();

  void setScore();
  int getScore();
};

#endif  // TICTACTOE_HPP
