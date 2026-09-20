#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
class MinStack {
public:
  int* data;
  int* mins;
  int len;
  int size;
  int min;
 
  MinStack() {
    data = (int*)malloc(sizeof(int) * 1024);
    mins = (int*)malloc(sizeof(int) * 1024);
    len = 0;
    min = INT_MAX;
    size = 1024;
  }

  void push(int val) {
    while (size <= len + 1) {
      data = (int*)realloc(data, sizeof(int) * size * 2);
      mins = (int*)realloc(mins, sizeof(int) * size * 2);
      size *= 2;
    }
    data[len] = val;
    mins[len] = min;
    min = std::min(min, val);
    len++;
  }

  void pop() {
    assert(len > 0);
    min = mins[len - 1];
    len--;
  }

  int top() {
    return data[len - 1];
  }

  int getMin() {
    return min;
  }
};
