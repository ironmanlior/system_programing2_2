#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
	class Graph {
	private:
		int size;
		vector<vector<int>> m;

	public:
		int getValue(int i, int j);
		vector<int> getLine(int i);
		int getSize();
		void loadGraph(vector<vector<int>> m);
		string printGraph();

		friend Graph operator + (const Graph& obj1, const Graph& obj2);
		friend Graph operator += (Graph& obj1, const Graph& obj2);
		Graph operator ++ ();

		friend Graph operator - (const Graph& obj1, const Graph& obj2);
		friend Graph operator -= (Graph& obj1, const Graph& obj2);
		Graph operator -- ();

		friend bool operator == (const Graph& obj1, const Graph& obj2);
		friend bool operator != (const Graph& obj1, const Graph& obj2);

		friend bool operator < (const Graph& obj1, const Graph& obj2);
		friend bool operator <= (const Graph& obj1, const Graph& obj2);
		
		friend bool operator > (const Graph& obj1, const Graph& obj2);
		friend bool operator >= (const Graph& obj1, const Graph& obj2);

		Graph operator * (int num);
		Graph operator *= (int num);
		Graph operator / (int num);
		Graph operator /= (int num);
		friend Graph operator * (const Graph& obj1, const Graph& obj2);

		friend ostream& operator << (ostream &out, const Graph &c)
		{
			for (int i = 0; i < c.size; i++){
				out << "[";
				for (int j = 0; j < c.size; j++){
					out <<c.m[i][j] << (j != c.size - 1 ? ", " : "");
				}
				out << "]" << endl;
			}
			out << endl;
			return out;
		}
	};
}

#endif