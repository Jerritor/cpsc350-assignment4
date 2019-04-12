#pragma once
#include <iostream>
//#include <stdio.h>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(string f)
{
	FileIO io(f);
	io.transferQueues(ids,enterTimes,windowTimes,windows);
	cout << "windows: " << windows << endl;
	wins = new Window[windows];
	while(true)
	{
		cout << "Clock: " << ++clock << endl;

		if (enterTimes.isEmpty() && windowTimes.isEmpty()) //once queues are empty
		{
			cout << "Queues empty." << endl;
			break;
		}

		if (clock == enterTimes.peek()) //if its time for student to enter
		{
			while (clock == enterTimes.peek())
			{
				waitLine.enqueue(0); //0 mins
				cout << "Removing (entertime): " << enterTimes.dequeue() << endl;
			}
		}

		bool vacant = false;
		int openWindow = 0; //0 means none
		for(int i = 0; i < windows; i++)
		{
			if(wins[i].getId() == clock) //dequeue
			{
				wins[i].setId(0); //set to vacant
			}

			if(!wins[i].isOccupied()) //empty
			{
				vacant = true;
				break;
			}
		}

		if (vacant)
		{
			wins[openWindow].setId(clock + windowTimes.dequeue() ); //transform id to leave time
		}

		if (clock >= 20) break;
	}

	//int size = sizeof(wins)/sizeof(wins[0]);
	//cout << "size: " << size << endl;
	//for(int i = 0; i < size; i++) cout << (i) << endl;
	//ids.enqueue(1);
	//enterTimes.enqueue(2);
	//windowTimes.enqueue(3);
	printQueues();
}

Simulation::~Simulation() { delete wins; }

void Simulation::printQueues()
{
	while (!ids.isEmpty() || !enterTimes.isEmpty() || !windowTimes.isEmpty())
	{
		cout << ids.dequeue() << ": enter=" << enterTimes.dequeue() << " window=" << windowTimes.dequeue() << endl;
	}
}
