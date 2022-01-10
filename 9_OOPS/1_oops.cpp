#include <iostream>
using namespace std;
class Person
{
    
public:

    string name;
    int age;
    void sayHi()
    {
        if (this->age <= 18)
        {
            cout << "Heya from"
                 << " " << this->name << endl;
        }
        else
        {
            cout << "Hello from"
                 << " " << this->name << endl;
        }
    }

};

int main()
{

    Person p1; //reference to the instance or class
    p1.name = "Mohit";
    p1.age = 5;
    p1.sayHi();
    Person p2; //reference to the instance or class
    p2.name = "Shivam";
    p2.age = 35;
    p2.sayHi();

    return 0;
}