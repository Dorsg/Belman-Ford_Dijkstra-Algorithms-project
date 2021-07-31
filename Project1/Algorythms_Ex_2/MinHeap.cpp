#include "MinHeap.h"


using namespace std;


namespace graphEx {



    MinHeap::MinHeap(int max)
    {
        if (max == 0) {
            arr = nullptr;
            heapSize = 0;
            maxSize = 0;
            return;

        }

        arr = new Item[max];
        vertexToIndexArr = new int[max];
        maxSize = max;
        heapSize = 0;
    }
    MinHeap::MinHeap(Item* _arr, int n)
    {
        buildHeapFloyd(_arr, n);

    }
    MinHeap::~MinHeap()
    {

        if (arr)
            delete[] arr;
        if (vertexToIndexArr)
            delete[] vertexToIndexArr;
    }
    void MinHeap::buildHeapFloyd(Item* _arr, int n) {

        heapSize = maxSize = initSize = n;

        arr = new Item[heapSize];
        vertexToIndexArr = new int[heapSize];

        //copying the array to heap object
        for (int i = 0; i < heapSize; ++i) {
            arr[i] = _arr[i];
            updateVertexToIndexArr(arr[i].data_vertex, i);
        }

        for (int i = n / 2 - 1; i >= 0; --i) {
            fixHeap(i);
        }


    }
    void MinHeap::fixHeap(int i)
    {
        int min;
        int leftChildIndex = left(i);
        int rightChildIndex = right(i);

        if (leftChildIndex < heapSize && arr[leftChildIndex].key_delta < arr[i].key_delta)
            min = leftChildIndex;
        else min = i;

        if (rightChildIndex < heapSize && arr[rightChildIndex].key_delta < arr[min].key_delta)
            min = rightChildIndex;

        if (min != i) {
            swap(arr[i], arr[min]);
            updateVertexToIndexArr(arr[i].data_vertex, i);
            updateVertexToIndexArr(arr[min].data_vertex, min);
        }

    }
    Item MinHeap::min()
    {
        return arr[0];
    }
    Item MinHeap::deleteMin()
    {
        Item min = arr[0];

        heapSize--;
       
        updateVertexToIndexArr(arr[0].data_vertex, NO_INDEX);
        if (heapSize != 0) {
            arr[0] = arr[heapSize];
            updateVertexToIndexArr(arr[0].data_vertex, 0);
        }

       
        heapifyDown(0);

        return min;
    }
    void MinHeap::insert(Item item)
    {

        arr[heapSize] = item;
        updateVertexToIndexArr(arr[heapSize].data_vertex, heapSize);
        heapSize++;
        int index = heapSize - 1;
        heapifyUp(index);
        

    }
    void MinHeap::swap(Item& x, Item& y)
    {
        Item temp = x;
        x = y;
        y = temp;

    }
    void MinHeap::makeEmpty(){
        //updating vertexToIndexArray with NO INDEX value.
        
        heapSize = maxSize = 0; 
       
    }
    void MinHeap::heapifyDown(int index) {
        // get left and right child of node at index `index`
        int leftChild = left(index);
        int rightChild = right(index);

        int min = index;

        // compare `A[i]` with its left and right child
        // and find the min value
        if (leftChild < heapSize && (arr[leftChild].key_delta < arr[min].key_delta)) {
            min = leftChild;
        }

        if (rightChild < heapSize && arr[rightChild].key_delta < arr[min].key_delta) {
            min = rightChild;
        }

        // swap with a child having greater value and
        // call heapify-down on the child
        if (min != index)
        {
            swap(arr[index], arr[min]);
            updateVertexToIndexArr(arr[index].data_vertex, index);
            updateVertexToIndexArr(arr[min].data_vertex, min);
            heapifyDown(min);
        }

    }
    void MinHeap::heapifyUp(int index) {

        // check if the node at index `index` and its parent violate the heap arrangement

        if (index == 0)
            return;

        if (arr[parent(index)].key_delta > arr[index].key_delta)
        {
            // swap the two if heap property is violated
            swap(arr[index], arr[parent(index)]);
            updateVertexToIndexArr(arr[index].data_vertex, index);
            updateVertexToIndexArr(arr[parent(index)].data_vertex, parent(index));

            // call heapify-up on the parent
            heapifyUp(parent(index));
        }
    }







    void MinHeap::decreaseKey(int vertexToChange, float newKey) {
        int indexToChange = getIndexOfVertex(vertexToChange);
        arr[indexToChange].key_delta = newKey;
        heapifyUp(indexToChange);
    }
    







    void MinHeap::updateVertexToIndexArr(int vertexToUpdate,int indexInHeapArray) {
        
        vertexToIndexArr[vertexToUpdate - 1] = indexInHeapArray;
    }
    void MinHeap::displayVertexToIndexArr() {

        
        for (int i = 0; i < initSize; ++i) {
            
            
            cout << "|vertex: " << i+1 << " its index in heap array: " << vertexToIndexArr[i] << "|" << endl;


        }

        cout << endl;
        

    }
    void MinHeap::displayHeapAsArray() {
        //first, copying the heap to temp heap, in order to save the data. after displaying the heap, getting the data back to heap from temp heap.
       
        for (int i = 0; i < heapSize; ++i) {
            cout << "|key: " << arr[i].key_delta << " vertex: " << arr[i].data_vertex << "|";
        }

    }
    void MinHeap::displayHeapAsMinHeap() {
        int size = getHeapSize();
        Item* tempArr = new Item[size];
        for (int i = 0; i < size; ++i) {
            tempArr[i] = arr[i];
        }

        while (heapSize > 0) {


            Item curr = deleteMin();
            cout << "|key: " << curr.key_delta << " vertex: " << curr.data_vertex << "|" << endl;

        }

        


        for (int i = 0; i < size; ++i) {
            insert(tempArr[i]);
        }

        delete[] tempArr;

    }
   
}
   

