#pragma once
#include "Point.h"
#include "Action.h"
#ifndef PLAYER_H

class Player
{
public:
	Player() {}

	// 게임 처음 시작 시 호출됩니다.
	// 시작 플레이어 위치(매번 달라집니다), 미로의 높이와 너비가 매개변수로 들어옵니다. 
	virtual void gameStart(Point player, int height, int width) = 0;

	// 다음에 "움직일 방향"을 반환하세요. 
	// 해당 방향으로 한 칸 이동 시도 후 아래 두 함수 중 하나가 호출됩니다.
	//
	// Action enum안에는 { MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN } 가 들어 있습니다.
	// ex) return Action::MOVE_LEFT; // 왼쪽으로 이동
	virtual Action nextMove() = 0;

	// 다음에 움직일 방향에 벽이 없으면 이 함수가 호출됩니다.
	// 입력 매개변수로 "움직인 후의 좌표", "이동 전의 좌표"가 들어옵니다.
	// ex) (3, 4)에서 MOVE_LEFT 한다면 point는 (3, 3) 입니다.
	virtual void ableToMove(Point point, Point prevPoint) = 0;

	// 다음에 움직일 방향에 벽이 있으면 이 함수가 호출됩니다.
	// 입력 매개변수로 "현재 위치의 좌표"가 들어옵니다.
	// ex) (3, 4)에서 MOVE_LEFT 해도 point는 (3, 4) 입니다.
	virtual void notAbleToMove(Point point) = 0;
};

#endif