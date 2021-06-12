#include <iostream>

int main() {
	int a[1001], dp1[1001], dp2[1001];
	int n, max;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		dp1[i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dp1[j] >= dp1[i]) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) 
		dp2[i] = 1;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (a[j] < a[i] && dp2[j] >= dp2[i]) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	max = dp1[1] + dp2[1] - 1;
	for (int i = 2; i <= n; i++) {
		if (max < dp1[i] + dp2[i] - 1)
			max = dp1[i] + dp2[i] - 1;
	}
	printf("%d\n", max);
	return 0;
}