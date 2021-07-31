#include "AdjacencyMatrix.h"

using namespace std;

namespace graphEx {

    AdjacencyMatrix::AdjacencyMatrix() : matrix(nullptr), numberOfVertexes(0) {}
    AdjacencyMatrix::AdjacencyMatrix(int _numberOfVertexes, ifstream& input) {
        MakeEmptyGraph(_numberOfVertexes);
        FillGraph(input);
    }

    AdjacencyMatrix:: ~AdjacencyMatrix() {
        deleteMatrix();
    }
    void AdjacencyMatrix::DisplayGraph() {
        for (auto i = 0; i <= numberOfVertexes; ++i) {
            for (auto j = 0; j <= numberOfVertexes; ++j) {
                if (matrix[i][j].isExsist == false)
                    cout << "x  " << " ";
                else
                    cout << matrix[i][j].weight << "   ";
            }
            cout << endl;
        }
    }

    void AdjacencyMatrix::RemoveEdge(int source, int destination, float weight)
    {
        matrix[source][destination].weight = 0;
        matrix[source][destination].isExsist = false;

    }

    void AdjacencyMatrix::FillGraph(ifstream& input)
    {
        int source, dest;
        float weight;

        while (!input.eof())
        {
            if (input.eof()) break;

            input >> source;
            input >> dest;
            input >> weight;

            if (weight < 0)
                throw (string)"Invalid input: one of the egdes with a negetive weight";

            AddEdge(source, dest, weight);

        }
    }

    void AdjacencyMatrix::MakeEmptyGraph(int _numberOfVertexes) {

        if (matrix)
            deleteMatrix();

        numberOfVertexes = _numberOfVertexes;
        matrix = new Matrix_Edge * [numberOfVertexes + 1];

        //alocationg rows
        for (auto i = 0; i < numberOfVertexes + 1; ++i) {
            //alocating the columns
            matrix[i] = new Matrix_Edge[numberOfVertexes + 1];
            for (auto j = 0; j < numberOfVertexes + 1; ++j) {
                if (i == 0) {
                    matrix[i][j].weight = j;
                    matrix[i][j].isExsist = true;
                }

                else if (j == 0) {
                    matrix[i][j].weight = i;
                    matrix[i][j].isExsist = true;
                }
                else {
                    matrix[i][j].weight = 0;
                    matrix[i][j].isExsist = false;
                }

            }
        }



    }

    List AdjacencyMatrix::GetAdjList(int vertexU) {
        List neighborList;

        for (auto vertexToCheck = 1; vertexToCheck <= numberOfVertexes; ++vertexToCheck) {

            Edge edgeToAddToList;
            //when the neighbor is the vertex itself, continueing the loop
            if (vertexU == vertexToCheck)
                continue;
            else if (matrix[vertexU][vertexToCheck].isExsist == true) {

                edgeToAddToList.source = vertexU; //placing the vertex we are checking for its neighbors as the source
                edgeToAddToList.dest = vertexToCheck;
                edgeToAddToList.weight = matrix[vertexU][vertexToCheck].weight;
                neighborList.AddToLst(edgeToAddToList);
            }

        }

        return neighborList;

    }

    //void AdjacencyMatrix::displayNeighborList(int vertexU) {
    //    List neighborList;
    //    neighborList = GetAdjList(vertexU);
    //    neighborList.DisplayList();

    //};


    void AdjacencyMatrix::AddEdge(int vertexU, int vertexV, float edgeWeight) {
        matrix[vertexU][vertexV].isExsist = true;
        matrix[vertexU][vertexV].weight = edgeWeight;
    }

    void AdjacencyMatrix::deleteMatrix() {

        for (auto i = 0; i < numberOfVertexes + 1; ++i) {
            delete[] matrix[i];
        }

        delete[] matrix;

    }

}