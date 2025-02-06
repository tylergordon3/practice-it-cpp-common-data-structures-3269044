#include <iostream>
#include <list>
using namespace std;

// Track stops in doubly linked list
class Route {
private:
  list<string> stops;
  list<string>::iterator current;

public:
  Route() { current = stops.end(); }

  // Add new stop to route
  void add_stop(const string &stop) {
    stops.push_back(stop);
    if (current == stops.end()) {
      current = stops.begin();
    }
  }

  // Advance to next stop
  void next_stop() {
    if (current == stops.end()) {
      current = stops.begin();
      return;
    }
    current++;
  }

  // Goes back to previous shop
  void prev_stop() {
    if (current == stops.begin()) {
      current = stops.end();
      return;
    }
    current--;
  }

  // Display current stop
  void current_stop() { cout << "Current stop is " << *current << endl; }
};

int main() {
  Route route;

  route.add_stop("Los Angeles");
  route.add_stop("Las Vegas");
  route.add_stop("Salt Lake City");
  route.add_stop("Denver");

  route.current_stop(); // "Current stop: Los Angeles"
  route.next_stop();
  route.current_stop(); // "Current stop: Las Vegas"
  route.next_stop();
  route.current_stop(); // "Current stop: Salt Lake City"
  route.next_stop();
  route.current_stop(); // "Current stop: Denver"
  route.prev_stop();
  route.current_stop(); // "Current stop: Salt Lake City"

  return 0;
}