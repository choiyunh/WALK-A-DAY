#include <iostream>

int main() {
	int N, im, kim;
	int round = 1;

	std::cin >> N >> im >> kim;

	while ((im / 2 == kim / 2) || (im - kim != 1 && kim - im != 1)) {
		for (int i = 1; i <= N; i++) {
			if (i == im) {
				if (im % 2 == 1)
					im++;
				im /= 2;
			}

			if (i == kim) {
				if (kim % 2 == 1)
					kim++;
				kim /= 2;
			}

			if (i == N && N % 2 != 0)
				N++;
		}
		round++;
		N /= 2;
	}

	printf("%d\n", round);

	return 0;
}