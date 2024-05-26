#ifndef PERSON_HPP
#define PERSON_HPP

#include "Algorithms.hpp"

namespace ariel
{

bool Algorithms::isConnected(Graph g){
	int n = g.getSize();
	vector<bool> visited(n, false);
	dfs(g, 0, visited);
	bool res = true;
	for (int i = 0; i < n; i++) res &= visited[i];
	return res;
}
 
void dfs(Graph g, int start, vector<bool>& visited)
{
    visited[start] = true;
    for (int i = 0; i < g.getSize(); i++)
        if (g.getValue(start, i) == 1 && (!visited[i]))
            dfs(g, i, visited);
}

string Algorithms::shortestPath(Graph g, int start, int end){
	int n = g.getSize();
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);
	vector<int> last(n, 0);
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && g.getValue(u, v) && dist[u] != INT_MAX && dist[u] + g.getValue(u, v) < dist[v]) {
                dist[v] = dist[u] + g.getValue(u, v);
				last[v] = u;
			}
    }
	vector<int> path;
	int i = end;
	for (; i != start; i = last[i]) path.push_back(i);
	path.push_back(i);
	string str = "";
	for (i = path.size() - 1; i >= 0; i--) str += path[i] + " -> ";
	return str;	

}

int minDistance(vector<int> dist, vector<bool> sptSet)
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < dist.size(); i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}


bool Algorithms::isContainsCycle(Graph g){
	int n = g.getSize();
	vector<bool> visited(n, false);
	vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++)
        return !visited[i] && isCyclicUtil(g, i, visited, recStack);
    return false;
}

bool isCyclicUtil(Graph g, int v, vector<bool> visited, vector<bool> recStack) {
    if (visited[v] == true) {
		recStack[v] = false;
    	return false;
	}
	visited[v] = true;
	recStack[v] = true;

	for (int i = 0; i < g.getSize(); i++)
		return (!visited[g.getValue(v, i)] && isCyclicUtil(g, g.getValue(v, i), visited, recStack)) || (recStack[g.getValue(v, i)]);
}

string Algorithms::isBipartite(Graph g){

}

}

#endif