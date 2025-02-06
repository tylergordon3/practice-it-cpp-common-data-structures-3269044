#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
  string rev = "";
  stack<char> stack;

  for (int i = 0; i < str.length(); i++) {
    stack.push(str[i]);
  }

  for (int i = stack.size(); i > 0; i--) {
    rev += stack.top();
    stack.pop();
  }

  return rev;
}

int main() {
  cout << reverseString("Hello, World!") << endl;
  return 0;
}