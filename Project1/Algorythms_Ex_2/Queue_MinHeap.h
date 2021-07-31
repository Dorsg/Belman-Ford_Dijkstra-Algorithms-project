#pragma once
#include "Queue_Base.h"
namespace graphEx{

class Queue_MinHeap : public Queue_Base{
    
private:
    MinHeap heap;
    Item* createHeapArrayFromDeltaArray(DeltaArray& deltaArr);
    
    
public:
    
    Queue_MinHeap();
    
    
    void Build(DeltaArray& deltaArr); //receive delta array and build minHeap accordingly.
    Item DeleteMin();           //returns the min key and deletes it
    bool IsEmpty();             //returns true if the heap is empty, otherwise returns false
    void DecreaseKey(int vertex, float newKey);
    
    void displayQueue();
   
    
    
    
    
};
}
