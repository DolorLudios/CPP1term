#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> factorization(int n) {
    std::vector<std::pair<int, int>> factors;
    int factor = 2;
    while (n > 1) {
        int i = 0;
        while (n % factor == 0) {
            ++i;
            n /= factor;
        }
        if (i > 0) {
            factors.push_back({ factor, i });
        }
        ++factor;
        if (factor * factor > n && n > 1) {
            factors.push_back({ n, 1 });
            break;
        }
    }
    return factors;
}

int main() {

    int n = 626215995;
    std::vector<std::pair<int, int>> factors = factorization(n);

    std::cout << "{";
    for (int i = 0; i < factors.size(); ++i) {
        std::cout << "{" << factors[i].first << "," << factors[i].second << "}" << ",";
    }
    std::cout << "}" << std::endl;

    return 0;
}





