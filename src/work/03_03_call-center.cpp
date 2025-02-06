#include <iostream>
#include <queue>
using namespace std;

// Call Center Class
class CallCenter {
private:
  queue<int> callLog;

public:
  void receive_call(const int id) {
    callLog.push(id);
    cout << "Call id: " << id << " recieved." << endl;
  }

  int process_call() {
    if (callLog.empty()) {
      cout << "The call queue is empty!" << endl;
      return -1;
    }
    cout << "Removing call: " << callLog.front() << " from the queue." << endl;
    callLog.pop();
    return 1;
  }
};

int main() {
  CallCenter center; // Instantiate CallCenter object

  // Receiving some calls
  center.receive_call(101);
  center.receive_call(102);
  center.receive_call(103);

  // Processing all calls
  int call_id;
  while ((call_id = center.process_call()) != -1) {
    std::cout << "Successfully processed call: " << call_id << std::endl;
  }

  return 0;
}