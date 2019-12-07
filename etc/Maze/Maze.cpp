#include "Maze.h"
#include "MazeGenerator.h"
using namespace std;
void Maze::printMaze(const Point & player) const
{
	//system("cls");
	for (int x = 0; x < HEIGHT; x++)
	{
		for (int y = 0; y < WIDTH; y++)
		{
			// 벽이면 꽉찬 사각형 출력
			if (map[x][y] == WALL) 
			{
				cout << "■"; 
			}
			//  미로 출구이면 하트 출력 
			else if (map[x][y] == GOAL)
			{
				cout << "♡";
			}
			// 플레이어 위치에 웃 출력
			else if (player.getX() == x && player.getY() == y)
			{
				cout << "웃";
			}
			// 빈 공간이면 그냥 공백 출력
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void Maze::generateMaze()
{
	// 미로 랜덤으로 생성
	MazeGenerator mazeGenerator;
	mazeGenerator.generate(map[0], WIDTH, HEIGHT);

	// 시작점과 도착점 세팅
	int isStart = rand() % 2;
	for (int x = 0; x < HEIGHT; x++) 
	{
		for (int y = 0; y < WIDTH; y++)
		{
			// 외곽에 도착점 및 시작점 세팅
			if ((x == 0 || x == HEIGHT - 1 || y == 0 || y == WIDTH - 1) && map[x][y] == Cell::SPACE)
			{
				if (isStart == 0)
				{
					map[x][y] = Cell::GOAL;
					isStart = 1 - isStart;
				}
				else
				{
					startPoint = Point(x, y);
					isStart = 1 - isStart;
				}
			}
		}
	}
}

Point Maze::getStartPoint() const //시작점으로 돌아가기.
{
	return startPoint;
}

bool Maze::ableToMove(const Point & point) const //움직일 수 있음을 판단.
{
	// 범위 체크
	if (point.getX() < 0 || point.getX() >= HEIGHT || point.getY() < 0 || point.getY() >= WIDTH)
	{
		return false; 
	}
	return map[point.getX()][point.getY()] == Cell::SPACE;
}

bool Maze::isGoal(const Point & point) const 
{
	// 범위 체크
	if (point.getX() < 0 || point.getX() >= HEIGHT || point.getY() < 0 || point.getY() >= WIDTH)
	{
		return false;
	}
	return map[point.getX()][point.getY()] == Cell::GOAL;
}
