#pragma once
#include <iostream>
#include <float.h>

#define INFINITY FLT_MAX //highest value in float type

using namespace std;
namespace graphEx{

struct Pair {
    int vertex;
    float delta;
};

class DeltaArray{
private:
    Pair* deltaArr;
    int numberOfVertexes;
    
    
   
public:
    
    DeltaArray();
    DeltaArray(int _numberOfVertexes);
    ~DeltaArray();
    
    void setStartVertex(int startVertex){deltaArr[startVertex-1].delta = 0;}
    void displayDeltaArr();
    int getNumberOfVertexes(){return numberOfVertexes;}
    const Pair getPairByVertex(int index){return deltaArr[index-1];}
    void setDeltaByVertex(int vertexToSet, float newDelta);
    
};

}
