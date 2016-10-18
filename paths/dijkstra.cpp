#include "dijkstra.hpp"

namespace homebrew
{
	dejkstra_paths::dejkstra_paths(std::initializer_list<std::vector<double>> matrix) :
		size_(matrix.size()), matrix_(matrix), paths_(size_), visited_(size_), calculated_(false)
	{
	}

	void dejkstra_paths::calculate_paths(const int start_vertex)
	{
		std::queue<int> nodes_queue;
		int curr_vertex;
		start_vertex_ = start_vertex;
		nodes_queue.push(start_vertex);
		while (!nodes_queue.empty())
		{
			curr_vertex = nodes_queue.front();
			nodes_queue.pop();
			visited_[curr_vertex] = true;
			for (int i = 0; i < size_; i++)
			{
				if (matrix_[curr_vertex][i] != 0)
				{
					if (!visited_[i])
					{
						nodes_queue.push(i);
						paths_[i] = paths_[curr_vertex] + matrix_[curr_vertex][i];
					}
					if (paths_[i] > paths_[curr_vertex] + matrix_[curr_vertex][i])
						paths_[i] = paths_[curr_vertex] + matrix_[curr_vertex][i];
				}
			}
		}
		calculated_ = true;
	}

	const std::vector<double> dejkstra_paths::get_min_paths(const int start_vertex)
	{
		if (!calculated_ || start_vertex != start_vertex_)
			calculate_paths(start_vertex);
		return paths_;
	}
}