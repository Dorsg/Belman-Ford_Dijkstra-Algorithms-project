#pragma once
#include "Edge.h"
using namespace std;

namespace graphEx {

    class Node {
        friend class List;

    private:
        Edge data;
        Node* next;
        Node* prev;

    public:
        Node();
        Node(Edge& _data);

        Edge getData() const { return data; }
        Node* getNext() const { return next; };
    };

    class List {
    private:
        Node* head;
        Node* tail;
        int numberOfNeighbors;

    public:

        List();
        List(List& list);
        ~List();

        int getNumOfArcsInLst() const { return numberOfNeighbors; };
        Node* getHead() { return head; }
        void makeEmpty();
        void AddToLst(Edge& newData);
        bool isLstEmpty() const;
        void removeFromList(Edge& dataToRemove);
        Node* findDataInList(Edge& dataToFind);
        List& operator=(const List& Lst);
        void DisplayList();
        void removeFromHead();
    };


}
