#include "DeltaArray.h"

namespace graphEx{

DeltaArray::DeltaArray() : deltaArr(nullptr){}
DeltaArray::DeltaArray(int _numberOfVertexes) : deltaArr(new Pair[_numberOfVertexes]), numberOfVertexes(_numberOfVertexes){
    
    for(int i=0;i<numberOfVertexes;++i){
        deltaArr[i].vertex = i+1;
        deltaArr[i].delta = INFINITY;
    }
    
}
DeltaArray::~DeltaArray(){
    if(deltaArr)
        delete [] deltaArr;
    numberOfVertexes = 0;
}

void DeltaArray:: displayDeltaArr(){
    cout << endl << "Displaying DeltaArr:" << endl;
    
    Pair currPair;
    for(int i=0;i<numberOfVertexes; ++i){
        currPair = deltaArr[i];
        cout<<"|vertex: |" << currPair.vertex << "|delta: |" << currPair.delta<<endl;
    }

    cout << endl;
  
    
}

void DeltaArray::setDeltaByVertex(int vertexToSet,float newDelta){
    deltaArr[vertexToSet-1].delta = newDelta;
    
}



}
