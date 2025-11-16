// class point
// class circle
// implement bu association and composition
// redias calc
// area (PI)
#include <iostream>
#include <cmath>
using namespace std;
// Composition
/* class Point
{
    int x;
    int y;

public:
    Point()
    {
        x = y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

class Circle
{
    float PI;
    float redius;
    Point p1, p2;

public:
    //  Circle()
    // {
    //     PI = 3.14;
    //     redius = 0;
    // }
    Circle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
    {
        PI = 3.14;
        redius = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    }
    float getArea()
    {
        return PI * redius * redius;
    }
    float getRedius()
    {
        return redius;
    }
};
 */

// Association
class Point
{
    int x;
    int y;

public:
    Point()
    {
        x = y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

class Circle
{
    float PI;
    float redius;
    Point *p1, *p2;

public:
    Circle()
    {
        p1 = p2 = nullptr;
        PI = 3.14;
        redius = 0;
    }
    Circle(Point *pt1, Point *pt2)
    {
        p1 = pt1;
        p2 = pt2;
        PI = 3.14;
        redius = sqrt(pow((p1->getX() - p2->getX()), 2) + pow((p1->getY() - p2->getY()), 2));
    }
    float getArea()
    {
        return PI * redius * redius;
    }
    float getRedius()
    {
        return redius;
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);
    Circle c(&p1, &p2);
    cout << c.getArea() << endl;
    cout << c.getRedius() << endl;
    return 0;
}
