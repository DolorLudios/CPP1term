#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

void spaceShift1(std::string& s) {
	std::stable_partition(s.begin(), s.end(), [](char c) {return !std::isspace(c); });
}
void spaceShift2(std::string& s) {
	auto it = std::copy_if(s.begin(), s.end(), s.begin(), [](char c) {return !std::isspace(c); });
	std::fill(it, s.end(), ' ');
}

int main() {
	std::string s1 = "cats and dogs cats and dogs";
	spaceShift1(s1);
	std::string s2 = "cats and dogs cats and dogs";
	spaceShift2(s2);
	std::cout << "{" << s1 << "}" << std::endl;
	std::cout << "{" << s2 << "}" << std::endl;

	return 0;
}

