#include "Pathfinding/ENLSVG.h"
#include <stdio.h>
#include <fstream>

// 1200 x 1000 tiles
int sizeX = 1200;
int sizeY = 1000;

void storeBlockedPoint(std::ofstream &output, int x, int y)
{
  output << x << "," << y << "\n";
}

int main()
{
	// Create grid
	Pathfinding::Grid grid(sizeX, sizeY);
  	std::ofstream output;
	output.open("output.csv");
  	output << "BLOCKED\n";

	for (int x = 100; x < 200; ++x)
	{
		for (int y = sizeY; y > 10; --y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 250; x < 350; ++x)
	{
		for (int y = 0; y < sizeY - 10; ++y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 400; x < 500; ++x)
	{
		for (int y = sizeY; y > 10; --y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 550; x < 650; ++x)
	{
		for (int y = 0; y < sizeY - 10; ++y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
	
  	for (int x = 660; x < 760; ++x)
	{
		for (int y = sizeY; y > 10; --y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 800; x < 900; ++x)
	{
		for (int y = 0; y < sizeY - 10; ++y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 910; x < 1010; ++x)
	{
		for (int y = sizeY; y > 10; --y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}
  
  	for (int x = 1020; x < sizeX-10; ++x)
	{
		for (int y = 0; y < sizeY - 10; ++y)
		{
			grid.setBlocked(x, y, true);
		  	storeBlockedPoint(output, x, y);
		}
	}

	
	// Preprocess the grid to build a visibility graph.
	Pathfinding::ENLSVG::Algorithm algo(grid);

	// Initialise a memory object for the algorithm. The algorithm uses this memory object for its path computations.
	Pathfinding::ENLSVG::Memory memory(algo);

	Pathfinding::Path path;
	
	int startX = 0;
	int startY = 0;
	int endX = 1200;
	int endY = 1000;

	path = algo.computePath(memory, startX, startY, endX, endY);
//	std::cout << path.size() << std::endl;
	output << "PATH\n";
	for (auto p : path)
	{
//		std::cout << "Point: " << p.x << ", " << p.y << '\n';
	  storeBlockedPoint(output, p.x, p.y);
	}
  	output.close();
		
}