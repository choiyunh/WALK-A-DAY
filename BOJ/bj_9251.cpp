#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	std::vector<std::vector<int>> dp(1000, std::vector<int>(1000, 0));
	s1 = '0' + s1;
	s2 = '0' + s2;

	for (int i = 1; i < s1.length(); i++) {
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	printf("%d\n", dp[s1.length()-1][s2.length()-1]);

	return 0;
}