#pragma once
#include <iostream>
#include <stack>
#include "Player.h"
#include "Maze.h"
using namespace std;

class P2018112063 :public Player{ //player�� ��ӹ޴� Ŭ���� P2018112063 ����
public:
	void gameStart(Point player, int height, int width); //Player�� �Լ��� �����Ѵ�.
	Action nextMove();                                   //P2018112063.cpp���� �÷��̾ ������ ������
	void ableToMove(Point point, Point prevPoint);       //�������ִ°�.
	void notAbleToMove(Point point);
	int visited[21][51] = { 0, };


	int curX, curY;
	int nextX, nextY;
	stack<Point> s;
	int flag = 0;
	Point dir[4] = { {0,-1},{0,+1},{-1,0},{+1,0} }; // L R U D
	int check[21][51] = { 0, };
private:
	Maze m;
};
