#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {

  if (n < 2) {
    return false;
  }

  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      return false;
    }
  }

  return true;
}

void findPrimes(const int arr[], size_t size, std::vector<int> &primes) {
  // TODO: Implement
  // Sieve of Eratosthenes
  for (int i = 0; i < size; i++) {
    if (isPrime(arr[i])) {
      primes.push_back((arr[i]));
    }
  }
}

int main() {
  int numbers[]{4, 7, 12, 3, 9, 17, 29};

  size_t size = sizeof(numbers) / sizeof(numbers[0]);
  vector<int> primes;

  findPrimes(numbers, size, primes);

  if (primes.empty()) {
    cout << "No prime numbers found in the array.";
  } else {
    cout << "The prime numbers in the array are:";
    for (int prime : primes) {
      cout << " " << prime;
    }
    cout << endl;
  }
  return 0;
}
