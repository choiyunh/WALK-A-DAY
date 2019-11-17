#pragma once
#include "Point.h"
#include "Action.h"
#ifndef PLAYER_H

class Player
{
public:
	Player() {}

	// ���� ó�� ���� �� ȣ��˴ϴ�.
	// ���� �÷��̾� ��ġ(�Ź� �޶����ϴ�), �̷��� ���̿� �ʺ� �Ű������� ���ɴϴ�. 
	virtual void gameStart(Point player, int height, int width) = 0;

	// ������ "������ ����"�� ��ȯ�ϼ���. 
	// �ش� �������� �� ĭ �̵� �õ� �� �Ʒ� �� �Լ� �� �ϳ��� ȣ��˴ϴ�.
	//
	// Action enum�ȿ��� { MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN } �� ��� �ֽ��ϴ�.
	// ex) return Action::MOVE_LEFT; // �������� �̵�
	virtual Action nextMove() = 0;

	// ������ ������ ���⿡ ���� ������ �� �Լ��� ȣ��˴ϴ�.
	// �Է� �Ű������� "������ ���� ��ǥ", "�̵� ���� ��ǥ"�� ���ɴϴ�.
	// ex) (3, 4)���� MOVE_LEFT �Ѵٸ� point�� (3, 3) �Դϴ�.
	virtual void ableToMove(Point point, Point prevPoint) = 0;

	// ������ ������ ���⿡ ���� ������ �� �Լ��� ȣ��˴ϴ�.
	// �Է� �Ű������� "���� ��ġ�� ��ǥ"�� ���ɴϴ�.
	// ex) (3, 4)���� MOVE_LEFT �ص� point�� (3, 4) �Դϴ�.
	virtual void notAbleToMove(Point point) = 0;
};

#endif