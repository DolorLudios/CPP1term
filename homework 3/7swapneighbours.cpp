#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <utility>

template<typename Container>
void swapNeighbours(typename Container::iterator it1, typename Container::iterator it2) {
	
	typename Container::iterator i = it1;
	while((i+1) != it2 )
	{
		std::swap(*i, *std::next(i));
		i+=2;
	}

}
int main() {
	std::vector<int> vec{ 10,20,30,40,50 };
	swapNeighbours<std::vector<int>>(vec.begin(), vec.end());
	
	std::cout << "{";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << "}";

	return 0;
}