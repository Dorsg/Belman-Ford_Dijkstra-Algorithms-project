#pragma once

#include<iostream>
#include<climits>

#define NO_INDEX -1

using namespace std;

namespace graphEx
{
    struct Item {
        float key_delta;
        int data_vertex;
    };

   


    class MinHeap
    {
        Item* arr;
        int* vertexToIndexArr;

        int maxSize;
        int heapSize;
        int initSize;

        void heapifyUp(int index);
        void heapifyDown(int index);
        void swap(Item& x, Item& y);
        int left(int i) { return (2 * i + 1); }
        int right(int i) { return (2 * i + 2); }
        int parent(int i) { return (i - 1) / 2; }
        void fixHeap(int i);
        int getIndexOfVertex(int vertex) { return vertexToIndexArr[vertex - 1];}
        
    public:
        MinHeap(int max);
        MinHeap(Item* arr, int n);
        ~MinHeap();




       
       
        Item min();
        Item deleteMin();
        void insert(Item item);
        int getHeapSize() { return heapSize; }
        bool isEmpty() { return (heapSize == 0); }
        void makeEmpty();
        void buildHeapFloyd(Item* arr, int n);
        void decreaseKey(int vertexToChange, float newKey);
        
       







        void displayHeapAsArray();
        void displayHeapAsMinHeap();
        void updateVertexToIndexArr(int vertexToUpdate, int indexInHeapArray);
        void displayVertexToIndexArr();
    };



}
