#include <iostream>

int main() {
	int N, cnt = 0;
	int kim, im;

	std::cin >> N >> kim >> im;

	while (kim != im) {
		cnt++;
		kim = kim / 2 + kim % 2;
		im = im / 2 + im % 2;
	}

	printf("%d\n", cnt);
	return 0;

}