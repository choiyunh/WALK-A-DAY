#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	string num;
	int flag = 1;
	for (int i = 123; i <= 987; i++) {
		num = to_string(i);
		if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2])
			continue;
		if (num[0] == '0' || num[1] == '0' || num[2] == '0')
			continue;

		// num과 baseball[j][0] 과 비교 한 글자씩 비교
		// 값 같고 인덱스도 같으면 S
		// 인덱스 다르면 B
		int S = 0, B = 0;
		flag = 1;
		for (size_t j = 0; j < baseball.size(); j++) {
			string num2 = to_string(baseball[j][0]);
			for (int k = 0; k < 3; k++) {
				for (int o = 0; o < 3; o++) {
					if (num2[k] == num[o]) {
						if (k == o) {
							S++;
							continue;
						}
						else {
							B++;
							continue;
						}
					}
				}
			}
			// 한 번이라도 S개수 B개수 안맞으면 그 수는 열외
			if (S != baseball[j][1] || B != baseball[j][2]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) // 모든 input을 만족할 때
			answer++;
	}
	return answer;
}

int main() {
	vector<vector<int>> v = { {123,2,0},{356,1,0},{327,2,0},{489,0,1} };
	
	printf("%d\n", solution(v));
	return 0;
}