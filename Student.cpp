#include <iostream>
#include <stdlib.h> //rand)()

using namespace std;

Student::Student()
{
	waittime = rand() % 20 + 1; //1-20
	windowtime = rand() % 20 + 1;
}

Student::Student(int window)
{
	waittime = wait;
	windowtime = window;
}

Student::~Student() {}

void Student::incWaittime() { waittime++; }

void Student::occupyWindow()
{
	//TO BE IMPLEMENTED
}

void Student::changeLocation() { location++; }
