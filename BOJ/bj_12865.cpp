#include<iostream>
#include<algorithm>

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main() {


	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) {
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	printf("%d\n", dp[n][k]);
}
