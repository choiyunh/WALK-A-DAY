#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	// 진입 지점 기준으로 오름차순 정렬
	sort(routes.begin(), routes.end());

	// 제일 먼저 진입하는 차의 진출지점에 카메라를 설치하는 걸로 가정하고
	// 그 다음 진입 차들의 진출지점이 카메라설치 위치보다 빠르면
	// 그 작은 점에 설치하면 최소로 설치 가능
	// 만약 카메라 위치보다 늦게 진입하는 차가 있으면 
	// 그 차의 진출위치에 추가 설치
	answer++;
	int camLoc = routes[0][1];
	for (int i = 0; i < routes.size(); i++) {
		if (routes[i][1] < camLoc) {
			camLoc = routes[i][1];
		}
		if (routes[i][0] > camLoc) {
			answer++;
			camLoc = routes[i][1];
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> v = { {-20,15},{-14,-5},{-18,-13},{-5,-3} };

	printf("%d\n", solution(v));
	return 0;
}