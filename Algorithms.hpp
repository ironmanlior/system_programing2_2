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
	public:
		bool isConnected(Graph g);
		string shortestPath(Graph g, int start, int end);
		bool isContainsCycle(Graph g);
		string isBipartite(Graph g);

};
}
#endif