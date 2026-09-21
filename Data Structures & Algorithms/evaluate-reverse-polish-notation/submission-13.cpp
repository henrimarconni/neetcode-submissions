#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using string = std::string;

class Solution {
public:
  bool isOp(string &s) {
    return s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
  }
  int apply(int a, int b, string &op) {
    switch (op[0]) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      assert(false);
    }
  }
  int evalRPN(std::vector<string> &tokens) {
    std::stack<int> stack;

    for (string &s : tokens) {
      if (isOp(s)) {
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        int res = apply(a, b, s);
        stack.push(res);
      } else
        stack.push(std::stoi(s));
    }

    return stack.top();
  }
};