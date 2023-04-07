#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

int main() {
	std::string brackets;
	std::cin >> brackets;

	std::stack<char> stackbrack;

	for (auto bracket : brackets)
	{
		if (bracket == '}' && stackbrack.top() == '{')
			stackbrack.pop();
		else if (bracket == ')' && stackbrack.top() == '(')
			stackbrack.pop();
		else if (bracket == ']' && stackbrack.top() == '[')
			stackbrack.pop();
		else
			stackbrack.push(bracket);
	}

	if (stackbrack.empty()) {
		std::cout << "Yes" << std::endl;
	}
	else
		std::cout << "No" << std::endl;
	
	return 0;
}