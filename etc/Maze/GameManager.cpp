#include "GameManager.h"
using namespace std;
void GameManager::init()
{
	maze.generateMaze();
	// 미로를 화면에 출력
	//maze.printMaze(maze.getStartPoint()); 
}

// player: 게임할 플레이어
void GameManager::run(Player* player)
{
	// 현재 플레이어의 좌표는 미로의 시작점으로
	Point playerPoint = maze.getStartPoint();

	// 게임 스타트
	player->gameStart(playerPoint, Maze::HEIGHT, Maze::WIDTH);

	// 10000번 턴을 준다.
	// 10000번 내에 미로를 끝내지 못하면 게임 오버.
	int limitTurn = MAX_TURN;
	while (limitTurn--)
	{
		// 미로를 화면에 출력
		//maze.printMaze(playerPoint);
		
		// 다음에 이동할 좌표
		Point nextPoint;
		switch (player->nextMove())  //switch문을 이용해서 case 사용.
		{
		case MOVE_LEFT: 
			nextPoint = Point(playerPoint.getX(), playerPoint.getY() - 1);
			break;
		case MOVE_RIGHT:
			nextPoint = Point(playerPoint.getX(), playerPoint.getY() + 1);					
			break;
		case MOVE_UP:			
			nextPoint = Point(playerPoint.getX() - 1, playerPoint.getY());
			break;
		case MOVE_DOWN:						
			nextPoint = Point(playerPoint.getX() + 1, playerPoint.getY());
			break;
		}

		// 클리어
		if (maze.isGoal(nextPoint))
		{
			break;
		}

		// 이동 가능하면
		if (maze.ableToMove(nextPoint))
		{
			player->ableToMove(nextPoint, playerPoint); 

			playerPoint = nextPoint;
		}
		// 이동이 불가능하면 
		else
		{
			player->notAbleToMove(playerPoint);
		}
	}


	// 미로를 화면에 출력
	maze.printMaze(playerPoint);

	// 지정된 턴 이전에 끝나면 게임 클리어 및 소요된 턴 출력
	if (limitTurn >= 0)
	{
		cout << MAX_TURN - limitTurn << "회 만에 미로를 클리어 하셨습니다! >,<" << endl;
	}
	// 게임 오버
	else
	{
		cout << MAX_TURN << "회 안에 미로를 클리어 하지 못하셨습니다! T^T" << endl;
	}


	delete player;
}
