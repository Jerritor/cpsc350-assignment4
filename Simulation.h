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

		RegistrarDeque waitLine;
		int clock = 0;
		int windows;
		Window *wins;

		Simulation(string f);
		~Simulation();

		void printQueues();
};
