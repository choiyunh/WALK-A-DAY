#include "Point.h"

Point::Point(int x, int y): x(x), y(y) //x=x; y=y;를 대입.
{
}

int Point::getX() const //x좌표.
{
	return x;
}

int Point::getY() const //y좌표.
{
	return y;
}

std::ostream& operator << (std::ostream& os, const Point& point) 
{
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}

Point& Point::operator = (const Point &point) //좌표 이동.
{
	x = point.x;
	y = point.y;
	return *this;
}

bool Point::operator == (const Point &point) const //움직인 x,y 좌표와 x,y 좌표를 비교해서  
{                                                  // 둘다 맞을경우 true값을 반환.
	return (x == point.x) && (y == point.y);
}

bool Point::operator != (const Point &point) const //움직인 x,y 좌표와 x,y 좌표를 비교해서
{                                                   //둘 중 하나라도 틀릴 경우 false값을 반환.
	return !((x == point.x) && (y == point.y));
}