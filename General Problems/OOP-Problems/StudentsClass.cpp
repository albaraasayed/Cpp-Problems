/*
    Problem: Students Class with Static Members

    Create a class 'Students' that stores the following data for each student:
        - id (int)
        - name (char array of size 20)
        - grades (array of 5 integers)

    The class should also include:
        - A static member 'schoolName' shared by all students.
        - A static member 'counter' to keep track of how many student objects exist.

    Implement:
        - Default and parameterized constructors
        - Destructor (to decrement counter)
        - Getters and setters for all member variables
        - Static methods to get/set schoolName and get the counter

    Additional requirements:
        - A function 'fillStudent()' to read student data from the user and return a Students object.
        - A function 'printStudentData(Students s)' to display the student data.
        - Demonstrate the use of static members by printing the counter and school name.

    Tasks:
        1. Create a student using parameterized constructor.
        2. Print the student details.
        3. Display the number of student objects using the static counter.
        4. Display the school name using the static member.
*/

#include <iostream>
#include <cstring>

using namespace std;
class Students
{
    int id;
    char name[20];
    int grades[5];
    static char schoolName[20];
    static int counter;

public:
    Students()
    {
        id = 0;
        for (int i = 0; i < 20; i++)
        {
            name[i] = '\0';
        }
        for (int i = 0; i < 5; i++)
        {
            grades[i] = 0;
        }
        counter++;
    }
    Students(int id, char *name, int grades[5])
    {
        this->id = id;
        strcpy(this->name, name);
        for (int i = 0; i < 5; i++)
        {
            this->grades[i] = grades[i];
        }
        counter++;
    }
    ~Students()
    {
        counter--;
    }
    static int getCounter()
    {
        return counter;
    }
    static char *getSchoolName()
    {
        return schoolName;
    }
    static void setNameOfSchool(char *sname)
    {
        strcpy(schoolName, sname);
    }

    void setId(int id)
    {
        this->id = id;
    }
    void setName(char *name)
    {
        strcpy(this->name, name);
    }
    void setGrades(int *grades)
    {
        for (int i = 0; i < 5; i++)
        {
            this->grades[i] = grades[i];
        }
    }
    int getId()
    {
        return id;
    }
    char *getName()
    {
        return name;
    }
    int *getGrades()
    {
        return grades;
    }
};
int Students::counter = 0;
char Students::schoolName[20] = "School";

Students fillStudent()
{
    Students s;
    cout << "Enter Srudent ID" << endl;
    int id;
    cin >> id;
    s.setId(id);

    cout << "Enter Srudent Name" << endl;
    char name[20];
    cin >> name;
    s.setName(name);

    cout << "Enter Grades" << endl;
    int grades[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> grades[i];
    }
    s.setGrades(grades);
    return s;
}

void printStudentData(Students &s)
{
    cout << "Student Id is:" << s.getId() << endl;
    cout << "Student name is: " << s.getName() << endl;
    cout << "Student Grades" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << s.getGrades()[i] << endl;
    }
}

int main()
{
    int grade[5] = {30, 40, 60, 80, 90};
    char str[20] = "Albaraa Alsayed";
    Students s1(5, str, grade);
    printStudentData(s1);
    cout << "Counter: " << Students::getCounter() << endl;
    cout << "School name: " << Students::getSchoolName() << endl;
    return 0;
}