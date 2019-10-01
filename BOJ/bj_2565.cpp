#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::pair<int, int> line[501];
	int max, dp[101];

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> line[i].first >> line[i].second;
		dp[i] = 1;
	}
	
	std::sort(line, line + n + 1);

	max = dp[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (line[i].second > line[j].second && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", n - max);
	

	return 0;
}