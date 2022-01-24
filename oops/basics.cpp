#include<iostream>
using namespace std;

/*
 * What is OOP?
 * Programming paradigm where things revolve around objects.
 *
 * What is object? (Like real life project)
 * Object is an entitiy which has some property and some specified behaviour
 *
 * Why?
 * To increase readability, extensibility and managability of our codebase
 *
 * A class is an user defined data type. And an object is an instance of a class.
 *
 */

class Hero {
public:
    string name;
    int health;
    string level;
};

int main() {
    Hero h1;
    h1.health = 100;
    h1.name = "Ramesh";
    h1.level = "6";
    cout<<h1.name<<' '<<h1.health<<' '<<h1.level<<endl;
}

