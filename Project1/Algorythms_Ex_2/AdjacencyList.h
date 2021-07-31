#pragma once
#include "List.h"
#include "Graph.h"

namespace graphEx {

    class AdjacencyList : public Graph{
    private:
        List* adjList;
        int numberOfVertexes;

    public:
        AdjacencyList(int _numberOfVertexes, ifstream& input);
        AdjacencyList();
        ~AdjacencyList();

        void MakeEmptyGraph(int _numberOfVertexes);
        void AddEdge(int vertex1, int vertex2, float weight);
        const bool IsAdjacent(int vertex1, int vertex2);
        void RemoveEdge(int vertex1, int vertex2, float weight);
        List GetAdjList(int vertex);
        void DisplayGraph();
        void FillGraph(ifstream& input);
        int getNumberOfVertexes() { return numberOfVertexes;}

    };
}
