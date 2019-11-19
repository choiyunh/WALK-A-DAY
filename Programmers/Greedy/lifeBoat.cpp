#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	
	// people을 내림차순 정렬 후
	// limit - people[0]이 40보다 작으면 answer++, erase
	// 40보다 크면 탐색 후 같이 erase , answer++
	// people이 빌 때까지 반복
	sort(people.begin(), people.end(), greater<int>());

	int i = 0;
	// erase쓰니까 효율성 X
	// i부터 배타고 간사람은 0으로 표시
	while (i<people.size()) {
		// 40보다 작거나 240보다 크면 고려 X (이미 떠난 사람 0)
		if (people[i] < 40 || people[i]>240) {
			i++;
			continue;
		}
		// max는 나와 같이 배에 탈 수 있는 무게의 최대값
		int max = limit - people[i];
		// 사람의 최소 몸무게가 40이기 때문에
		// 어차피 혼자 가야댐
		if (max < 40) {
			answer++;
			people[i++] = 0;
		}
		// 더 태울 수 있으면
		else {
			int flag = 0;
			for (size_t j = i + 1; j < people.size(); j++) {
				// people[j]가 0인경우는 이미 앞에서 누가 데려간 것
				// max보다 가벼운 사람이 있다면
				if (people[j] <= max && people[j] >= 40) {
					people[i++] = 0;
					people[j] = 0;
					flag = 1;
					answer++;
					break;
				}
			}
			// 태울 수 있는 무게의 사람이 없다면 혼자가
			if (flag == 0) {
				people[i++] = 0;
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> p = { 10,20,30,50 };
	int l = 100;

	printf("%d\n", solution(p, l));
	return 0;
}