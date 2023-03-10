#include <iostream>
#include <vector>
using namespace std;

int sumEven(const std::vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0) {
            sum += vec[i];
        }
    }

    return sum;
}

int main() {
    
    std::vector<int> vec{ 10, 20, 30, 40, 50 };
    
    std::cout << (sumEven(vec));

    return 0;
}
