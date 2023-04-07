#include <iostream>
#include <string>
#include <set>

int main() {
	int n;
	std::cin >> n;

	int k;
	std::cin >> k;

	std::set<int> rope{ 0 , n };

	for (int i = 0; i < k; ++i)
	{	
		int	slice;
		std::cin >> slice;
		rope.insert(slice);

		std::set<int>::iterator it = rope.find(slice);
		int left = *std::prev(it); 
		int right = *std::next(it); 
		
		int maxSlice = std::max(slice - left, right - slice);
		
		std::cout << maxSlice << std::endl;
	}

	return 0;
}