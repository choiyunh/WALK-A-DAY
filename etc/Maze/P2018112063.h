#pragma once
#include <iostream>
#include <stack>
#include "Player.h"
#include "Maze.h"
using namespace std;

class P2018112063 :public Player{ //player를 상속받는 클래스 P2018112063 생성
public:
	void gameStart(Point player, int height, int width); //Player속 함수를 정의한다.
	Action nextMove();                                   //P2018112063.cpp에서 플레이어가 움직일 것으로
	void ableToMove(Point point, Point prevPoint);       //정의해주는것.
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
