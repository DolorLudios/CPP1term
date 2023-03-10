#include <iostream>
#include <utility>
#include <vector>

template <typename T>
T max(const std::vector<T>& v) {
    T result{ v[0] };

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > result)
            result = v[i];
    }

    return result;
}


int main()
{
    std::vector<int> v1{ 10, 20, 30, 40, 50 };
    std::vector<float> v2{ 1.5, 6.1, -0.5, 2.4, -4.7 };
    std::vector<std::string> v3{ "Cat", "Dog", "Mouse", "Elephant" };
    std::vector < std::pair<int, int>> v4{ {3,3}, {5,1}, {17,1}, {29,1}, {97,2} };

    std::cout << max(v1) << std::endl;
    std::cout << max(v2) << std::endl;
    std::cout << max(v3) << std::endl;
    std::cout << "{" << max(v4).first << "," << max(v4).second << "}" << std::endl;

    return 0;

}