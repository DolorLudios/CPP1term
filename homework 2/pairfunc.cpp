#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <string_view>
#include <utility>

template <typename Container>
typename std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairing(const Container& c) {
	std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairVec;
	using idtype = typename Container::size_type;
	typename Container::value_type zero{};

	for (idtype i = 0; i < c.size(); i += 2)
	{
		if (i + 1 < c.size()) {
			pairVec.push_back({ c[i], c[i + 1] });
		}

		if (i + 1 >= c.size()) {
			pairVec.push_back({ c[i], zero});
		}

	}

	return pairVec;
}

int main() {
	std::vector<std::string> v{ std::string("Cat"), std::string("Dog"), std::string("Mouse"), std::string("Lion"), std::string("Elephant")};
	std::array<int, 5> a{ 10,20,30,40,50 };
	std::vector<std::pair<char, char>> pairVec1 = pairing(std::string("Hello"));
	std::vector<std::pair<int, int>> pairVec2 = pairing(a);
	std::vector<std::pair<std::string, std::string>> pairVec3 = pairing(v);

	std::cout << "{";
	for (int i = 0; i < pairVec3.size(); i++)
	{
		std::cout << "{" << pairVec3[i].first << "," << pairVec3[i].second << "}" << ",";
	}
	std::cout << "}";


	return 0;
}
