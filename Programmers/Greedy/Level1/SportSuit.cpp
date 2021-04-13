#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	int cnt = 0; // 체육복을 도난 당했지만 수업을 들을 수 있는 수
	int lostNum = lost.size();

	// 도난당했지만 안빌려도 되는 사람을 먼저 체크해서
	// lost와 rserve배열에서 제거
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				cnt++;
				i--; // lost.earse 했으므로 i--
				break;
			}
		}
	}
	// 다른 사람에게 빌려야 하는 사람 체크
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			// 앞 사람부터 체크( 뒷 사람은 뒷뒷사람한테도 빌려줄 수 있기 때문에)
			// 앞에서 빌릴 수 있으면 빌리고 break;
			if (reserve[j] == lost[i] - 1) {
				cnt++;
				reserve.erase(reserve.begin() + j);
				break;
			}
			// 앞 사람한테 못 빌리면 뒷사람한테 빌리기
			if (reserve[j] == lost[i] + 1) {
				cnt++;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
	}
	
	answer -= (lostNum - cnt);
	return answer;
}

int main() {
	int n = 5;
	vector<int> l = { 2,3,4 };
	vector<int> r = { 3,4,5 };

	printf("%d\n", solution(n, l, r));
	return 0;
}