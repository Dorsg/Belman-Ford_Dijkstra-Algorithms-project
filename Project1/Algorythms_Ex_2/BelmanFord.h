#pragma once
#include "Graph.h"
#include "DeltaArray.h"

#define NO_PARENT -1

namespace graphEx {

    class BelmanFord {

    private:
	   DeltaArray dArr; //delta array
	   int* pArr; //parents array
	   int numberOfVertex;
	   Graph* graph;

    public:

	   BelmanFord(int numberOfVertex, int sourceVertex, Graph* graph);
	   ~BelmanFord();

	   bool executeAlgorythm();
	   bool relax(int vertex, int neighbor, float weight);
	   void displayTree();

	   float calcShortestPathToTarget(int dest);
    };
}