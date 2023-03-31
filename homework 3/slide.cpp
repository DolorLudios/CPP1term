#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> vec(n);

	for (size_t i = 0; i < n; ++i )
		std::cin >> vec[i];

	std::vector<int>::iterator it = std::max_element(vec.begin(), vec.end());
	std::sort(vec.begin(), it);
	std::sort(it, vec.end());
	std::reverse(it, vec.end());

	for (size_t i = 0; i < n; i++)
	{
		std::cout << vec[i] << " ";
	}

	return 0;
	
}

