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
		friend Graph operator * (const Graph& obj1, const Graph& obj2);

		ostream& operator << (ostream& s)
		{
			s << this->printGraph();
			return s;
		}
};
}

#endif