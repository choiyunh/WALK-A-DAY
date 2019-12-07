#pragma once
#include <iostream>

class Point
{
public:
	// 생성자
	Point(int x = 0, int y = 0);

	// getter
	int getX() const;
	int getY() const;

	// 출력 편하게 하기 위함
	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	// 대입 및 비교 편하게 하기 위한 오버라이딩
	Point& operator = (const Point &p);
	bool operator == (const Point &p) const;
	bool operator != (const Point &p) const;

private:
	int x, y;
};