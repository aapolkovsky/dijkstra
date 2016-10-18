#ifndef HOMEBREW_DIJKSTRA_HPP
#define HOMEBREW_DIJKSTRA_HPP

#include <vector>
#include <queue>

namespace homebrew
{
	class dejkstra_paths
	{
	public:
		template <typename T>
		using matrix = std::vector<std::vector<T>>;

		dejkstra_paths(std::initializer_list<std::vector<double>> matrix);
		void calculate_paths(const int start_vertex);
		const std::vector<double> get_min_paths(const int start_vertex);

	private:
		size_t size_;
		matrix<double> matrix_;
		std::vector<double> paths_;
		std::vector<bool> visited_;
		bool calculated_;
		int start_vertex_;
	};
}

#endif