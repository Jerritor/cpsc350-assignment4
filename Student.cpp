#include <iostream>
#include <stdlib.h> //rand)()

using namespace std;

Student::Student(int i)
{
	id = i;
	waittime = rand() % 20 + 1; //1-20
	windowtime = rand() % 20 + 1;
}

Student::Student(int i, int window)
{
	id = i;
	windowtime = window;
	waittime = rand() % 20 + 1; //1-20
}

Student::Student(int i, int window, int wait)
{
	id = i;
	windowtime = window;
	waittime = wait;
}

Student::~Student() {}

void Student::incWaittime() { waittime++; }

void Student::occupyWindow()
{
	//TO BE IMPLEMENTED
}

void Student::changeLocation() { location++; }
