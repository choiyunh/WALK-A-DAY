#include <iostream>
#include <algorithm>

int score[300];
int d[300];

int dp(int i) {
	if (i == 0) return score[i];
	if (i == 1) return std::max(score[i], score[i] + score[i - 1]);
	if (i == 2) return std::max(score[i - 2] + score[i], score[i - 1] + score[i]);
	if (d[i] != 0) return d[i];
	return d[i] = std::max(dp(i - 3) + score[i - 1], dp(i - 2)) + score[i];
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> score[i];
	}

	printf("%d\n", dp(n-1));

	return 0;
}