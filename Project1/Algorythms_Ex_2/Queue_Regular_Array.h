#pragma once
#include "Queue_Base.h"
using namespace std;

namespace graphEx{

	class Queue_Regular_Array : public Queue_Base{
	private:
        Item* arr;
        int* vertexToIndexArr;
        int indexToMinKey;
        int indexToNextOpenCell;
        int queueLogSize;

        Item* createHeapArrayFromDeltaArray(DeltaArray& deltaArr);
        void updateVertexToIndexArr(int vertexToUpdate, int indexInHeapArray);
        void updateMinKey();

	public:

        Queue_Regular_Array();
        ~Queue_Regular_Array();

        void Build(DeltaArray& deltaArr); //receive delta array and build minHeap accordingly.
        Item DeleteMin();           //returns the min key and deletes it
        bool IsEmpty();             //returns true if the heap is empty, otherwise returns false
        void DecreaseKey(int vertex, float newKey);
        void displayQueue();
	};




}
