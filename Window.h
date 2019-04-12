#pragma once
#include <iostream>
#include "FileIO.h"
#include "RegistrarDeque.h"

using namespace std;

class Window
{
	public:
		int id = 0; //id=0 means unoccupied

		Window();
		~Window();

		void occupy(int i);
		int vacate();
		bool isOccupied();
};
