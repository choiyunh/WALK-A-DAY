#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string s1, s2;
	int num1, num2;
	std::cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	num1 = stoi(s1);
	num2 = stoi(s2);

	if (num1 >= num2)
		printf("%d\n", num1);
	else
		printf("%d\n", num2);
	
}

