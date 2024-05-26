#include "Graph.hpp"

namespace ariel
{



int Graph::getValue(int i, int j){
	return this->m[i][j];
}

vector<int> Graph::getLine(int i){
	return this->m[i];
}

int Graph::getSize(){
	return this->size;
}

void Graph::loadGraph(vector<vector<int>> m){
	if (m.size() == m[0].size()) {
		this->size = m.size();
		this->m = m;
	}
}

string Graph::printGraph(){
	string s = "";
	for (int i = 0; i < this->size; i++){
		s += i + "connected to: ";
		for (int j = 0; j < this->size; j++){
			if (i == j) continue;
			s += j + " ";
		}
		s += "\n";
	}
	return s;
}

Graph operator + (const Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) perror("must be of same size");
	vector<vector<int>> m(obj1.size, vector(obj1.size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			m[i][j] = obj1.m[i][j] + obj2.m[i][j];

	Graph g;
	g.loadGraph(m);
	return g;
}

Graph operator - (const Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) perror("must be of same size");
	vector<vector<int>> m(obj1.size, vector(obj1.size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			m[i][j] = obj1.m[i][j] - obj2.m[i][j];

	Graph g;
	g.loadGraph(m);
	return g;
}



Graph operator += (Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) perror("must be of same size");

	vector<vector<int>> m(obj1.size, vector(obj1.size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			m[i][j] = obj1.m[i][j] + obj2.m[i][j];

	obj1.loadGraph(m);
	return obj1;
}

Graph operator -= (Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) perror("must be of same size");

	vector<vector<int>> m(obj1.size, vector(obj1.size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			m[i][j] = obj1.m[i][j] - obj2.m[i][j];

	obj1.loadGraph(m);
	return obj1;
}



Graph Graph::operator ++ (){
	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; j++)
			this->m[i][j]++;

	return *this;
}

Graph Graph::operator -- (){
	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; j++)
			this->m[i][j]--;

	return *this;
}


bool operator == (const Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) return false;
	bool res = true;

	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++)
			res &= obj1.m[i][j] == obj2.m[i][j];

	return res;

}

bool operator != (const Graph& obj1, const Graph& obj2){
	if (obj1.size != obj2.size) return false;
	bool res = true;

	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++)
			res &= obj1.m[i][j] == obj2.m[i][j];

	return !res;
}


bool operator < (const Graph& obj1, const Graph& obj2){
	if (obj1.size < obj2.size) return true;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++){
			if (obj1.m[i][j] != 0) count1++;
			else if (obj2.m[i][j] != 0) count2++;
		}

	return count1 < count2;
}

bool operator <= (const Graph& obj1, const Graph& obj2){
	if (obj1.size < obj2.size) return true;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++){
			if (obj1.m[i][j] != 0) count1++;
			else if (obj2.m[i][j] != 0) count2++;
		}

	return count1 <= count2;
}


bool operator > (const Graph& obj1, const Graph& obj2){
	if (obj1.size > obj2.size) return true;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++){
			if (obj1.m[i][j] != 0) count1++;
			else if (obj2.m[i][j] != 0) count2++;
		}

	return count1 > count2;
}

bool operator >= (const Graph& obj1, const Graph& obj2){
	if (obj1.size > obj2.size) return true;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < obj1.size; i++)
		for (int j = 0; j < obj1.size; j++){
			if (obj1.m[i][j] != 0) count1++;
			else if (obj2.m[i][j] != 0) count2++;
		}

	return count1 >= count2;
}

Graph Graph::operator * (int num){
	vector<vector<int>> m(this->size, vector(this->size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			m[i][j] = this->m[i][j] * num;

	Graph g;
	g.loadGraph(m);
	return g;
}
Graph operator * (const Graph& obj1, const Graph& obj2){
	vector<vector<int>> m(obj1.size, vector(obj1.size, 0));

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m.size(); j++)
			for (int k = 0; k < m.size(); k++)
				m[i][j] += obj1.m[i][k] * obj1.m[k][j];

	Graph g;
	g.loadGraph(m);
	return g;
}

}