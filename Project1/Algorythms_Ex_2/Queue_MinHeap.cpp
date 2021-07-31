
#include "Queue_MinHeap.h"

namespace graphEx{

Queue_MinHeap:: Queue_MinHeap() : heap(0){}


void Queue_MinHeap:: Build(DeltaArray& deltaArr){
     
    Item* itemArray = createHeapArrayFromDeltaArray(deltaArr);
    int numberOfVertexes = deltaArr.getNumberOfVertexes();
    
    heap.buildHeapFloyd(itemArray, numberOfVertexes);
    
    delete [] itemArray;
}

Item Queue_MinHeap:: DeleteMin(){
    
    return heap.deleteMin();
}

bool Queue_MinHeap:: IsEmpty(){
    
    return heap.isEmpty();
}

Item* Queue_MinHeap::createHeapArrayFromDeltaArray(DeltaArray& deltaArr){
    int arraySize = deltaArr.getNumberOfVertexes();
    Item* itemArr = new Item[arraySize];
    
    for(int i = 0;i<arraySize;++i){
        Pair p = deltaArr.getPairByVertex(i+1);
        
        itemArr[i].data_vertex = p.vertex;
        itemArr[i].key_delta = p.delta;
    }
    
    return itemArr;
}

void Queue_MinHeap::DecreaseKey(int vertex, float newKey) {
    heap.decreaseKey(vertex, newKey);
}

void Queue_MinHeap::displayQueue() {
    cout << "Displaying Queue:" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "As array:" << endl; heap.displayHeapAsArray(); cout << endl << endl;;
    cout << "As heap: " << endl; heap.displayHeapAsMinHeap(); cout << endl;
    cout << "Veretx to index in heap arr: " << endl;
    heap.displayVertexToIndexArr();
    

}





}
