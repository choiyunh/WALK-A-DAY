#pragma once
#include "Maze.h"
#include "Player.h"

class GameManager
{
public:
	// 게임 초기화
	// -> 미로 생성
	void init();
	// player 가 실제 게임 플레이 진행
	// -> 플레이어가 이동할 액션을 선택, 그에 따른 반응을 호출.
	// -> 도착지점을 일정 턴 안에 도달 시 게임 클리어	
	void run(Player *player);

private:
	// 미로
	Maze maze;
};