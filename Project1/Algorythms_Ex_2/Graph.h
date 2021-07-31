#pragma once
#include "List.h"
#include <fstream>

namespace graphEx {

    class Graph {

    public:
        virtual void MakeEmptyGraph(int _numberOfVertexes) = 0;
        virtual void AddEdge(int vertex1, int vertex2, float weight) = 0;
        virtual const bool IsAdjacent(int vertex1, int vertex2) = 0;
        virtual void RemoveEdge(int vertex1, int vertex2, float weight) = 0;
        virtual List GetAdjList(int vertex) = 0;
        virtual void DisplayGraph() = 0;
        virtual void FillGraph(ifstream& input) = 0;
        virtual int getNumberOfVertexes() = 0;

        virtual ~Graph() {};

    };

}