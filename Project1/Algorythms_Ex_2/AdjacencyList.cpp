
#include <iostream>
#include "AdjacencyList.h"

namespace graphEx {
    AdjacencyList::AdjacencyList() : adjList(nullptr), numberOfVertexes(0) {}

    AdjacencyList::AdjacencyList(int _numberOfVertexes, ifstream& input) {
        int tempSource, tempDest;
        float tempWeight;

        adjList = new List[_numberOfVertexes];
        numberOfVertexes = _numberOfVertexes;

        while (!input.eof()) {
            if (input.eof()) break;

            input >> tempSource;
            input >> tempDest;
            input >> tempWeight;
            
            if (tempWeight < 0)           
                (string)"Invalid input: one of the egdes with a negetive weight";

            AddEdge(tempSource, tempDest, tempWeight);
        }
        input.clear();
    }

    AdjacencyList::~AdjacencyList()
    {
        delete[] adjList;
    }

    void AdjacencyList::MakeEmptyGraph(int _numberOfVertexes)
    {
        adjList = new List[_numberOfVertexes];
        numberOfVertexes = _numberOfVertexes;
    }

    List AdjacencyList::GetAdjList(int vertex)
    {
        return adjList[vertex-1];
    }

    void AdjacencyList::AddEdge(int vertex1, int vertex2, float weight)
    {
        Edge toAdd = { vertex1, vertex2, weight };

        if(!IsAdjacent(vertex1,vertex2))
            adjList[vertex1-1].AddToLst(toAdd);
    }

    const bool AdjacencyList::IsAdjacent(int vertex1, int vertex2)
    {
        Node* temp = adjList[vertex1-1].getHead();
        Edge currEdge;

        while (temp)
        {
            currEdge = temp->getData();
            if (currEdge.dest == vertex2)
                return true;
            temp = temp->getNext();
        }

        return false;
    }

    void AdjacencyList::RemoveEdge(int vertex1, int vertex2, float weight)
    {
        Edge toDelete = { vertex1, vertex2, weight };

        for (int i = 0; i < numberOfVertexes; i++)
        {
            if (adjList[i].findDataInList(toDelete))
            {
                adjList[i].removeFromList(toDelete);
                break;
            }
        }
    }

    void AdjacencyList::DisplayGraph()
    {
        for (int i = 0; i < numberOfVertexes; i++)
        {
            cout << "vertex number " << i + 1 << " : ";
            adjList[i].DisplayList();
            cout << endl;
        }
    }

    void AdjacencyList::FillGraph(ifstream& input)
    {

        int source, dest, weight;

        while (!input.eof())
        {
            if (input.eof()) break;

            input >> source;
            input >> dest;
            input >> weight;

            AddEdge(source, dest, weight);

        }
    }

}