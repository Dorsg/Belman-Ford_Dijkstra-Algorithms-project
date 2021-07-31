//Dor Sabag 307886663
//Niv Gorsky 206094914


#define MIN_HEAP 1
#define REG_ARR_HEAP 2

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ios>
#include <chrono>
#include <float.h>
#include "Graph.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "List.h"
#include "Edge.h"
#include "Dijkstra.h"
#include "BelmanFord.h"
#include "Queue_Base.h"

using namespace std;
using namespace chrono;
using namespace graphEx;

void fileHandler(int& numberOfVertexes, int& start, int& target, ifstream& input,string fname);
void executeAndMeasureAlgorithms(BelmanFord& belmanFordList, Dijkstra& dijkstraListMH, Dijkstra& dijkstraListAMH
                               , BelmanFord& belmanFordMatrix, Dijkstra& dijkstraMatrixMH, Dijkstra& dijkstraMatrixAMH, string fileName);
void calcAndPrintShortestPath(BelmanFord& belmanFordList, Dijkstra& dijkstraListMH, Dijkstra& dijkstraListAMH
                            , BelmanFord& belmanFordMatrix, Dijkstra& dijkstraMatrixMH, Dijkstra& dijkstraMatrixAMH, int target);

int main(int argc, char** argv)
{   
    ifstream inputFile;
    int numberOfVertexes, start, target, fPosition;

    try {
        // get start, target and vertexes number from file 
        fileHandler(numberOfVertexes, start, target, inputFile, argv[1]);

        // creating two graphs (matrix and list) using polymorphism
        fPosition = inputFile.tellg();
        Graph* adjacencyList = new AdjacencyList(numberOfVertexes, inputFile);
        inputFile.seekg(fPosition, inputFile.beg);
        Graph* adjacencyMatrix = new AdjacencyMatrix(numberOfVertexes, inputFile);
       
        // adjacency list system objects
        BelmanFord belmanFordList(numberOfVertexes, start, adjacencyList);
        Dijkstra dijkstraListMH(numberOfVertexes, start, adjacencyList, MIN_HEAP);
        Dijkstra dijkstraListAMH(numberOfVertexes, start, adjacencyList, REG_ARR_HEAP);

        // adjacency matrix system objects
        BelmanFord belmanFordMatrix(numberOfVertexes, start, adjacencyMatrix);
        Dijkstra dijkstraMatrixMH(numberOfVertexes, start, adjacencyMatrix, MIN_HEAP);
        Dijkstra dijkstraMatrixAMH(numberOfVertexes, start, adjacencyMatrix, REG_ARR_HEAP);

        // running all 6 algorithems and writing measures to file 
        executeAndMeasureAlgorithms(belmanFordList, dijkstraListMH, dijkstraListAMH,
                                    belmanFordMatrix, dijkstraMatrixMH, dijkstraMatrixAMH, argv[2]);

        // calculating and printing shortest paths 
        calcAndPrintShortestPath(belmanFordList, dijkstraListMH, dijkstraListAMH,
                                 belmanFordMatrix, dijkstraMatrixMH, dijkstraMatrixAMH, target);
        inputFile.close();
    }
    catch(string exeption){
        cout << exeption << endl << "please try again";
        inputFile.close();
        exit(0);
    }
}

void fileHandler(int& numberOfVertexes, int& start, int& target, ifstream& input, string fname)
{
    input.open(fname);
    if (!input)
        throw (string)"file doesn't exist";

    input >> numberOfVertexes;
    
    if (numberOfVertexes < 0)
        throw (string)"number of vertexes is negative";

    input >> start;
    
    if (start < 0 || start > numberOfVertexes)
        throw (string)"invalid start number";    
    
    input >> target;

    if (target < 0 || target > numberOfVertexes)
        throw (string)"invalid target number";
}

void executeAndMeasureAlgorithms(BelmanFord& belmanFordList, Dijkstra& dijkstraListMH, Dijkstra& dijkstraListAMH,
                                 BelmanFord& belmanFordMatrix, Dijkstra& dijkstraMatrixMH, Dijkstra& dijkstraMatrixAMH, string fileName)
{   //(1)
    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    belmanFordList.executeAlgorythm();
    auto end1 = chrono::high_resolution_clock::now();
    double belmanFordListT = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    belmanFordListT *= 1e-9;
    //(2)
    auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    dijkstraListMH.executeAlgorythm();
    auto end2 = chrono::high_resolution_clock::now();
    double dijkstraListMHT = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    dijkstraListMHT *= 1e-9;
    //(3)
    auto start3 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    dijkstraListAMH.executeAlgorythm();
    auto end3 = chrono::high_resolution_clock::now();
    double dijkstraListAMHT = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
    dijkstraListAMHT *= 1e-9;
    //(4)
    auto start4 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    belmanFordMatrix.executeAlgorythm();
    auto end4 = chrono::high_resolution_clock::now();
    double belmanFordMatrixT = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();
    belmanFordMatrixT *= 1e-9;
    //(5)
    auto start5 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    dijkstraMatrixMH.executeAlgorythm();
    auto end5 = chrono::high_resolution_clock::now();
    double dijkstraMatrixMHT = chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();
    dijkstraMatrixMHT *= 1e-9;
    //(6)
    auto start6 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    dijkstraMatrixAMH.executeAlgorythm();
    auto end6 = chrono::high_resolution_clock::now();
    double dijkstraMatrixAMHT = chrono::duration_cast<chrono::nanoseconds>(end6 - start6).count();
    dijkstraMatrixAMHT *= 1e-9;

    //writing to file:-------------------------------------------------
    ofstream myfile(fileName);

    myfile << "Adjacency Dijkstra heap " << fixed
        << dijkstraListMHT << "\n" << setprecision(9);
    myfile << "Adjacency Dijkstra array " << fixed
        << dijkstraListAMHT << "\n" << setprecision(9);
    myfile << "Adjacency Bellman Ford " << fixed
        << belmanFordListT << "\n" << setprecision(9);
    myfile << "Matrix Dijkstra heap " << fixed
        << dijkstraMatrixMHT << "\n" << setprecision(9);
    myfile << "Matrix Dijkstra array " << fixed
        << dijkstraMatrixAMHT << "\n" << setprecision(9);
    myfile << "Matrix Bellman Ford " << fixed
        << belmanFordMatrixT << "\n" << setprecision(9);

    myfile.close();
}

void calcAndPrintShortestPath(BelmanFord& belmanFordList, Dijkstra& dijkstraListMH, Dijkstra& dijkstraListAMH
                            , BelmanFord& belmanFordMatrix, Dijkstra& dijkstraMatrixMH, Dijkstra& dijkstraMatrixAMH, int target) {
   
    float belmanFordListRes = belmanFordList.calcShortestPathToTarget(target);
    float dijkstraListMHpRes = dijkstraListMH.calcShortestPathToTarget(target);
    float dijkstraListAMHRes = dijkstraListAMH.calcShortestPathToTarget(target);
    float belmanFordMatrixRes = belmanFordMatrix.calcShortestPathToTarget(target);
    float dijkstraMatrixMHRes = dijkstraMatrixMH.calcShortestPathToTarget(target);
    float dijkstraMatrixAMHRes = dijkstraMatrixAMH.calcShortestPathToTarget(target);

    

    if (belmanFordMatrixRes == INFINITY)
        throw (string)"No Route";

    // printing results:------------------------------------------
    cout << "Adjacency Dijkstra heap " << dijkstraListMHpRes << endl <<
        "Adjacency Dijkstra array " << dijkstraListAMHRes << endl <<
        "Adjacency Bellman Ford " << belmanFordListRes << endl <<
        "Matrix Dijkstra heap " << dijkstraMatrixMHRes << endl <<
        "Matrix Dijkstra array " << dijkstraMatrixAMHRes << endl <<
        "Matrix Bellman Ford " << belmanFordMatrixRes << endl;

}