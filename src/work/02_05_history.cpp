#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Create a program that allows fetching the current website's URL and
// navigating back to previously visited sites.

// Implement a class named BrowserHistory
// Uses a stack to track websites

class BrowserHistory {
private:
  stack<string> history;

public:
  void visit(const string &url) {
    history.push(url);
    cout << "Visiting: " << url << endl;
  }

  void back() {
    if (history.empty()) {
      cout << "History is empty." << endl;
      return;
    }
    cout << "Going back. " << endl;
    history.pop();
  }

  string current() const {
    if (history.empty()) {
      return "Not viewing a website currently.";
    }
    return history.top();
  }
};

int main() {
  BrowserHistory bh;

  bh.visit("explorecalifornia.org");
  bh.visit("pixelford.com");
  bh.visit("landonhotel.com");

  cout << "Current Site: " << bh.current() << endl;

  bh.back();
  cout << "Current Site: " << bh.current() << endl;

  bh.back();
  cout << "Current Site: " << bh.current() << endl;

  bh.back();
  cout << "Current Site: " << bh.current() << endl;

  return 0;
}