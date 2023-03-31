#include <iostream>
#include <string_view>
#include <algorithm>
#include <cctype>

bool uppercaseDetector(std::string_view s) {

	if (std::any_of(s.begin(), s.end(), [](char c) {return (!std::isupper(c) && std::isalpha(c)) ;}))
		return false;	
	else
		return true;
}

int main() {

	std::string_view s1 = "CATS aND !!DOGS21!";
	std::string_view s2 = "CATS AND !!DOGS21!";

	std::cout << std::boolalpha;

	std::cout << uppercaseDetector(s1) << std::endl;
	std::cout << uppercaseDetector(s2) << std::endl;

}