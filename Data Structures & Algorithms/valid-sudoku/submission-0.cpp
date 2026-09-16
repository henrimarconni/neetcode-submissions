#include <cstring>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {

    bool row[10]{};
    bool boxes[3][3][10]{};
    bool cols[10][9]{};

    int x = 0;
    int y = 0;

    for (std::vector<char>& b_row : board) {
      for (char ch : b_row) {
        int code = ch == '.' ? -1 : ch - '0';
        if (code > 0) {
          if (row[code])
            return false;
          if (boxes[y / 3][x / 3][code])
            return false;
          if (cols[x][code])
            return false;
          row[code] = true;
          boxes[y / 3][x / 3][code] = true;
          cols[x][code] = true;
        }

        x++;
      }
     memset(row, 0, sizeof(bool) * 10);
      x = 0;
      y++;
    }
    
    return true;
  }
};
