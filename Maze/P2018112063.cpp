#include <iostream>
#include <time.h>
#include "Maze.h"
#include <stack>
#include <vector>
#include "P2018112063.h"
#include "GameManager.h"

using namespace std;

void P2018112063::gameStart(Point player, int height, int width) { 
	//���� �Լ��� ������Ʈ �ϸ鼭 ������ ����	
	m.generateMaze();
	curX = player.getX();
	curY = player.getY();
	check[curX][curY] = 1;
}

Action P2018112063::nextMove() { //nextMove�� ���ϰ��� �־�� ������ �ǹǷ� ��������
	flag = 0;
	int i = 0;
	for (i = 0; i < 4; i++) {
		int tempX = curX + dir[i].getX();
		int tempY = curY + dir[i].getY();
		// �����̸�
		if (m.isGoal(Point(tempX, tempY))) {
			return Action(i);
		}
		// �ش� �������� �̵��� �� ������
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
	// �� ���� �� ������ �� ���� ��
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
