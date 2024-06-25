#ifndef ALGO
#define ALGO

#include "Graph.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <utility>
namespace ariel
{
	class Algorithms{
		private:
			static int minDistance(vector<int> dist, vector<bool> sptSet);
			static bool isCyclicUtil(Graph g, int v, vector<bool> visited, vector<bool> recStack);
			static void dfs(Graph g, int start, vector<bool>& visited);
		public:
			static bool isConnected(Graph g);
			static string shortestPath(Graph g, int start, int end);
			static bool isContainsCycle(Graph g);
			static string isBipartite(Graph g);

	};
}
#endif