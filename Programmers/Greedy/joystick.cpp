// joystcik.cpp
// Greedy Algorithm
// Created by Choiyunh

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
	int answer = 0;
	// N은 앞으로든 뒤로든 13번 이동
	// N 이전은 다음 알파벳 N이후는 이전 알파벳으로 찾아가는게 나음
	vector<char> alpha = { 'A','B','C','D','E','F','G','H','I','J','K','L', // 그냥 아스키코드로 하는게 편할려나
	   'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	vector<bool> check(name.length(), false); // 해당 위치를 바꿔야하는지 체크
	int cus = 0; // 커서의 위치
	int i = 1;
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < check.size(); i++) {
		if (name[i] == 'A') {
			check[i] = true;
			cnt++;
		}
	}

	// 첫 번째 위치 알파벳부터 바꾸고 시작
	if (!check[cus]) {
		for (j = 0; j < alpha.size(); j++) {
			if (name[cus] == alpha[j]) {
				if (name[cus] > 'N') {// N보다 큰 알파벳은 뒤로 이동
					j = alpha.size() - j;
				}
				break;
			}
		}
		answer += j;
		check[cus] = true;
		cnt++;
	}

	i = 1;
	j = 0;
	while (cnt < name.length()) {
		int right, left;
		right = cus + i; // 우측으로 i만큼씩 이동
		left = cus - i; // 좌측으로 i만큼씩 이동
		// 범위를 넘어가면
		if (right >= name.length())
			right -= name.length();
		if (left < 0)
			left += name.length();

		if (!check[right]) {
			answer += i;
			cus = right;
			i = 1; // 커서 이동하면 다시 좌우로 한칸씩 검사해야 되므로
			for (j = 0; j < alpha.size(); j++) {
				if (name[cus] == alpha[j]) {
					if (name[cus] > 'N') {// N보다 큰 알파벳은 뒤로 이동
						j = alpha.size() - j;
					}
					break;
				}
			}
			answer += j;
			check[cus] = true;
			cnt++;
			j = 0;
			continue;
		}
		else if (!check[left]) {
			answer += i;
			cus = left;
			i = 1;  // 커서 이동하면 다시 좌우로 한칸씩 검사해야 되므로
			for (j = 0; j < alpha.size(); j++) {
				if (name[cus] == alpha[j]) {
					if (name[cus] > 'N') {// N보다 큰 알파벳은 뒤로 이동
						j = alpha.size() - j;
					}
					break;
				}
			}
			answer += j;
			check[cus] = true;
			cnt++;
			j = 0;
			continue;
		}
		i++; // 좌 우로 한칸씩 늘려가며 검사
	}
	return answer;
}

int main() {
	//string name = "AABAAAAAAABBB";
	//string name = "JAZ";
	//string name = "ABABAAAAAAABA";
	string name = "BBAABB";
	printf("%d\n", solution(name));

	return 0;
}