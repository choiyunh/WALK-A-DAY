#pragma once
#include <iostream>

class Point
{
public:
	// ������
	Point(int x = 0, int y = 0);

	// getter
	int getX() const;
	int getY() const;

	// ��� ���ϰ� �ϱ� ����
	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	// ���� �� �� ���ϰ� �ϱ� ���� �������̵�
	Point& operator = (const Point &p);
	bool operator == (const Point &p) const;
	bool operator != (const Point &p) const;

private:
	int x, y;
};