#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void reverseString(std::vector<std::string>& vec) {

	std::reverse(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::reverse(vec[i].begin(), vec[i].end());
	}
}

int main() {
	std::vector<std::string> vec{ "cat","dog","mouse","elephant" };
	reverseString(vec);

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
}