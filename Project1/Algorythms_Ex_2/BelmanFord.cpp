#include "BelmanFord.h"

namespace graphEx {

    BelmanFord::BelmanFord(int numberOfVertex, int sourceVertex, Graph* graph) :numberOfVertex(numberOfVertex), dArr(numberOfVertex), graph(graph), pArr(new int[numberOfVertex]) {
        dArr.setStartVertex(sourceVertex);
        for (int i = 0; i < numberOfVertex; ++i) {
            pArr[i] = NO_PARENT;
        }

    }

    BelmanFord::~BelmanFord()
    {
        if (pArr)
            delete[] pArr;
    }

    bool BelmanFord::executeAlgorythm()
    {
        for (int i = 1; i <= numberOfVertex; i++)
        {
            for (int u = 1; u <= numberOfVertex; u++)
            {
                List neighborList;
                neighborList = graph->GetAdjList(u);

                Node* currNeighbor = neighborList.getHead();

                while (currNeighbor) {
                    Edge edge = currNeighbor->getData();
                    int neighbor = edge.dest;
                    float weight = edge.weight;

                    relax(u, neighbor, weight);

                    currNeighbor = currNeighbor->getNext();
                }
            }
        }

        // check for negative cycle
        for (int u = 1; u <= numberOfVertex; u++)
        {
            List neighborList;
            neighborList = graph->GetAdjList(u);

            Node* currNeighbor = neighborList.getHead();

            while (currNeighbor) {
                Edge edge = currNeighbor->getData();
                int neighbor = edge.dest;
                float weight = edge.weight;

                if (relax(u, neighbor, weight))
                {   // throwing exeption because we are not supposed to get a negative cycle in our input graphs
                    throw (string)"Invalid input: there is a negative cycle inside the graph"; 
                    return false;
                }

                currNeighbor = currNeighbor->getNext();
            }
        }

        return true;
    }

    bool BelmanFord::relax(int vertex, int neighbor, float weight)
    {
        float vertexDelta = dArr.getPairByVertex(vertex).delta;
        float neighborDelta = dArr.getPairByVertex(neighbor).delta;

        if (vertexDelta + weight < neighborDelta) {
            dArr.setDeltaByVertex(neighbor, vertexDelta + weight);
            pArr[neighbor - 1] = vertex;
            return true;
        }

        return false;

    }

    void BelmanFord::displayTree()
    {

        cout << "Parents arr:" << endl;
        cout << "-----------" << endl;
        for (int i = 0; i < numberOfVertex; ++i)
            cout << "|Vertex: " << i + 1 << " Patrent: " << pArr[i] << "|";

    }

    float BelmanFord::calcShortestPathToTarget(int dest)
    {
        return dArr.getPairByVertex(dest).delta;
    }

}