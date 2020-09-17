#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Point2D
{
private:
    int x;
    int y;
    string h;

public:
    Point2D(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    Point2D(int x_, int y_, string h_)
    {
        x = x_;
        y = y_;
        h = h_;
    }

    int getDistance(Point2D next)
    {
        return abs(this->x - next.x) + abs(this->y - next.y);
    }
    string exec(Point2D p_)
    {
        this->x = p_.x;
        this->y = p_.y;

        return this->h;
    }
};

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    Point2D left(3, 0, "L"), right(3, 2, "R");

    vector<Point2D> p = {
        Point2D(3, 1),
        Point2D(0, 0),
        Point2D(0, 1),
        Point2D(0, 2),
        Point2D(1, 0),
        Point2D(1, 1),
        Point2D(1, 2),
        Point2D(2, 0),
        Point2D(2, 1),
        Point2D(2, 2)};

    for (int i : numbers)
        if (i % 3 == 1)
            answer += left.exec(p[i]);
        else if (i != 0 && i % 3 == 0)
            answer += right.exec(p[i]);
        else
            if (left.getDistance(p[i]) == right.getDistance(p[i]))
                answer += hand == "left" ? left.exec(p[i]) : right.exec(p[i]);
            else
                answer += left.getDistance(p[i]) < right.getDistance(p[i]) ? left.exec(p[i]) : right.exec(p[i]); 

    return answer;
}