#include <iostream>
#include <queue>
using namespace std;

class MerchOrderSystem {
private:
  queue<int> regular;
  queue<int> priority;

public:
  void place_order(int orderID, bool isPriority = false) {
    if (isPriority) {
      priority.push(orderID);
      cout << "Order [Priority " << orderID << "] has been placed." << endl;
    } else {
      regular.push(orderID);
      cout << "Order [Regular" << orderID << "] has been placed." << endl;
    }
  }

  int fulfill_order() {
    if (!priority.empty()) {
      int curr = priority.front();
      cout << "Fulfilling order [Priority " << curr << "]" << endl;
      priority.pop();
      return curr;
    } else if (!regular.empty()) {
      int curr = regular.front();
      cout << "Fulfilling order [Regular " << curr << "]" << endl;
      regular.pop();
      return curr;
    } else {
      cout << "There are no orders!" << endl;
      return -1;
    }
  }
};

int main() {
  MerchOrderSystem system; // Instantiate MerchOrderSystem object

  // Placing some orders
  system.place_order(201);       // Regular order
  system.place_order(202);       // Regular order
  system.place_order(101, true); // Priority order
  system.place_order(203);       // Regular order

  // Fulfilling all orders
  int orderID;
  while ((orderID = system.fulfill_order()) != -1) {
    cout << "Order with ID " << orderID << " has been fulfilled.\n";
  }

  return 0;
}