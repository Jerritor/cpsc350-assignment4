#pragma once
#include <iostream>
#include "Window.h"

using namespace std;

Window::Window()

Window::~Window() {}

void Window::occupy(int i)
{
	id = i;
}

int Window::vacate()
{
	int tmp = id;
	id = 0;
	return tmp;
}

bool Window::isOccupied() { return (id == 0); }
