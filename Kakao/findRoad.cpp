#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<iostream>
#define MAX 1e5+1

using namespace std;

class Node {
public:
	int value;
	Node* left = NULL;
	Node* right = NULL;
	Node(int value) { this->value = value; }
};

// y 내림차순 정렬
bool compare(vector<int>& a, vector<int>& b) {
	return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
}

vector<priority_queue<pair<int, int>>> yList; //y를 인덱스로 하는 (-x, val) 우선순위큐를 저장한 배열
int depth = 0;

Node* makeBinaryTree(int maxX, int level) {

	int x = -yList[level].top().first;
	int val = yList[level].top().second;
	yList[level].pop();
	Node* root = new Node(val);

	// 마지막 레벨이거나 자식 노드들이 없으면
	// 자식 노드 세팅 필요없음.
	if (level == depth || yList[level + 1].empty())
		return root;



	// 오른쪽 노드
	nextX = -yList[level + 1].top().first;
	if (x < nextX && nextX < maxX)
		root->right = makeBinaryTree(maxX, level + 1);
	return root;

	// 왼쪽 노드
	int nextX = -yList[level + 1].top().first;
	if (nextX < x)
		root->left = makeBinaryTree(x, level + 1);
	if (yList[level + 1].empty())
		return root;
}
