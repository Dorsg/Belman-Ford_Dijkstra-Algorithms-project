#include "Dijkstra.h"
#define MIN_HEAP 1
#define REG_ARR_HEAP 2

namespace graphEx {

    Dijkstra::Dijkstra(int numberOfVertex, int sourceVertex, Graph* graph,int queueType) :numberOfVertex(numberOfVertex), dArr(numberOfVertex), graph(graph), pArr(new int[numberOfVertex]), queue(queue) {
        dArr.setStartVertex(sourceVertex);

        if(queueType == MIN_HEAP)
            queue = new Queue_MinHeap();
        else if (queueType == REG_ARR_HEAP)
            queue = new Queue_Regular_Array();

        for (int i = 0; i < numberOfVertex; ++i) {
            pArr[i] = NO_PARENT;
        }

    }
    Dijkstra::~Dijkstra() {
        if (pArr)
            delete[] pArr;

    }

    void Dijkstra::executeAlgorythm() {

       
        queue->Build(dArr);

        while (!queue->IsEmpty()) {

            int vertex = queue->DeleteMin().data_vertex;

            List neighborList;
            neighborList = graph->GetAdjList(vertex);

            Node* curr = neighborList.getHead();

            while (curr) {
                Edge edge = curr->getData();
                int neighbor = edge.dest;
                float weight = edge.weight;

                if (relax(vertex, neighbor, weight) == true) {
                    float newKey = dArr.getPairByVertex(neighbor).delta;
                    queue->DecreaseKey(neighbor, newKey);
                }
                curr = curr->getNext();
            }
        }

    }


    bool Dijkstra::relax(int vertex, int neighbor, float weight) {
        float vertexDelta = dArr.getPairByVertex(vertex).delta;
        float neighborDelta = dArr.getPairByVertex(neighbor).delta;

        if (vertexDelta + weight < neighborDelta) {
            dArr.setDeltaByVertex(neighbor, vertexDelta + weight);
            pArr[neighbor - 1] = vertex;
            return true;
        }

        return false;

    }

    void Dijkstra::displayTree() {

        cout << "Parents arr:" << endl;
        cout << "-----------" << endl;
        for (int i = 0; i < numberOfVertex; ++i) {
            cout << "|Vertex: " << i + 1 << " Patrent: " << pArr[i] << "|";
        }
    }

    float Dijkstra::calcShortestPathToTarget(int dest)
    {
        return dArr.getPairByVertex(dest).delta;
    }

}