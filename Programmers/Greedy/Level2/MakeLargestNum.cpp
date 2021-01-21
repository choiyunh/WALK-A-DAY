#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	string temp = number;
	int flag = 0;
	// 첫 인덱스부터 자신과 다음 수 비교해서 작으면 삭제 후 k--;
	// 삭제하면 다시 첫 인덱스부터 반복
	while (k > 0) {
		int i = 0;
		flag = 0;
		for (i = 0; i < number.length() - 1; i++) {
			if (number[i] < number[i + 1]) { // 내가 다음 수보다 작으면 삭제
				number.erase(i, 1);
				k--;
				flag = 1;
				break;
			}
		}
		if (flag == 0 && k > 0) { // 다 검사했으나 k가 남았을 때
			number.erase(number.end()-1);
			k--;
		}
	}
	return number;
}