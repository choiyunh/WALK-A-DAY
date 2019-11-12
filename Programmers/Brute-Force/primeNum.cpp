#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

bool checkNum(int i, string numbers);

int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>()); // 내림차순 정렬
	int i_numbers = stoi(numbers);
	vector<bool> temp(i_numbers + 1, true);

	for (int i = 2; i <= i_numbers; i++) {
		if (temp[i] == true) {
			if (checkNum(i, numbers))
				answer++;			
			int j = i;
			while (j <= i_numbers) { // 배수들을 다 flase
				temp[j] = false;
				j += i;
			}
		}
	}

	return answer;
}

bool checkNum(int i, string numbers) {
	int flag = 0;
	// numbers 71 , i 11 일 때..
	while (i != 0) {
		int tmp = i % 10; // 숫자 하나씩
		flag = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (numbers[j] - '0' == tmp) {
				flag = 1;
				numbers.erase(j, 1);
				break;
			}
		}
		if (flag == 0) // flag가 0으로 나온 순간 return
			return false;
		i /= 10; 
	}
	return true;
}

int main() {
	string n = "011";
	vector<bool> temp(13);
	printf("%d\n", solution(n));

	return 0;
}
