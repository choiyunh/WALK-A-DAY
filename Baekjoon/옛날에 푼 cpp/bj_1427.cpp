#include <iostream>
#include <string>

int main() {
	std::string s;

	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int max = i;
		for (int j = i+1; j < s.length(); j++) {
			if (s[j] > s[max]) max = j;
		}
		int temp = s[i];
		s[i] = s[max];
		s[max] = temp;
	}

	printf("%s\n", s.c_str());
}
