#include <cstdint>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    uint16_t rows[10]{};
    uint16_t cols[10]{};
    uint16_t boxes[10]{};

    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[x][y] == '.')
          continue;

        // 00001000 0_____ => 9 bits, 1 per square
        int mask = 1 << (board[x][y] - '0');
        int b = x / 3 + (y / 3) * 3;

        if ((rows[x] & mask) || (cols[y] & mask) || (boxes[b] & mask))
          return false;

        rows[x] |= mask;
        cols[y] |= mask;
        boxes[b] |= mask;
      }
    }
    return true;
  }
};
