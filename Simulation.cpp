#pragma once
#include <iostream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(string f)
{
	FileIO io(f);
	io.transferQueues(ids,enterTimes,windowTimes,windows);
	wins = new Windows();
	while(true)
	{
		cout << "Clock: " << ++clock << endl;
		break;
	}
	for(int i = 0; i < wins.size(); i++) cout << (wins[i]->id) << endl;
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
