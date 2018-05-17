/*
 * main.cpp
 *
 *  Created on: May 17, 2018
 *      Author: hippo
 */

#include <iostream>
#include "NetworkAdapter.h"


int main(int argc, char **argv)
{
	NetworkAdapter adapter;
	adapter.PerformData();
	std::cout << "Answer:" << std::endl;
	adapter.PrintData();
	return 0;
}



