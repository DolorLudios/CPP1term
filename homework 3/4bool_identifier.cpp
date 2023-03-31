#include <iostream>
#include <string_view>
#include <cctype>
#include <algorithm>

bool isIdentifier(std::string_view s) {
	if (std::isdigit(s[0]))
		return false;
	if (std::all_of(s.begin(), s.end(), [](char c) {return (std::isalnum(c) || c == '_'); }))
		return true;
	else
		return false;
}

int main() {

	std::string_view s1 = "_name123";
	std::string_view s2 = "_nam-e123";
	std::string_view s3 = "1_name123";


	std::cout << std::boolalpha;

	std::cout << isIdentifier(s1) << std::endl;
	std::cout << isIdentifier(s2) << std::endl;
	std::cout << isIdentifier(s3) << std::endl;


	return 0;

}