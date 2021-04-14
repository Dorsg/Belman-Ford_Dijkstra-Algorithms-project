#include "AdjacencyList.h"

namespace graphEx {
    AdjList::AdjList() : adjList(nullptr), numberOfVertexes(0) {}

    AdjList::~AdjList() 
    {
        delete adjList;        
    }

    void AdjList::MakeGraph(int _numberOfVertexes)
    {
        adjList = new List[_numberOfVertexes];
        numberOfVertexes = _numberOfVertexes;
    }

    List AdjList::NeighborList(int vertex)
    {
        return adjList[vertex];
    }

    void AdjList::AddEdge(int vertex1, int vertex2, int weight)
    {
        Edge toAdd = { vertex1, vertex2, weight };
        adjList[vertex1].AddToLst(toAdd);
    }

    void AdjList::DeleteEdge(int vertex1, int vertex2, int weight)
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

}