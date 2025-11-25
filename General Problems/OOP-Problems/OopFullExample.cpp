#include <iostream>
using namespace std;

class Shape
{
protected:
    int dir1;
    int dir2;

public:
    Shape()
    {
        dir1 = dir2 = 0;
        cout << "Default Constructor of class Shape" << endl;
    }
    Shape(int dir)
    {
        dir1 = dir2 = dir;
        cout << "Single Parameter Constructor of class Shape" << endl;
    }
    Shape(int dir1, int dir2)
    {
        this->dir1 = dir1;
        this->dir2 = dir2;
        cout << "Two Parameters Constructor of class Shape" << endl;
    }
    void setDir1(int dir1)
    {
        this->dir1 = dir1;
    }
    void setDir2(int dir2)
    {
        this->dir2 = dir2;
    }
    int getDir1()
    {
        return dir1;
    }
    int getDir2()
    {
        return dir2;
    }
    virtual float getArea() = 0;
    virtual ~Shape()
    {
        cout << "Destructor of Shape" << endl;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle()
    {
        cout << "Default Constructor of class Rectangle" << endl;
    }
    Rectangle(int dir1, int dir2) : Shape(dir1, dir2)
    {
        cout << "Two Parameters Constructor of class Rectangle" << endl;
    }
    float getArea()
    {
        cout << "Area of Rectangle: ";
        return getDir1() * getDir2();
    }
};

class Triangle : public Shape
{
public:
    Triangle()
    {
        cout << "Default Constructor of class Triangle" << endl;
    }
    Triangle(int dir1, int dir2) : Shape(dir1, dir2)
    {
        cout << "Two Parameters Constructor of class Triangle" << endl;
    }
    float getArea()
    {
        cout << "Area of Triangle: ";
        return 0.5 * getDir1() * getDir2();
    }
};

class Circle : public Shape
{
public:
    Circle()
    {
        cout << "Default Constructor of class Circle" << endl;
    }
    Circle(int r) : Shape(r, r)
    {
    }
    float getArea()
    {
        cout << "Area of Circle: ";
        return 3.14 * getDir1() * getDir2();
    }
};

class Square : public Rectangle
{
public:
    Square()
    {
        cout << "Default Constructor of class Square" << endl;
    }
    Square(int m) : Rectangle(m, m)
    {
        cout << "Single Parameter Constructor of class Square" << endl;
    }
    float getArea()
    {
        cout << "Area of Square: ";
        return getDir1() * getDir2();
    }
};

class geoShape
{
    Shape **shapes;
    int size;

public:
    geoShape(Shape *shapes[], int size)
    {
        this->size = size;
        this->shapes = new Shape *[size];
        cout << "Constructor of class geoShape" << endl;
        for (int i = 0; i < size; i++)
        {
            this->shapes[i] = shapes[i];
        }
    }
    ~geoShape()
    {
        for (int i = 0; i < size; i++)
        {
            delete shapes[i];
        }
        delete[] shapes;
    }
    /*   geoShape(Shape **shapes, int size)
      {
          this->size = size;
          this->shapes = new Shape *[size];
          cout << "Constructor of class geoShape" << endl;
          sum = 0;
          for (int i = 0; i < size; i++)
          {
              this->shapes[i] = *shapes[i];
          }
      } */
    int totalSum()
    {
        float sum = 0;
        cout << "Total Area: ";
        for (int i = 0; i < size; i++)
        {
            sum += shapes[i]->getArea();
        }
        return sum;
    }
};

int main()
{
    int size;
    cout << "Enter The number Of shapes";
    cin >> size;
    Shape **sh = new Shape *[size];

    int i = 0;
    int choiceOfSwitch;
    do
    {
        cout << "Select shape that you want to add" << endl;
        cout << "1. Rectangle" << endl;
        cout << "2. Circle" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Squere" << endl;
        cin >> choiceOfSwitch;
        switch (choiceOfSwitch)
        {
        case 1:
        {
            int dir1;
            int dir2;
            cout << "Enter length and width of Rectangle" << endl;
            cin >> dir1 >> dir2;
            sh[i] = new Rectangle(dir1, dir2);
            break;
        }
        case 2:
        {
            int r;
            cout << "Enter radius of Circle" << endl;
            cin >> r;
            sh[i] = new Circle(r);
            break;
        }
        case 3:
        {
            int base;
            int height;
            cout << "Enter base and height of Triangle" << endl;
            cin >> base >> height;
            sh[i] = new Triangle(base, height);
            break;
        }
        case 4:
        {
            int m;
            cout << "Enter side of Square" << endl;
            cin >> m;
            sh[i] = new Square(m);
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
        i++;
    } while (i < size);

    geoShape g(sh, size);
    cout << g.totalSum() << endl;
    delete[] sh;
    return 0;
}