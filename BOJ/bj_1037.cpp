#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num;
	std::vector<int> v;

	std::cin >> num;

	for (int i = 0; i < num; i++) {
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());

	printf("%d\n", v.front()*v.back());

	return 0;
}