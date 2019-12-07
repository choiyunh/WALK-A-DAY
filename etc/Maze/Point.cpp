#include "Point.h"

Point::Point(int x, int y): x(x), y(y) //x=x; y=y;�� ����.
{
}

int Point::getX() const //x��ǥ.
{
	return x;
}

int Point::getY() const //y��ǥ.
{
	return y;
}

std::ostream& operator << (std::ostream& os, const Point& point) 
{
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}

Point& Point::operator = (const Point &point) //��ǥ �̵�.
{
	x = point.x;
	y = point.y;
	return *this;
}

bool Point::operator == (const Point &point) const //������ x,y ��ǥ�� x,y ��ǥ�� ���ؼ�  
{                                                  // �Ѵ� ������� true���� ��ȯ.
	return (x == point.x) && (y == point.y);
}

bool Point::operator != (const Point &point) const //������ x,y ��ǥ�� x,y ��ǥ�� ���ؼ�
{                                                   //�� �� �ϳ��� Ʋ�� ��� false���� ��ȯ.
	return !((x == point.x) && (y == point.y));
}