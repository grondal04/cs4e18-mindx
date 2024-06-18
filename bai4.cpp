#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isSuperPrime(int n) {
    if (!isPrime(n)) return false;
    int lastDigitRemoved = n / 10;

    bool flag = true;
    while (n / 10) {
        n /= 10;
        if (!isPrime(n))
            return false;
    }

    return true;
}

vector<int> findSuperPrimes(int n) {
    vector<int> superPrimes;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            superPrimes.push_back(i);
        }
    }
    return superPrimes;
}

int main() {
    int n;
    cin >> n;

    vector<int> superPrimes = findSuperPrimes(n);

    for (int prime : superPrimes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
