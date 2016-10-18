#include "dijkstra.hpp"

int main()
{
	homebrew::dejkstra_paths dp1
	{
		{ 0.0, 2.0, 0.0 },
		{ 2.0, 0.0, 3.0 },
		{ 0.0, 3.0, 0.0 }
	};

	auto v1 = dp1.get_min_paths(1);

	homebrew::dejkstra_paths dp2
	{
		{ 0, 1, 4, 0, 2, 0 },
		{ 1, 0, 0, 9, 0, 0 },
		{ 4, 0, 0, 7, 0, 0 },
		{ 0, 9, 7, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 8 },
		{ 0, 0, 0, 2, 8, 0 }
	};

	auto v2 = dp2.get_min_paths(1);
}