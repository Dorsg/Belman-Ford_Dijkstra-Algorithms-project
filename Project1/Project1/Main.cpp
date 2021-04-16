#include <iostream>
#include <string>
#include <fstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "List.h"
#include "Edge.h"

using namespace std;
using namespace graphEx;

void main(int argc, char** argv)
{
    /*ifstream input; 
    int numberOfVertexes, start, target; 
    int tempSource, tempDest, tempWeight;
    Edge tempEdge;

    input.open(argv[1]); 
    if (!input) { 
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    input >> numberOfVertexes;
    input >> start;
    input >> target;

    AdjList adjacencyList;
    adjacencyList.MakeGraph(numberOfVertexes);
   // cout << numberOfVertexes << " " << start << " " << target << endl;

    while (!input.eof()) { 
        input >> tempSource;
        input >> tempDest;
        input >> tempWeight;

        adjacencyList.AddEdge(tempSource, tempDest, tempWeight);
        //cout << tempSource << " " << tempDest << " " << tempWeight << endl;

    }

    adjacencyList.DisplayGraph();


    input.close();
    cout << "End-of-file reached.." << endl;

	*/

	AdjacencyMatrix adjacencyMatrix(10);

	adjacencyMatrix.displayMatrix;
    
}


