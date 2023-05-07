#include <iostream>
#include <string>
#include <set>

int main() {
	int n;
	std::cin >> n;

	int k;
	std::cin >> k;

	std::set<int> rope{ 0 , n };
	std::multiset<int> lengths{ n };

	for (int i = 0; i < k; ++i)
	{
		int	slice;
		std::cin >> slice;
		rope.insert(slice);

		std::set<int>::iterator it = rope.find(slice);
		int left = *std::prev(it);
		int right = *std::next(it);

		lengths.erase(right - left);
		lengths.insert(slice - left);
		lengths.insert(right - slice);

		std::cout << *std::prev(lengths.end());
	}

	return 0;
}







