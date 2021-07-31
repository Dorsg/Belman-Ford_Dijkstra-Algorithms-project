#pragma once
#include "Queue_Regular_Array.h"
#include "Queue_MinHeap.h"
#include "Graph.h"

#define NO_PARENT -1



namespace graphEx {

	class Dijkstra {

	private:
		DeltaArray dArr; //delta array
		int* pArr; //parents array
		int numberOfVertex;
		Graph* graph;
		Queue_Base* queue;

	public:

		Dijkstra(int numberOfVertex, int sourceVertex, Graph* graph, int queueType);
		~Dijkstra();

		void executeAlgorythm();
		bool relax(int vertex, int neighbor, float weight);
		void displayTree();
		float calcShortestPathToTarget(int dest);
	};
}