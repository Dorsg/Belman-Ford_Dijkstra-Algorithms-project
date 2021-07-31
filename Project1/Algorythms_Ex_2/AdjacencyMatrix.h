#pragma once
#include "List.h"
#include <iostream>
#include "Graph.h"


using namespace std;
namespace graphEx {

    struct Matrix_Edge
    {
        float weight;
        bool isExsist;
    };


    class AdjacencyMatrix : public Graph {
    private:
        int numberOfVertexes;
        Matrix_Edge** matrix;

    public:
        AdjacencyMatrix();
        AdjacencyMatrix(int _numberOfVertexes, ifstream& input);
        ~AdjacencyMatrix();

        void MakeEmptyGraph(int numberOfVertexes);
        void AddEdge(int vertexU, int vertexV, float edgeWeight);
        const bool IsAdjacent(int vertexV, int vertexU) { return matrix[vertexU][vertexV].isExsist; }
        List GetAdjList(int u); 
        void DisplayGraph();
        void RemoveEdge(int source, int destination, float weight);
        void FillGraph(ifstream& input);
        int getNumberOfVertexes() { return numberOfVertexes;}
        

        // TEST // 
        //void displayNeighborList(int vertexU); //display a list

        // INTERNAL // 
        void deleteMatrix();
    };
}