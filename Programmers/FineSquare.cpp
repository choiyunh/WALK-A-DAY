#include <iostream>

using namespace std;

long long solution(int w, int h) {
	long long answer = 0;

	long long w_ = w;
	long long h_ = h;

	for (int y = 1; y < h; y++)
		answer += (long long)((w_ * h_) - (w_ * y)) / h_;

	return answer * 2;
}