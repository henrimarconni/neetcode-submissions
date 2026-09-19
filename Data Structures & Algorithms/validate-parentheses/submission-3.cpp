#include <cassert>
#include <string>
#include <vector>
using string = std::string;

class Solution {
public:
  bool isLParen(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
  }
  bool isRParen(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
  }
  bool isConjugatable(char ch) {
    if (ch == ')')
      return true;
    if (ch == '}')
      return true;
    if (ch == ']')
      return true;

    return false;
  }
  char conjugate(char ch) {
    if (ch == ')')
      return '(';
    if (ch == '}')
      return '{';
    if (ch == ']')
      return '[';
    assert(false);
  }
  bool isValid(string s) {
    std::vector<char> stack;

    for (char ch : s) {
      if (isLParen(ch))
        stack.push_back(ch);
      else if (isRParen(ch) && stack.size() == 0) {
        return false;
      }
      else if (isRParen(ch) && !isConjugatable(ch)) {
        return false;
      }
      else if (isRParen(ch) && stack.back() != conjugate(ch)) {
        return false;
      }
      else if (isRParen(ch))
        stack.pop_back();
    }

    return stack.empty();
  }
};
