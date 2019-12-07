#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
#include "Point.h"

// 벽(WALL)인지 공간(SPACE)인지 골 지점(GOAL)인지를 나타내는 enum
enum Cell
{
	WALL, SPACE, GOAL
};

class Maze
{
public:
	// 미로의 크기, (높이 너비)
	// 상수 값은 Constants.h에 선언됨
	static const int WIDTH = MAZE_WIDTH;
	static const int HEIGHT = MAZE_HEIGHT;


	// 미로 출력, 플레이어 위치도 받아서 출력
	void printMaze(const Point& player) const;

	// 미로를 랜덤으로 생성
	void generateMaze();

	// 시작점 반환
	Point getStartPoint() const;

	// 해당 좌표에 이동 가능한가
	bool ableToMove(const Point& point) const;

	// 해당 좌표가 목표 지점인가
	bool isGoal(const Point& point) const;
	

private:
	// 실제 미로 맵
	Cell map[HEIGHT][WIDTH];
	// 시작점
	Point startPoint;
};