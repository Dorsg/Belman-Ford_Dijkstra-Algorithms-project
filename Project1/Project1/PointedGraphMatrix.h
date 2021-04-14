#pragma once
#include "Edge.h"
#include "List.h"


using namespace std;
namespace graphEx {

	enum edgeSymbol
	{
		no_edge,
		edge
	} edgeSymbol;


	class PointedGraphMatrix {
	private:
		int numberOfVertexes;
		Edge** matrix;


	public:
		//ctors and dtor
		PointedGraphMatrix();
		PointedGraphMatrix(int n);
		~PointedGraphMatrix();


		void makeEmptyGraph(int n);
		bool isAdjacent(int u, int v);
		List getAdjList(int u);
		bool addEdge(int u, int v, int c);
		void removeEdge(int u, int v);

	};

}
