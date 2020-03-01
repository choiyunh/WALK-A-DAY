#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int curWeight = 0;
	int i = 0;

	while (1) {
		if (q.size() == bridge_length) { // �ٸ��� ���� Ʈ���� �������� �� pop
			curWeight -= q.front();
			q.pop();
		}
		answer++; // �� Ʈ���̵� 0�̵� push�ϸ� �ð��� ������ answer++
		if (curWeight + truck_weights[i] <= weight) {// ���� ���Կ� �� Ʈ���� ���Ը� ������ �� �ߵ� �� ������ (���� ���� �۰ų� !!������!!)
			curWeight += truck_weights[i]; // ���� ���Ը� �����ְ�
			q.push(truck_weights[i++]); // �� Ʈ���� push�� �� i++
			
			if (i == truck_weights.size()) { // ������ Ʈ���� �ٸ��� �ö����� bridge_length�� �����ְ� ��
				answer += bridge_length;
				break;
			}
		}
		else { // �� Ʈ���� �ߵ� �� ������ 0�� push
			q.push(0);
		}		
	}
	return answer;
}

int main() {
	int bl =100;
	int w = 100;
	vector<int> t_w = {10,10,10,10,10,10,10,10,10,10};
	//vector<int> t_w = { 7,4,5,6 };

	printf("%d\n", solution(bl, w, t_w));
	return 0;
}