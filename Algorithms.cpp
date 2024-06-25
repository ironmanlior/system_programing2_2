#ifndef PERSON_HPP
#define PERSON_HPP

#include "Algorithms.hpp"
#include <climits>
#include <iostream>
 
using namespace std;
namespace ariel
{

bool Algorithms::isConnected(Graph g){
	int n = g.getSize();
	vector<bool> visited(n, false);
	Algorithms::dfs(g, 0, visited);
	bool res = true;
	for (int i = 0; i < n; i++) res &= visited[i];
	return res;
}
 
void Algorithms::dfs(Graph g, int start, vector<bool>& visited)
{
    visited[start] = true;
    for (int i = 0; i < g.getSize(); i++)
        if (g.getValue(start, i) == 1 && (!visited[i]))
            Algorithms::dfs(g, i, visited);
}

string Algorithms::shortestPath(Graph g, int start, int end){
	int n = g.getSize();
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);
	vector<int> last(n, -1);
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = Algorithms::minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && g.getValue(u, v) && dist[u] != INT_MAX && dist[u] + g.getValue(u, v) < dist[v]) {
                dist[v] = dist[u] + g.getValue(u, v);
				last[v] = u;
			}
    }
	vector<int> path;
	int i = end;
	if (last[i] == -1) return "0";
	for (; i != start; i = last[i]) path.push_back(i);
	path.push_back(i);
	string str = "";
	for (i = path.size() - 1; i >= 0; i--) str += to_string(path[i]) + (i == 0 ? "" : "->");
	return str;	

}

int Algorithms::minDistance(vector<int> dist, vector<bool> sptSet)
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
        if(!visited[i] && Algorithms::isCyclicUtil(g, i, visited, recStack)) 
			return true;
    return false;
}

bool Algorithms::isCyclicUtil(Graph g, int v, vector<bool> visited, vector<bool> recStack) {
    if (visited[v] == true) {
		recStack[v] = false;
    	return false;
	}
	visited[v] = true;
	recStack[v] = true;

	for (int i = 0; i < g.getSize(); i++)
		return (!visited[g.getValue(v, i)] && Algorithms::isCyclicUtil(g, g.getValue(v, i), visited, recStack)) || (recStack[g.getValue(v, i)]);
}

string Algorithms::isBipartite(Graph g){
	// Create a color array to store colors 
    // assigned to all vertices. Vertex 
    // number is used as index in this array. 
    // The value '-1' of colorArr[i] 
    // is used to indicate that no color 
    // is assigned to vertex 'i'. The value 1 
    // is used to indicate first color 
    // is assigned and value 0 indicates 
    // second color is assigned.


	vector<int> color(g.getSize(), -1);
 
    color[0] = 1;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
        // Return false if there is a self-loop 
        if (g.getValue(u, u) == 1)
        	return "0"; 
 
        // Find all non-colored adjacent vertices
        for (int v = 0; v < g.getSize(); ++v)
        {
            // An edge from u to v exists and 
            // destination v is not colored
            if (g.getValue(u, v) && color[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                color[v] = 1 - color[u];
                q.push(v);
            }
 
            // An edge from u to v exists and destination 
            // v is colored with same color as u
            else if (g.getValue(u, v) && color[v] == color[u])
                return "0";
        }
    }
 
    // If we reach here, then all adjacent  
    // vertices can be colored with alternate color
	string s = "";
	s += "A={";
	for (int i = 0; i < g.getSize(); i++){
		if (color[i] == 1) s += to_string(i) + (i == g.getSize() - 1 ? "" : ", ");
	}
	s += "}, b={";
	for (int i = 0; i < g.getSize(); i++){
		if (color[i] == 0) s += to_string(i) + (i == g.getSize() - 1 ? "" : ", ");
	}
    return s;
}

}

#endif