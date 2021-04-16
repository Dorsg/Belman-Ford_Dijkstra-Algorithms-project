#pragma once
#include "Edge.h"
#include "List.h"


using namespace std;
namespace graphEx {

	enum edgeSymbol
	{
		no_edge,
	} edgeSymbol;


	class AdjacencyMatrix {
	private:
		int numberOfVertexes;
		int** matrix;


	public:
		//ctors and dtor
		AdjacencyMatrix();
		AdjacencyMatrix(int n);
		~AdjacencyMatrix();


		void makeEmptyGraph(int n);
		bool isAdjacent(int u, int v);
		List getAdjList(int u);
		bool addEdge(int u, int v, int c);
		void removeEdge(int u, int v);
		void displayMatrix();

	};

}
