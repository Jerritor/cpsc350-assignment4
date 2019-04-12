#include <iostream>
#include <fstream>
#include "FileIO.h"
#include "RegistrarDeque.h"

using namespace std;

FileIO::FileIO(string f)
{
	cout << readFile(f) << endl;
	//printQueues();
}

FileIO::~FileIO() {}

bool FileIO::readFile(string f) //returns if gridfile is opened
{
	ifstream inputfile; //input stream
	inputfile.open(f); //opening the user inputted file

	if (inputfile.fail())
	{
		cerr << "Error opening file." << endl;
		return false;
	}
	else
		cout << "Opening " << f << "..." << endl;

	string currentline;
	int linenum = 0;
	int timeToArrive = 0;
	int numOfppl = 0;
	int idSetter = 0;
	while (getline(inputfile, currentline, '\n')) //not end of file
	{
		//newline & carriage return deletion from string
		for(int i = 0; i < currentline.length(); i++)
		{
			if (currentline[i] == '\n' || currentline[i] == '\r')
				currentline.erase(i);
		}
		linenum++;

		if (linenum == 1) //line 1: # of rows
			if (stoi(currentline) < 0)
			{
				cerr << "Make sure the # of windows is positive!" << endl;
				inputfile.close();
				return false;
			}
			else windows = stoi(currentline);
		else //line >1
		{
			if (timeToArrive == 0)
				timeToArrive = stoi(currentline);
			else if (numOfppl == 0)
				numOfppl = stoi(currentline);
			else //timeToArrive != 0 AND numOfppl != 0
			{
					idDeque.enqueue(++idSetter); //add student id
					enterDeque.enqueue(timeToArrive); //add time to enter queue
					windowDeque.enqueue(stoi(currentline)); //add time needed @ window
					if (numOfppl == 1)
						timeToArrive = 0;
					numOfppl--;
			}
		}
		inputfile.clear();
	}

	cout << "Registrar File Succesfully Loaded: " << f << endl;
	inputfile.close();
	return true;
}

void FileIO::printQueues()
{
	while (!idDeque.isEmpty() || !enterDeque.isEmpty() || !windowDeque.isEmpty())
	{
		cout << idDeque.dequeue() << ": enter=" << enterDeque.dequeue() << " window=" << windowDeque.dequeue() << endl;
	}
}

void FileIO::transferQueues(RegistrarDeque &id, RegistrarDeque &enter, RegistrarDeque &win, int &numWins)
{
	numWins = windows;
	while (!idDeque.isEmpty() || !enterDeque.isEmpty() || !windowDeque.isEmpty())
	{
		id.enqueue(idDeque.dequeue());
		enter.enqueue(enterDeque.dequeue());
		win.enqueue(windowDeque.dequeue());
	}
}
