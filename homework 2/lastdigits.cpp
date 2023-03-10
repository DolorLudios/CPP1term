#include <iostream>
#include <vector>
#include <span>

std::vector<int> lastDigits1(const std::vector<int>& v) {
	std::vector<int> vector;

	for (int i = 0; i < v.size(); ++i)
	{
		vector.push_back(v[i] % 10);
	}

	return vector;
}

void lastDigits2(std::vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] %= 10;
	}

}

void lastDigits3(std::vector<int>* pv) {

	for (int i = 0; i < pv->size(); i++)
	{
		(*pv)[i] %= 10;
	}
}

void lastDigits4(std::span<int> sp) {
	for (int i = 0; i < sp.size(); i++)
	{
		sp[i] %= 10;
	}
}

int main() {
	std::vector<int> v = { 56, 43, 7695234 };
	lastDigits3(&v);

	for (int i = 0; i < v.size(); i++) 
	{
		std::cout << v[i] << ' ';
	}

	return 0;
}
