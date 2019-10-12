#include <iostream>
using namespace std;
int n, heap[10000001];

void heapify(int i)
{
	int cur = 2 * i;

	if (cur < n && heap[cur] < heap[cur + 1]) cur++;

	if (heap[i] < heap[cur])
	{
		swap(heap[i], heap[cur]);
		if (cur <= n / 2) heapify(cur);
	}
}

void heapsort(int i)
{
	swap(heap[1], heap[i]);

	int root = 1;
	int cur = 2;

	while (cur / 2<i)
	{
		cur = 2 * root;
		if (cur < i - 1 && heap[cur] < heap[cur + 1]) cur++;
		if (cur < i && heap[root] < heap[cur])
			swap(heap[root], heap[cur]);

		root = cur;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> heap[i];

	for (int i = n / 2; i > 0; i--) // 최초 heap 생성
		heapify(i);

	for (int i = n; i > 0; i--) // heap 정렬
		heapsort(i);

	for (int j = 1; j <= n; j++) // 출력
		printf("%d ", heap[j]);
}