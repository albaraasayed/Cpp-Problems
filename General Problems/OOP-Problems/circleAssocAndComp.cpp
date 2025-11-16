/*
    Create a program that models circles using two different types
    of relationships between classes: Association and Composition.

    1. Define a Point class that stores an (x, y) coordinate.

    2. Implement a CircleA class that represents a circle using
       *Association*, where the circle receives two Point objects
       as pointers. The distance between these two points should be
       used to calculate the radius of the circle.

    3. Implement a CircleC class that represents a circle using
       *Composition*, where the circle contains two Point objects
       directly as member variables. The radius should also be
       computed based on the distance between the two points.

    4. For both circle types, calculate:
        - The radius based on the distance between the points
        - The area of the circle (Area = PI * r²)

    In main(), create Point objects, pass them to CircleA, and also
    create CircleC using coordinates directly. Display the radius
    and area for each circle.
*/

#include <iostream>
#include <cmath>
using namespace std;

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

// Association
class CircleA
{
    float PI;
    float redius;
    Point *p1, *p2;

public:
    CircleA()
    {
        p1 = p2 = nullptr;
        PI = 3.14;
        redius = 0;
    }
    CircleA(Point *pt1, Point *pt2)
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

// Composition
class CircleC
{
    float PI;
    float redius;
    Point p1, p2;

public:
    //  CircleC()
    // {
    //     PI = 3.14;
    //     redius = 0;
    // }
    CircleC(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
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

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);
    CircleA c1(&p1, &p2);
    cout << "Area of CircleA: " << c1.getArea() << endl;
    cout << "Radius of CircleA: " << c1.getRedius() << endl;

    CircleC c2(0, 0, 3, 4);
    cout << "Area of CircleC: " << c2.getArea() << endl;
    cout << "Radius of CircleC: " << c2.getRedius() << endl;
    return 0;
}
