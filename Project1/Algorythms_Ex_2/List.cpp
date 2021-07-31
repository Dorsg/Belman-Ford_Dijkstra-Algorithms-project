#include "List.h"
#include <iostream>

using namespace std;

namespace graphEx {

    Node::Node() : next(nullptr), prev(nullptr) {
        data.weight = 0;
        data.source = -1;
        data.dest = -1;
    }

    Node::Node(Edge& _data) : next(nullptr), prev(nullptr) {
        data = _data;
    }

    List::List() : numberOfNeighbors(0), head(nullptr), tail(nullptr) {}

    List::~List() {
        makeEmpty();
    }

    void List::makeEmpty() {
        Node* tmp = head;

        while (head) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        numberOfNeighbors = 0;

    }

    void List::AddToLst(Edge& newData) {
        Node* toAdd = new Node(newData);
        if (isLstEmpty())
            head = tail = toAdd;
        else {
            tail->next = toAdd;
            toAdd->prev = tail;
            tail = toAdd;
        }
        numberOfNeighbors++;
    }

    bool List::isLstEmpty() const {
        if (head == nullptr)
            return true;
        return false;
    }

    List::List(List& lst) : List() {

        *this = lst;
    }

    List& List::operator=(const List& lst) {

        if (this != &lst) {
            numberOfNeighbors = lst.numberOfNeighbors;

            Node* temp =  lst.head;
            while (temp) {
                this->AddToLst(temp->data);
                temp = temp->next;
            }
        }

        return *this;
    }

    void List::DisplayList()
    {
        Node* temp = this->head;

        if (this->isLstEmpty())
            cout << "Empty";
        else
        {
            while (temp)
            {
                cout << "dest: " << temp->data.dest << " weight: " << temp->data.weight;
                cout << "  |";
                temp = temp->next;
            }
        }
    }

    void List::removeFromList(Edge& dataToRemove) {

        Node* toRemove = findDataInList(dataToRemove);
        toRemove->prev = toRemove->next;
    }

    Node* List::findDataInList(Edge& dataToFind) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.source == dataToFind.source && temp->data.dest == dataToFind.dest) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void List::removeFromHead() {
        if (head == nullptr)
            return;
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            
            numberOfNeighbors = 0;

            return;
        }

        Node* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
        numberOfNeighbors--;
      
    }

}
