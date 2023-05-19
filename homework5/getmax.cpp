#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>

uint64_t findMax(const std::vector<uint64_t>& v, size_t start, size_t end) {
    uint64_t max = v[start];
    for (size_t i = start + 1; i < end; ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

uint64_t getMax(int n, const std::vector<uint64_t>& v) {
    auto size = v.size();
    int elementsInThread = size / n;

    std::vector<std::thread> threads;
    std::vector<uint64_t> maxValues(n, 0);
    std::mutex mutex;
    size_t end;

    for (int i = 0; i < n; ++i) {
        size_t start = i * elementsInThread;
        if (i == n - 1)
            end = size;
        else
            end = start + elementsInThread;

             
        threads.emplace_back([start, end, &v, &maxValues, i, &mutex]() {
            maxValues[i] = findMax(v, start, end);
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return *std::max_element(maxValues.begin(), maxValues.end());
}

int main() {
        std::cout << "Generating numbers!" << std::endl;
        std::vector<uint64_t> numbers(5e8);
        numbers[0] = 123456789;
        for (size_t i = 1; i < numbers.size(); ++i)
        {
            numbers[i] = numbers[i - 1] * i + 1;
        }
        std::cout << "Numbers generated!" << std::endl;

        int n;
        std::cin >> n;

        auto start = std::chrono::high_resolution_clock::now();

        uint64_t m = getMax(n, numbers);
        std::cout << "Maximum = " << m << std::endl;


        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << " milliseconds." << std::endl;

        auto start1 = std::chrono::high_resolution_clock::now();

        auto maxIter1 = getMax(1, numbers);
        std::cout << "Maximum = " << *maxIter1 << std::endl;


        auto end1 = std::chrono::high_resolution_clock::now();
        std::cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
            << " milliseconds." << std::endl;


        return 0;
}