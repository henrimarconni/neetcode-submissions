#include <cstddef>
#include <cstring>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    bool row[10]{};
    bool cols[9][10]{};
    bool boxes[3][3][10]{};

    for (size_t y = 0; y < 9; y++) {
      for (size_t x = 0; x < 9; x++) {
        int code = board[y][x] == '.' ? -1 : board[y][x] - '0';

        if (code < 0)
          continue;

        if (row[code] || cols[x][code] || boxes[x / 3][y / 3][code])
          return false;

        row[code] = true;
        cols[x][code] = true;
        boxes[x / 3][y / 3][code] = true;
      }
      memset(row, 0, sizeof(bool) * 10);
    }

    return true;
  }
};
