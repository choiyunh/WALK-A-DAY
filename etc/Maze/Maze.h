#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
#include "Point.h"

// ��(WALL)���� ����(SPACE)���� �� ����(GOAL)������ ��Ÿ���� enum
enum Cell
{
	WALL, SPACE, GOAL
};

class Maze
{
public:
	// �̷��� ũ��, (���� �ʺ�)
	// ��� ���� Constants.h�� �����
	static const int WIDTH = MAZE_WIDTH;
	static const int HEIGHT = MAZE_HEIGHT;


	// �̷� ���, �÷��̾� ��ġ�� �޾Ƽ� ���
	void printMaze(const Point& player) const;

	// �̷θ� �������� ����
	void generateMaze();

	// ������ ��ȯ
	Point getStartPoint() const;

	// �ش� ��ǥ�� �̵� �����Ѱ�
	bool ableToMove(const Point& point) const;

	// �ش� ��ǥ�� ��ǥ �����ΰ�
	bool isGoal(const Point& point) const;
	

private:
	// ���� �̷� ��
	Cell map[HEIGHT][WIDTH];
	// ������
	Point startPoint;
};