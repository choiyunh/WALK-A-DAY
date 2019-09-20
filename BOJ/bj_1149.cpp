#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> d(1000, std::vector<int>(3, 0));
std::vector<std::vector<int>> m(1000, std::vector<int>(3, 0));

//0-R, 1-G, 2-B
int dp(int N, int c) {
	if (N == 0) return m[N][c] = d[N][c];
	if (m[N][c] != 0) return m[N][c];
	if (c == 0) return m[N][c] = std::min(dp(N - 1, 1), dp(N - 1, 2)) + d[N][c];
	if (c == 1) return m[N][c] = std::min(dp(N - 1, 0), dp(N - 1, 2)) + d[N][c];
	if (c == 2) return m[N][c] = std::min(dp(N - 1, 0), dp(N - 1, 1)) + d[N][c];
}	

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> d[i][j];
		}
	}

	int min[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		min[i] = dp(N - 1, i);
	}

	int ans = std::min(min[0], min[1]);
	ans = std::min(ans, min[2]);
	
	printf("%d\n", ans);
	   
	return 0;
}