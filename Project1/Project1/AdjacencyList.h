#pragma once
#include "List.h"

namespace graphEx {

    class AdjList {
    private:
        List* adjList;
        int numberOfVertexes;

    public:
        AdjList();
        ~AdjList();

        void MakeGraph(int _numberOfVertexes);
        List NeighborList(int vertex);
        void AddEdge(int vertex1, int vertex2, int weight);
        void DeleteEdge(int vertex1, int vertex2, int weight);
        void DisplayGraph();

    };
}
