#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <utility>
#include <list>

int main() {
	int n;
	int m;
	
	std::cin >> n;
	std::cin >> m;

	std::list<int> grunts;

	for (int i = 1; i < n + 1; i++)
	{
		grunts.push_back(i);
	}

	for (std::list<int>::iterator it = grunts.begin(); it != grunts.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	std::list<int>::iterator it = grunts.begin();
	while (grunts.size() != 1) {
		for (int i = 0; i < m - 1; i++)
		{
			it++;
			if (it == grunts.end()) {
				it = grunts.begin();
			}
		}
		std::cout << *it << " ";
		it = grunts.erase(it);
		if (it == grunts.end()) {
			it = grunts.begin();
		}

	}
	std::cout << std::endl;
	std::cout << grunts.back() << std::endl;
	
	return 0;
}
