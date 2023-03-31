#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>

template <typename Container>
typename Container::value_type maxElement(typename Container::iterator it1, typename Container::iterator it2) {
	typename Container::value_type max = *it1;
	for (typename Container::iterator i = it1; i < it2 ; ++i)
	{
		if (*i > max)
			max = *i;
	}

	return max;
}

int main() {
	std::vector<int> vec{ 1, 10 ,20 ,3,15,9 };

	std::cout << maxElement<std::vector<int>>(vec.begin(), vec.end()) << std::endl;
}