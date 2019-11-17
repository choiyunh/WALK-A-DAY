#include <iostream>
#include <time.h>
#include "Maze.h"
#include <stack>
#include <vector>
#include "P2018112063.h"
#include "GameManager.h"

using namespace std;

void P2018112063::gameStart(Point player, int height, int width) { 
	//남은 함수는 프로젝트 하면서 구현할 예정	
	m.generateMaze();
	curX = player.getX();
	curY = player.getY();
	check[curX][curY] = 1;
}

Action P2018112063::nextMove() { //nextMove에 리턴값이 있어야 실행이 되므로 구현해줌
	flag = 0;
	int i = 0;
	for (i = 0; i < 4; i++) {
		int tempX = curX + dir[i].getX();
		int tempY = curY + dir[i].getY();
		// 골인이면
		if (m.isGoal(Point(tempX, tempY))) {
			return Action(i);
		}
		// 해당 방향으로 이동할 수 있으면
		if (m.ableToMove(Point(tempX, tempY)) && check[tempX][tempY] == 0) {
			if (flag == 0) {
				nextX = tempX;
				nextY = tempY;
			}
			flag = 1;			
		}
		tempX = curX;
		tempY = curY;
	}
	// 네 방향 다 움직일 수 없을 때
	if (flag == 0 && !s.empty()) {
		check[curX][curY] = 1;
		nextX = s.top().getX();
		nextY = s.top().getY();
		s.pop();
	}
	if (nextX - curX == 1) {
		return MOVE_DOWN;
	}
	if (nextX - curX == -1) {
		return MOVE_UP;
	}
	if (nextY - curY == 1) {
		return MOVE_RIGHT;
	}
	if (nextY - curY == -1) {
		return MOVE_LEFT;
	}	
}


void P2018112063::ableToMove(Point point, Point prevPoint) {
	curX = point.getX();
	curY = point.getY();
	check[prevPoint.getX()][prevPoint.getY()] = 1;
	if (flag == 1)
		s.push(prevPoint);
}
void P2018112063::notAbleToMove(Point point) {
	check[point.getX()][point.getY()] = 1;
}
