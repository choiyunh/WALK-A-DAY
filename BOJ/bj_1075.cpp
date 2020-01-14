//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int getResult(int N_, int F_) {
//
//	int num = (N_ / 100) * 100;
//
//	for (int i = 0; i < 100; i++) {
//		if (num % F_ == 0) {
//			num %= 100;
//			break;
//		}
//		else
//			num++;
//	}
//
//	return num;
//}
//
//int main() {
//
//	int N, F;
//	int result;
//
//	cin >> N;
//	cin >> F;
//
//	result = getResult(N, F);
//
//	if (result < 10)
//		cout << '0';
//	cout << result << endl;
//
//	return 0;
//}

#include <iostream>

int main() {
	int N, F;
	std::cin >> N >> F;

	int temp = (N / 100) * 100;
	int ans = 0;

	for (temp; ; temp++) {
		if (temp % F == 0) {
			ans = temp % 100;
			break;
		}
	}

	if (ans < 10)
		printf("0");
	printf("%d\n", ans);

	return 0;
}
