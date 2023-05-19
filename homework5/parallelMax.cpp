#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <cstdint>



template <typename RandIt>
RandIt findMax(RandIt start, RandIt finish)
{
    RandIt maxIt = start;
    for (auto it = start; it != finish; ++it)
    {
        if (*it > *maxIt)
            maxIt = it;
    }
    return maxIt;
}

template <typename RandIt>
RandIt getMax(int n, RandIt start, RandIt finish) {
    size_t size = std::distance(start, finish);
    int elementsInThread = size / n;

    std::vector<std::thread> threads;
    std::vector<RandIt> maxIters(n);

    for (int i = 0; i < n; ++i)
    {
        RandIt threadStart = start + (i * elementsInThread);
        RandIt threadFinish;

        if (i == n - 1)
            threadFinish = finish;
        else
            threadFinish = threadStart + elementsInThread;

        threads.emplace_back([threadStart, threadFinish, &maxIters, i]() {
            maxIters[i] = findMax(threadStart, threadFinish);
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return *std::max_element(maxIters.begin(), maxIters.end(), [](RandIt iter1, RandIt iter2) { return *iter1 < *iter2; });
}

int main() {
    std::cout << "Generating numbers!" << std::endl;
    std::vector<uint64_t> numbers(5e7);
    numbers[0] = 123456789;
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        numbers[i] = numbers[i - 1] * i + 1;
    }
    std::cout << "Numbers generated!" << std::endl;

    int n;
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();

    auto maxIter = getMax(n, numbers.begin(), numbers.end());
    std::cout << "Maximum = " << *maxIter << std::endl;


    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " milliseconds." << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();

    auto maxIter1 = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Maximum = " << *maxIter1 << std::endl;


    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
        << " milliseconds." << std::endl;


    return 0;
}