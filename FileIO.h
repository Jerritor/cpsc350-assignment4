#pragma once
#include <iostream>
#include "RegistrarDeque.h"

using namespace std;

class FileIO
{
	public:
		RegistrarDeque idDeque;
		RegistrarDeque enterDeque;
		RegistrarDeque windowDeque;
		int windows;

		FileIO(string f);
		~FileIO();
		bool readFile(string f);
		void printQueues();
		void transferQueues(RegistrarDeque &id, RegistrarDeque &enter, RegistrarDeque &win, int &numWins);

		//enter queue <int> holds times to let students go
		//id queue <int> holds the id's to be released into queue (in order)

		//registrar queue <int> holds waiting times (increments in line)
		//window array <int> holds student # at window

		bool timeNumEntered;
		//int[numEntered]
};
