#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> t(500, std::vector<int>(500, 0));
std::vector<std::vector<int>> d(500, std::vector<int>(500, 0));

int dp(int n, int i) {
	if (n == 0) return t[n][i];
	if (d[n][i] != 0) return d[n][i];
	return d[n][i] = std::max(dp(n - 1, i), dp(n - 1, i + 1)) + t[n][i];
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			std::cin >> t[n-i][j];
		}
	}

	printf("%d\n", dp(n-1,0));

	return 0;
}