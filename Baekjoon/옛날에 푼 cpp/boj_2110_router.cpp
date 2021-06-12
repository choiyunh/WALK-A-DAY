#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int N, C; // 집의 갯수, 공유기 갯수
	vector<int> house; // 집의 좌표
	cin >> N >> C;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(), house.end()); //좌표 오름차순 정렬

	int left = 1;
	int right = house[N - 1] - house[0]; // 최대 거리

	int mid;
	int cnt, ans;
	// 이분탐색
	while (left <= right) {
		mid = (left + right) / 2; // 가장 인접한 것들 사이의 거리
		int start = house[0];
		cnt = 1;
		for (int i = 1; i < N; i++) {
			if ((house[i] - start) >= mid) {// house[i]에 설치
				cnt++; // 공유기 갯수 증가
				start = house[i];
			}
		}

		if (cnt >= C) {// 공유기를 C개 이상 설치 가능하면 간격을 넓혀보기(mid크게)
			ans = mid;
			left = mid + 1;
		}
		else { // 아니면 간격을 좁혀보기
			right = mid - 1;
		}
	}

	printf("%d\n", ans);


	return 0;
}