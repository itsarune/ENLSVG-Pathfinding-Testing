#include "Pathfinding/ENLSVG.h"
#include <stdio.h>

// 1200 x 1000 tiles
int sizeX = 1200;
int sizeY = 1000;

int main()
{
	// Create grid
	Pathfinding::Grid grid(sizeX, sizeY);

	for (int x = 100; x < sizeX; ++x)
	{
		for (int y = sizeY-400; y < sizeY-200; ++y)
		{
			grid.setBlocked(x, y, true);
		}
	}
	
	for (int x = 0; x < sizeX-200; ++x)
	{
		for (int y = sizeY-700; y < sizeY-500; ++y)
		{
			grid.setBlocked(x, y, true);
		}
	}
	
	// Preprocess the grid to build a visibility graph.
	Pathfinding::ENLSVG::Algorithm algo(grid);

	// Initialise a memory object for the algorithm. The algorithm uses this memory object for its path computations.
	Pathfinding::ENLSVG::Memory memory(algo);

	Pathfinding::Path path;
	// Compute 10000 paths
	for (int i=0; i<10000; ++i) {
		int startX = 0;
		int startY = 0;
		int endX = 1200;
		int endY = 1000;
		
		path = algo.computePath(memory, startX, startY, endX, endY);
		std::cout << path.size() << std::endl;
		
		for (auto p : path)
		{
			std::cout << "Point: " << p.x << ", " << p.y << '\n';
		}
		
	}
}