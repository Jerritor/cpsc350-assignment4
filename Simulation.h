#pragma once
#include <iostream>
#include "FileIO.h"
#include "RegistrarDeque.h"

using namespace std;

class Simulation
{
	public:
		RegistrarDeque ids;
		RegistrarDeque enterTimes;
		RegistrarDeque windowTimes;
		int clock = 0;
		int windows;

		Simulation(string f);
		~Simulation();

		void printQueues();
};
