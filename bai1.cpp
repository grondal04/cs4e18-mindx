#include <iostream>
#include <cmath>
#include <vector>

long long divisorsSum(int n) {
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) sum += i;
    }

    return sum;
}

int main() {
    int T;
    std::cout << "Nhap so luong test case: ";
    std::cin >> T;

    std::vector<long long> numbers(T);
    std::cout << "Nhap cac so nguyen duong:" << std::endl;
    for (int i = 0; i < T; i++) {
        std::cin >> numbers[i];
    }

    std::cout << "Ket qua:" << std::endl;
    for (int i = 0; i < T; i++) {
        std::cout << divisorsSum(numbers[i]) << std::endl;
    }

    return 0;
}
