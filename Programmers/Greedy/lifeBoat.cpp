#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	
	// people을 내림차순 정렬 후
	// 맨 앞과 뒤를 더해서 limit보다 작으면 두 명 태움(answer++, cnt+=2)
	// i++ j--
	// limit보다 크면 한 명 태움(answer++, cnt++) i++
	sort(people.begin(), people.end(), greater<int>());
	
	int i = 0;
	int j = people.size() - 1;
	int cnt = 0;
	while (cnt < people.size()) {
		if (people[i] + people[j] <= limit) { // 두 명 태움
			answer++;
			cnt += 2;
			j--;
		}
		else {
			answer++;
			cnt++;
		}
		i++;
	}
	return answer;
}

int main() {
	//vector<int> p = { 10,20,30,50 }; // 50 30 20 10
	vector<int> p = { 70,50,80,50 };
	int l = 100;

	printf("%d\n", solution(p, l));
	return 0;
}