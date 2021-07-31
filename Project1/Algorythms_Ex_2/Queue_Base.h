#pragma once
#pragma once
#include "DeltaArray.h"
#include "MinHeap.h"
using namespace std;

namespace graphEx {

    class Queue_Base {
    private:

        virtual Item* createHeapArrayFromDeltaArray(DeltaArray& deltaArr) = 0;
        

    public:
         Queue_Base(){}
         virtual ~Queue_Base(){}

         virtual void Build(DeltaArray& deltaArr) = 0;
         virtual Item DeleteMin() = 0;
         virtual bool IsEmpty() = 0;
         virtual void DecreaseKey(int vertex, float newKey) = 0;

         virtual void displayQueue() = 0;

       
    };




}


