#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
	int answer = 0; // 몇 번 인용했는지 0부터 증가
	int cnt = 0; // answer번 이상 인용된 논문의 갯수
	sort(citations.begin(), citations.end()); // 오름차순 정렬
	int n = citations.size(); // n
	while(1){
		for (int i = 0; i < n; i++) {  
			if (citations[i] >= answer) // answer번 이상 인용되었으면 cnt++
				cnt++;
		}
		if (answer > cnt) { // answer번 이상 인용된 논문이 answer개보다 적으면
			answer--; 
			break; // break
		}
		cnt = 0;
		answer++; // answer을 1씩 증가하면서 진행
	}
	return answer;
}
