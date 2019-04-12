#pragma once
#include <iostream>
#include "FileIO.h"
#include "RegistrarDeque.h"
#include "Window.h"


using namespace std;

class Simulation
{
	public:
		RegistrarDeque ids;
		RegistrarDeque enterTimes;
		RegistrarDeque windowTimes;
		int clock = 0;
		int windows;
		Windows *wins;

		Simulation(string f);
		~Simulation();

		void printQueues();
};
