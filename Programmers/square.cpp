#include <iostream>
using namespace std;

long long solution(int w, int h)
{	//w = 8, h = 12�� ���� ���簢�������� ���簢�� 96�� ��밡��(8*12)
	//�밢������ ������ �� 16���� ����� �� ����
	//���簢���� �� -> h��ŭ ������
	//���簢���� �� -> w*2��ŭ ������
	long long answer = 1;
	if (w == h)
		answer = (w * h) - h;
	else
		answer = (w * h) - (w * 2);
	return answer;
}

int main() {
	int w = 8;
	int h = 12;
	cout << solution(w, h) << endl;
	return 0;
}