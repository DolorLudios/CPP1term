#include <iostream>
#include <map>

int main() {
	int n;
	std::cin >> n;

	std::map <int, int> numMap;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;

		if (numMap.contains(num)) {
			numMap[num]++;
		}
		else {
			numMap.insert(std::pair<int, int>(num, 1));
		}
	}
	for (auto it = numMap.begin(); it != numMap.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	return 0;
}