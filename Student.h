#pragma once
#include <iostream>

using namespace std;

class Student
{
  public:
	int waittime = 0; //counter increments while in queue
	int windowtime = 0;
	int location = 0; //0=stack,1=queue,2=window

	Student(); //random waittime and windowtime
	Student(int window);
	~Student();

	void incWaittime();
	void occupyWindow();
	void changeLocation(); //increments location

	//overriding operator<< for printing
	ostream& operator<<(ostream& os) {
        return "Student(" << waittime << ", " << windowtime << ")" << endl;
    }
};