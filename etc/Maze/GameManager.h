#pragma once
#include "Maze.h"
#include "Player.h"

class GameManager
{
public:
	// ���� �ʱ�ȭ
	// -> �̷� ����
	void init();
	// player �� ���� ���� �÷��� ����
	// -> �÷��̾ �̵��� �׼��� ����, �׿� ���� ������ ȣ��.
	// -> ���������� ���� �� �ȿ� ���� �� ���� Ŭ����	
	void run(Player *player);

private:
	// �̷�
	Maze maze;
};